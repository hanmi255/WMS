/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/05/17 11:37:57

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
#include "CostWayController.h"
#include "../../service/cost-way/CostwayService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include <iostream>
#include <string>
#include <filesystem>
#include "ExcelComponent.h"
// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
namespace fs = std::filesystem;

//StringJsonVO::Wrapper DeleteController::execwaydelete(const String& id)
//{
//	// 定义返回数据对象
//	auto jvo = StringJsonVO::createShared();
//	if (id =="")
//	{
//		jvo->init(String(""), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	CostwayService service;
//	// 执行数据删除
//	if (service.removeDataById(id.getValue(""))) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// 响应结果
//	return jvo;
//}

StringJsonVO::Wrapper DeleteController::execDeleteCostway(const oatpp::List<String>& ids)
{
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
	CostwayService service;
	int success = 1;
	String wrong_ids = "";
	for (const auto& id : *ids)//成功则状态success,返回最后处理的一个id;失败则fail,返回所有失败的id
	{
		if (service.removeDataById(id))//成功修改该id对应的数据
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


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadExcelController::execDownloadFile(const String& filename)
{
	DeleteQuery::Wrapper query;
	CostwayService service;
	list<CostwayDO> result = service.listAll();
	std::vector<std::vector<std::string>> data;
	stringstream ss;
	std::vector<std::string> r1;
	ss.clear();
	std::string info = ZH_WORDS_GETTER("pronut_code");
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	ss.clear();
	info = ZH_WORDS_GETTER("pronut_name");
	cout << info << endl;
	ss << info;
	r1.push_back(ss.str());
	ss.str("");
	data.push_back(r1);
	for(auto r:result)
	{
		std::vector<std::string> row;
		string n = r.getPronut_code();
		string m = r.getPronut_name();
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
	cout << 1 << endl;
	std::string fileName = "./public/excel/1.xlsx";
	std::string sheetName= ZH_WORDS_GETTER("cost-way.excel");
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
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}

StringJsonVO::Wrapper UploadExcelController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);	// 1 初始化
	/*OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_code", pronut_code);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "pronut_name", pronut_name);*/
	// 4 解析数据
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		// 测试将文件保存到磁盘上
		string fullPath = "public/static/file/" + filename;
		file.saveToFile(fullPath.c_str());
		cout << fullPath << endl;;
		/* 测试上传到FastDFS */
	    string urll = "121.43.101.169";
		cout << 1 << endl;
		FastDfsClient dfs(urll);
		cout << 2 << endl;
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
	
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		cout << downloadUrl << endl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		xlnt::workbook wb;
		std::string fullp = string("public/static/file/");
		dfs.downloadFile(downloadUrl, &fullp);
		wb.load(fullPath);
		xlnt::worksheet ws = wb.active_sheet();
		int j = 0;
		for (const auto& row : ws.rows()) {
			if (j == 0)
			{
				j++;
				continue;
			}
			int i = 0;
			string n;
			string m;
			for (const auto& cell : row) 
			{
			    std::cout << i << endl;
				if(i==0)
				{
					n = cell.to_string();
					i++;
				}
				else 
				{
					m = cell.to_string();
					i++;
				}
			}
			auto dto = UploadExcelDTO::createShared();
			dto->addExcel(n, m);
			CostwayService service;
			uint64_t id = service.saveData(dto);
		}
	}
	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

