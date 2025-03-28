/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/2/27 22:17

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CostDetailController.h"
#include "../../service/cost-detail/CostDetailService.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

//通过读取List<String>里的id,修改对应表现的收款属性
StringJsonVO::Wrapper CostDetailController::execChargeCost(List<String> ids)
{
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数校验
	for (const auto& id : *ids)
	{
		//检验是否有传入字符串为空
		if (*id == "")
		{
			jvo->init(String("error: parameter::id cannot be empty!"), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//定义service
	CostDetailService service;
	int success = 1;
	String wrong_ids = "";
	for (const auto& id : *ids)//成功则状态success,返回最后处理的一个id;失败则fail,返回所有失败的id
	{
		if (service.charge(id))//成功修改该id对应的数据
		{
			jvo->data=id;//内部实现为设置jvo->setStatus和jvo->data=id
		}
		else//出错
		{
			success = 0;
			wrong_ids = wrong_ids + id + ",";
		}
	}
	if (success == 1)//没有出错
	{
		jvo->success(jvo->data);
	}
	else
	{
		jvo->fail(wrong_ids);
	}
	return jvo;
}

StringJsonVO::Wrapper CostDetailController::execDischargeCost(List<String> ids)
{
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数校验
	for (const auto& id : *ids)
	{
		//检验是否有传入字符串为空
		if (*id== "")
		{
			jvo->init(String("error: parameter::id cannot be empty!"), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	//定义service
	CostDetailService service;
	int success = 1;
	String wrong_ids = "";
	for (const auto& id : *ids)//成功则状态success,返回最后处理的一个id;失败则fail,返回所有失败的id
	{
		if (service.discharge(id))//成功修改该id对应的数据
		{
			jvo->data = id;//内部实现为设置jvo->setStatus和jvo->data=id
		}
		else//出错
		{
			success = 0;
			wrong_ids = wrong_ids + id + ",";
		}
	}
	if (success == 1)//没有出错
	{
		jvo->success(jvo->data);
	}
	else
	{
		jvo->fail(wrong_ids);
	}
	return jvo;
}
StringJsonVO::Wrapper CostDetailController::execUploadCostDetail(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 1 初始化容器和读取器
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);//可上传多个参数,但是后续只解析"file"参数

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* 测试将文件保存到磁盘上面 */
		//string fullPath = "public/static/file/" + filename;
		//file.saveToFile(fullPath.c_str());

		if (false)//是否上传到FastDFS,可选
		{
			/* 测试上传到FastDFS */
			ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
			// 获取文件后缀名
			string suffix = "";
			size_t pos = filename.rfind(".");
			if (pos != string::npos)
			{
				suffix = filename.substr(pos + 1);
			}
			// 上传文件
			string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
			downloadUrl = urlPrefix + downloadUrl;
			OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		}
	}
	// 5 响应结果:文件上传到String的file,要将file解析并传入数据库
	auto jvo = StringJsonVO::createShared();
	ExcelComponent excel;
	const char* data = file->data();
	vector<vector<string>> matrix=excel.readIntoVector(data, file->size(), ZH_WORDS_GETTER("cost-detail.upload.field.sheetname"));
	//将每行数据组装成DTO传输给service层插入,前3行为标头
	int lines = matrix.size();
	for (int i = 3; i < lines; ++i)
	{
		CostExportDTO dto;
		dto.creator = matrix[i][0];
		dto.createdate = matrix[i][1];
		dto.updater= matrix[i][2];
		dto.updatedate= matrix[i][3];
		dto.client= matrix[i][4];
		dto.clientname= matrix[i][5];
		dto.cost= matrix[i][6];
		dto.costname= matrix[i][7];
		dto.costdate= matrix[i][8];
		dto.oldprice= matrix[i][9];
		dto.notax = matrix[i][10];
		dto.tax = matrix[i][11];
		dto.taxprice = matrix[i][12];
		dto.source = matrix[i][13];
		dto.remark = matrix[i][14];
		dto.state = matrix[i][15];
		dto.status = matrix[i][16];
		dto.count = matrix[i][17];
		dto.unit = matrix[i][18];
		//从负载读取信息
		dto.create_by = payload.getRealname();
		dto.org_code = payload.getOrgcode();
		dto.company_code = payload.getCompanycode();
		CostDetailService service;
		uint64_t id=service.addData(&dto);
		if (id <= 0)
		{
			jvo->fail("fail");
			return jvo;
		}
	}
	jvo->success("OK");
	return jvo;
}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostDetailController::execDownloadCostDetail(const List<String>& ids)
{
	//调用service层导出全部数据
	CostDetailService service;
	auto result=service.exportAll(ids);
	//给查询结果加上表头
	vector<string> title = { 
		ZH_WORDS_GETTER("cost-detail.download.field.creator-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.create-date"),
		ZH_WORDS_GETTER("cost-detail.download.field.updater-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.update-date"),
		ZH_WORDS_GETTER("cost-detail.download.field.clinet"),
		ZH_WORDS_GETTER("cost-detail.download.field.client-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.cost"),
		ZH_WORDS_GETTER("cost-detail.download.field.cost-name"),
		ZH_WORDS_GETTER("cost-detail.download.field.cost-date"),
		ZH_WORDS_GETTER("cost-detail.download.field.old-price"),
		ZH_WORDS_GETTER("cost-detail.download.field.no-tax"),
		ZH_WORDS_GETTER("cost-detail.download.field.tax"),
		ZH_WORDS_GETTER("cost-detail.download.field.tax-cost"),
		ZH_WORDS_GETTER("cost-detail.download.field.source"),
		ZH_WORDS_GETTER("cost-detail.download.field.remark"),
		ZH_WORDS_GETTER("cost-detail.download.field.state"),
		ZH_WORDS_GETTER("cost-detail.download.field.status"),
		ZH_WORDS_GETTER("cost-detail.download.field.count"),
		ZH_WORDS_GETTER("cost-detail.download.field.unit") };
	result.insert(result.begin(),title);
	//导入excel
	ExcelComponent excel;
	//excel.writeVectorToFile("C:/Users/wcy/Desktop/save.xlsx", ZH_WORDS_GETTER("cost-detail.download.field.sheetname"), result);//保存到本地
	//返回给前端
	auto buff=excel.writeVectorToBuff(ZH_WORDS_GETTER("cost-detail.download.field.sheetname"), result);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to export data: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Data Not Found");
	}
	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);
	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + ZH_WORDS_GETTER("cost-detail.download.field.filename"));

	// 影响成功结果
	return response;
}