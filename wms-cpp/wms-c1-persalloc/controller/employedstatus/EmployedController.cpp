#include "stdafx.h"
#include "EmployedController.h"
#include "../../service/employedstatus/EmployedService.h"
#include <iostream>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"
#include <filesystem> 
// 不手动typedef的话不识别，不知道为什么
typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
//#include "SimpleDateTimeFormat.h"

Uint64JsonVO::Wrapper EmployedController::execRemoveByCode(const EmployedBatchRemoveDTO::Wrapper& dto_list)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	auto row = dto_list->rows;

	for (auto iter = row->begin(); iter != row->end(); iter++) {
		auto dto = *iter;

		// 参数校验
		// 非空校验
		if (!dto->code)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 有效值校验
		if (dto->code->empty())
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

		// 定义一个Service
		EmployedService service;
		// 执行数据删除
		auto res = service.removeData(dto);
		if (res) {
			jvo->success(res);
		}
		else {
			jvo->fail(res);
		}
	}
	// 响应结果
	return jvo;
}

std::shared_ptr<OutgoingResponse> EmployedController::execDownloadFile()
{
	string filename = "ba_pos_sta.xlsx";
	EmployedService service;
	string loaclpath = "public/static/";
	bool success = service.exportAllData(loaclpath);

	// 构建文件全路径
	std::string fullPath = loaclpath + filename;

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring || !success)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);

	// 影响成功结果
	return response;
}

StringJsonVO::Wrapper EmployedController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	namespace fs = std::filesystem;
	// 响应结果
	auto jvo = StringJsonVO::createShared();

	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 获取文件数据 */
	string fullPath = "";
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (!file) {
		jvo->fail("fail");
		return jvo;
	}

	// 文件名称
	string filename = partfile->getFilename().getValue("");

	// 将文件保存到磁盘
	fullPath = "public/static/file/" + filename;
	fs::path dir = fs::path("public/static/file/");
	if (!fs::exists(dir)) fs::create_directories(dir);				// 递归创建目录
	file.saveToFile(fullPath.c_str());								// 保存到指定目录

	ExcelComponent excel;
	xlnt::workbook wb;
	// 获取所有工作表名称
	const std::vector<std::string> sheetNames = wb.sheet_titles(); // 自动获取页签名,但是要加载两遍文件
	// auto res = excel.readIntoVector(fullPath, ZH_WORDS_GETTER("excel.sheet.s1"));

	auto res = excel.readIntoVector(fullPath, sheetNames[0]);
	if (res.size() < 1) {
		jvo->fail("fail");
		return jvo;
	}

	EmployedService service;
	bool success = service.importAllData(res, payload);

	if (success)
		jvo->success("success");
	else jvo->fail("fail");
	return jvo;
}
