#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "StatusFileController.h"
#include "domain/vo/enterprise-status/GetEnterpriseStatusVO.h"
#include <regex>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

// 递归替换所有 `from` 为 `to`
void replaceAll_file(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty() || from == to) return; // 避免死循环
	size_t startPos = 0;
	while ((startPos = str.find(from, startPos)) != std::string::npos) {
		str.replace(startPos, from.length(), to);
		startPos += to.length(); // 防止死循环
	}
}

// 处理路径字符串
std::string normalizePath_file(std::string path) {
	if (path.empty())return {};
	// 1. 移除引号
	replaceAll_file(path, "%22", "");
	replaceAll_file(path, "%27", "");

	// 2. 替换 URL 编码
	replaceAll_file(path, "%3A", ":"); // :冒号
	replaceAll_file(path, "%5C", "\\");// \斜线
	replaceAll_file(path, "%2F", "\\");// /斜线

	// 3. 处理可能出现的多个 `\` 叠加的情况，使用正则确保 `\` 统一为 `\\`
	path = std::regex_replace(path, std::regex(R"(\\+)"), R"(\)"); // 将多个 `\` 统一为 `\\`

	return path;
}

StringJsonVO::Wrapper StatusFileController::execUploadMore(const String& filepath)
{
	
	std::string path = filepath.getValue("");
	//传入的地址需要替换 详细替换过程参考normalizePath()函数
	std::string normalizedPath = normalizePath_file(path);
	cout << normalizedPath << endl;
	size_t pos = normalizedPath.rfind(".");
	std::string filetype = normalizedPath.substr(pos + 1);
	cout << 1 << endl;
	if (filetype != "xlsx")
	{
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Type is not right.\nPlease try again.");
		ResultStatus rs("415 Unsupported Media Type", 415);
		jvo->setStatus(rs);
		std::cout << "Type is not right.\nPlease try again." << std::endl;
		return jvo;
	}
	FastDfsClient dfs("192.168.182.128");//请在整合的时候替换为对应的fastdfs服务器IP
	std::string result = dfs.uploadFile(normalizedPath);
	std::string downloadPath;

	//文件存在且成功上传
	if (result != "") {
		//文件路径
		std::string dir = "http://192.168.182.128:8888/";//请在整合的时候替换为对应的fastdfs服务器IP
		std::string fullPath = dfs.downloadFile(result, &dir);

		//dfs.deleteFile(result);
		downloadPath = dir + result;
		std::cout << "Upload successfully." << std::endl << "Path is:" << downloadPath << std::endl;
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

	//读取.xlsx中的数据
	std::vector<std::vector<std::string>> excelData = ExcelComponent::readIntoVector(downloadPath, "Sheet1");
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

	auto jvo = StringJsonVO::createShared();
	jvo->success("Import Data successfully.");
	ResultStatus rs("200 OK", 200);
	jvo->setStatus(rs);
	return jvo;




}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> StatusFileController::execDownloadFile(const String& filename)
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
	ZH_WORDS_GETTER("enterprise_level_code"),
	ZH_WORDS_GETTER("enterprise_field_status"),
	ZH_WORDS_GETTER("enterprise_field_stop"),
	};
	std::vector<std::string> ba_comp_en = {
		"id", "create_name", "create_by", "create_date", "update_name",
		"update_by", "update_date", "sys_org_code", "sys_company_code",
		"com_sta_code", "com_sta_name", "com_sta_del"
	};

	ExcelComponent excel;
	std::string sheetName = "Page";

	int total_size = 200;  // 假设数据总数
	int PageSize = 100;      // 每页100条
	int PageIndex;


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
	for (int i = PageIndex * PageSize; i < total_size; i++)
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
