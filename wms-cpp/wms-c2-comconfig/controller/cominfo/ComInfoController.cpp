#include "stdafx.h"
#include "ComInfoController.h"
#include "domain/vo/cominfo/ComInfoVO.h"
#include <regex>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
StringJsonVO::Wrapper ComInfoController::execInputComInfo(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	
	// 4 解析数据
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	API_MULTIPART_PARSE_FILE_FIELD(container, "Sheet name", sheet_name);
	API_MULTIPART_PARSE_FILE_FIELD(container, "Number of sheet page", sheet_number);
	//cout << endl << endl << endl << endl << << sheet_name.getValue("").c_str() << endl << endl << endl << endl;
	//文件存在
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* 测试将文件保存到磁盘上面 */
		//string fullPath = "public/static/file/" + filename;
		//file.saveToFile(fullPath.c_str());

		/* 测试上传到FastDFS */
		//ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string filetype = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			filetype = filename.substr(pos + 1);
		}
		if (filetype != "xlsx")
		{
			auto jvo = StringJsonVO::createShared();
			jvo->fail("Type is not right.\nPlease try again.");
			ResultStatus rs("415 Unsupported Media Type", 415);
			jvo->setStatus(rs);
			std::cout << "Type is not right.\nPlease try again." << std::endl;
			return jvo;
		}
		// 上传文件
		//string downloadUrl = dfs.uploadFile(file->data(), file->size(), filetype);
		//downloadUrl = urlPrefix + downloadUrl;
		//OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());


		std::string page_ = "Page1";
		//读取.xlsx中的数据
		std::vector<std::vector<std::string>> excelData = ExcelComponent::readIntoVector(file->data(), file->size(), page_);
		//每页的数据
		int row_size = excelData.size() - 1;
		if (row_size <= 0)
		{
			auto jvo = StringJsonVO::createShared();
			jvo->fail("File is empty.\nPlease try again.");
			ResultStatus rs("204 No Content", 204);
			jvo->setStatus(rs);
			return jvo;
		}
		else
		{
			//输出上传的测试结果
			for (int i = 1; i < 10; ++i)
			{
				for (int j = 0; j < 15; ++j)
				{
					cout << excelData[i][j] << "  ";
				}
				cout << endl;
			}
		}
	}
	//文件不存在
	else
	{
		std::cout << "Path is not right!\nDon't find file!\nPlease try again." << std::endl;
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Path is not right.\nDon't find file.\nPlease try again.");
		ResultStatus rs("404 Not Found", 404);
		jvo->setStatus(rs);
		return jvo;
	}

	// 5 响应结果
	auto jvo = StringJsonVO::createShared();
	jvo->success("Import Data successfully.");
	ResultStatus rs("200 OK", 200);
	jvo->setStatus(rs);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ComInfoController::execOutputComInfo(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "Public/DownloadComInfo/" + URIUtil::urlDecode(filename.getValue(""));
	//表`ba_comp`对应结构
	std::vector<std::string> ba_comp = {
	ZH_WORDS_GETTER("comconfig.cominfo.id"),
	ZH_WORDS_GETTER("comconfig.cominfo.create_name"),
	ZH_WORDS_GETTER("comconfig.cominfo.create_by"),
	ZH_WORDS_GETTER("comconfig.cominfo.create_date"),
	ZH_WORDS_GETTER("comconfig.cominfo.update_name"),
	ZH_WORDS_GETTER("comconfig.cominfo.update_by"),
	ZH_WORDS_GETTER("comconfig.cominfo.update_date"),
	ZH_WORDS_GETTER("comconfig.cominfo.sys_org_code"),
	ZH_WORDS_GETTER("comconfig.cominfo.sys_company_code"),
	ZH_WORDS_GETTER("comconfig.cominfo.com_code"),
	ZH_WORDS_GETTER("comconfig.cominfo.com_zh_name"),
	ZH_WORDS_GETTER("comconfig.cominfo.com_zh_aname"),
	ZH_WORDS_GETTER("comconfig.cominfo.com_zh_addr"),
	ZH_WORDS_GETTER("comconfig.cominfo.com_en_name"),
	ZH_WORDS_GETTER("comconfig.cominfo.com_en_aname")
	};
	std::vector<std::string> ba_comp_en = {
		"id", "create_name", "create_by", "create_date", "update_name",
		"update_by", "update_date", "sys_org_code", "sys_company_code",
		"com_code", "com_zh_name", "com_zh_aname", "com_zh_addr",
		"com_en_name", "com_en_aname"
	};
	//导出数据到客户端
	/*
	int total_size;//由查询企业信息得到的条数
	int PageSize;//每页几条

	//创建一个excel表格
	ExcelComponent excel;
	std::string sheetName = "Page";

	for (int PageIndex = 0; PageIndex  < (total_size - 1) / PageSize; PageIndex++) //计算总页数
	{
		//构造每一条数据
		std::vector<std::vector<std::string>> data;
        data.push_back(ba_comp);
        data.push_back(ba_comp_en);

		// 生成当前页的数据
		for (int i = 0; i < PageSize; i++)
		{
			int recordIndex = PageIndex * PageSize + i;
			if (recordIndex >= total_size) break; // 避免越界

			// 实际应从数据库查询
			std::vector<std::string> row = {
			
			};
			data.push_back(row);
		}
		// 生成当前分页的数据到文件
		std::string currentSheetName = sheetNamePrefix + std::to_string(PageIndex + 1);
		excel.writeVectorToFile(fullPath, currentSheetName, data);
	}
	//构造每一条数据
	std::vector<std::vector<std::string>> data;
	data.push_back(ba_comp);
	data.push_back(ba_comp_en);
	for(int i=PageIndex*PageSize;i<total_size;++i)
	{
		int recordIndex = PageIndex * PageSize + i;

		// 实际应从数据库查询
		std::vector<std::string> row = {
			
		};
		data.push_back(row);
	}
	// 读取文件内容到 buffer 发送
	auto buff = excel.writeVectorToBuff(sheetName + std::to_string(++PageIndex), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	*/
	// 测试数据 此内容仅供测试
	// 导出zo_wms中内容需要待查询企业信息接口完成
	// 假设 total_size 和 PageSize 由查询企业信息接口完成获取
	int total_size = 200;  // 假设数据总数
	int PageSize = 100;      // 每页100条
	int PageIndex;

	ExcelComponent excel;
	std::string sheetName = "Page";

	for (PageIndex = 0; PageIndex < (total_size - 1) / PageSize; PageIndex++)
	{
		std::vector<std::vector<std::string>> data;
		data.push_back(ba_comp);
		data.push_back(ba_comp_en);

		// 生成当前页的数据
		for (int i = 0; i < PageSize; i++)
		{
			int recordIndex = PageIndex * PageSize + i;
			if (recordIndex >= total_size) break; // 避免越界

			// 这里用模拟数据，实际应从数据库查询
			std::vector<std::string> row = {
				std::to_string(recordIndex + 1), "user" + std::to_string(recordIndex),
				"creator" + std::to_string(recordIndex), "2024-03-01 10:00:00",
				"editor" + std::to_string(recordIndex), "editor_by" + std::to_string(recordIndex),
				"2024-03-02 11:00:00", "100" + std::to_string(recordIndex),
				"200" + std::to_string(recordIndex), "C00" + std::to_string(recordIndex),
				"Company" + std::to_string(recordIndex), "Alias" + std::to_string(recordIndex),
				"Address" + std::to_string(recordIndex), "Company_EN" + std::to_string(recordIndex),
				"Alias_EN" + std::to_string(recordIndex)
			};
			data.push_back(row);
		}

		// 生成当前分页的数据到文件
		std::string currentSheetName = sheetName + std::to_string(PageIndex + 1);
		excel.writeVectorToFile(fullPath, currentSheetName, data);
	}
	std::vector<std::vector<std::string>> data;
	data.push_back(ba_comp);
	data.push_back(ba_comp_en);
	// 生成当前页的数据
	for (int i = PageIndex*PageSize; i < total_size; i++)
	{

		// 这里用模拟数据，实际应从数据库查询
		std::vector<std::string> row = {
			std::to_string(i + 1), "user" + std::to_string(i),
			"creator" + std::to_string(i), "2024-03-01 10:00:00",
			"editor" + std::to_string(i), "editor_by" + std::to_string(i),
			"2024-03-02 11:00:00", "100" + std::to_string(i),
			"200" + std::to_string(i), "C00" + std::to_string(i),
			"Company" + std::to_string(i), "Alias" + std::to_string(i),
			"Address" + std::to_string(i), "Company_EN" + std::to_string(i),
			"Alias_EN" + std::to_string(i)
		};
		data.push_back(row);
	}
	// 读取文件内容到 buffer 发送
	auto buff = excel.writeVectorToBuff(sheetName + std::to_string(++PageIndex), data);
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


