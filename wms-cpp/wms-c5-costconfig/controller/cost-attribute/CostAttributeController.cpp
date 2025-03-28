/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/22 19:11:00

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
#define _IP_ "192.168.110.141"

#include "stdafx.h"
#include "CostAttributeController.h"
#include "./service/cost-attribute/CostAttributeService.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
#include "../ApiDeclarativeServicesHelper.h"
#include <iostream>
#include <string>
#include "SimpleDateTimeFormat.h"
/*
	删除客户计费属性
*/
StringJsonVO::Wrapper CostAttributeController::execDeleteCostAttribute(const List<String>& ids) {
	//定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验
	if (!ids) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service    
	// 删除操作
	CostAttributeService service;
	int count = 0;
	for (int i = 0; i < ids->size(); i++) {
		if (service.DeleteCostAttribute(ids[i])) {
			count++;
		}
		else
		{
			jvo->fail(ids[i]);
			break;
		}
	}
	if (count == ids->size()) {
		jvo->success("delete success");
	}


	// 响应结果
	return jvo;

}

/*
	导入客户计费属性
*/
//StringJsonVO::Wrapper CostAttributeController::execImportCostAttribute(shared_ptr<IncomingRequest> request) {
//	// 1 初始化
//	API_MULTIPART_INIT(container, reader);
//
//	// 2 配置读取器
//	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
//
//	// 3 读取数据
//	request->transferBody(&reader);	// 1 初始化
//	/*OATPP_LOGD("Multipart", "parts_count=%d", container->count());
//	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_code", pronut_code);
//	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_name", pronut_name);*/
//	// 4 解析数据
//	/* 获取文件数据 */
//	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
//	if (file)
//	{
//		/* 打印文件名称 */
//		string filename = partfile->getFilename().getValue("");
//		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
//		// 测试将文件保存到磁盘上
//		string fullPath = "public/static/file/" + filename;
//		file.saveToFile(fullPath.c_str());
//		/* 测试上传到FastDFS */
//		string url = _IP_;
//		FastDfsClient dfs(url);
//		// 获取文件后缀名
//		string suffix = "";
//		size_t pos = filename.rfind(".");
//		if (pos != string::npos)
//		{
//			suffix = filename.substr(pos + 1);
//		}
//
//		// 上传文件
//		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
//		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
//
//		// 初始化xInt
//		xlnt::workbook wb;
//		std::string fullp = string("public/static/file/");
//		dfs.downloadFile(downloadUrl, &fullp);
//		wb.load(fullPath);
//		xlnt::worksheet ws = wb.active_sheet();
//		int j = 0;
//
//		// 初始化一个vector用来存储文件的dto数据
//		vector<CostAttributeDTO::Wrapper> dataDTOs;
//		for (const auto& row : ws.rows()) {
//			if (j == 0)
//			{
//				j++;
//				continue;
//			}
//			vector<string> rowData;
//			for (const auto& cell : row)
//			{
//				rowData.push_back(cell.to_string());
//			}
//			auto dto = CostAttributeDTO::createShared();
//			dto->addExcel(rowData);
//			dataDTOs.push_back(dto);
//		}
//		// 把数据传入service导入数据库
//		CostAttributeService service;
//		CostAttributesDTO::Wrapper id = service.ImportCostAttribute(dataDTOs);
//	}
//	// 5 响应结果
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("OK");
//	return jvo;
//
//}
//
/*
	导入客户计费属性
*/
StringJsonVO::Wrapper CostAttributeController::execImportCostAttribute(shared_ptr<IncomingRequest> request) {
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
		/*string fullpath = "public/static/file/" + filename;
		file.saveToFile(fullpath.c_str());*/

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
	vector<vector<string>> matrix = excel.readIntoVector(data, file->size(), ZH_WORDS_GETTER("excel.name.import"));
	//将每行数据组装成DTO传输给service层插入
	int lines = matrix.size();
	for (int i = 1; i < lines; ++i)
	{
		auto dto = ImportCostAttributeDTO::createShared();
		dto->addExcel(matrix[i][0], matrix[i][1]);
		//从负载读取信息
		CostAttributeService service;
		uint64_t id = service.ImportCostAttribute(dto);
		if (id <= 0)
		{
			jvo->fail("fail");
			return jvo;
		}
	}
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostAttributeController::execExportCostAttribute()
{
	ExportCostAttributeQuery::Wrapper query;
	CostAttributeService service;
	list<CostAttributeDO> result = service.ExportCostAttribute();
	std::vector<std::vector<std::string>> data;
	stringstream ss;
	std::vector<std::string> r1;
	ss.clear();
	std::string info = ZH_WORDS_GETTER("cost.attribute.code");
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	ss.clear();
	info = ZH_WORDS_GETTER("cost.attribute.name");
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	data.push_back(r1);
	for (auto r : result)
	{
		std::vector<std::string> row;
		string n = r.getKeHuShuXingCode();
		string m = r.getKeHuShuXingName();
		ss.clear();
		ss << n;
		row.push_back(ss.str());
		ss.str("");
		ss.clear();
		ss << m;
		row.push_back(ss.str());
		ss.str("");
		data.push_back(row);
	}
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.name.export");


	// 将Excel数据导出到String中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(sheetName, data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());


	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

		// 创建响应头
		auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + fileName);

	// 影响成功结果
	return response;
}

///*
//	导出客户计费属性
//*/
//shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostAttributeController::execExportCostAttribute() {
//	// 定义一个service
//	// 导出操作
//	CostAttributeService service;
//	auto res = CostPageDTO::createShared();
//	res = service.ExportCostAttribute();
//
//	// 判断返回服务层结果是否为空
//	if (res->pages){
//		return createResponse(Status::CODE_500, "Failed to retrieve data");
//	}
//	// 初始化二维数组 存储数据客户属性数据 用于生成excel文件
//	std::vector<std::vector<std::string>> data;
//	std::vector<std::string> header;
//	// 设置响应头
//	header.push_back(ZH_WORDS_GETTER("excel.code"));
//	header.push_back(ZH_WORDS_GETTER("excel.Name"));
//	// 插入响应头
//	data.push_back(header);
//	// 插入数据到二维数组
//	for (auto it : *res->rows) {
//		std::vector<std::string> row;
//		row.push_back(it->id);
//		row.push_back(it->create_name);
//		row.push_back(it->create_by);
//		row.push_back(it->create_date);
//		row.push_back(it->update_name);
//		row.push_back(it->update_by);
//		row.push_back(it->update_date);
//		row.push_back(it->sys_org_code);
//		row.push_back(it->sys_company_code);
//		row.push_back(it->kehushuxing_code);
//		row.push_back(it->kehushuxing_name);
//		data.push_back(row);
//	}
//
//	// excel文件名
//	std::string sheetName = ZH_WORDS_GETTER("excel.name.export");
//	// 声明excel文件处理组件
//	ExcelComponent excel;
//	// 生成excel buffer 
//	auto buff = excel.writeVectorToBuff(sheetName, data);
//	if (buff.empty()) {
//		return createResponse(Status::CODE_500, "Failed to generate Excel file");
//	}
//
//	auto fstring = String(reinterpret_cast<const char*>(buff.data()), buff.size());
//	const String& filename = "ExportedCostAttribute";
//	auto response = createResponse(Status::CODE_200, fstring);
//	response->putHeader("Content-Disposition", "attachment; filename=" + (filename ? filename : "default.xlsx"));
//	response->putHeader("Content-Type", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
//
//	return response;
//}

