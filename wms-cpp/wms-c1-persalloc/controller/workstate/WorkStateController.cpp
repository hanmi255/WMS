// wangye 2025/2/24
#include "stdafx.h"
#include <iostream>
#include "WorkStateController.h"
#include "../../service/workstate/WorkStateService.h"
#include "../ApiDeclarativeServicesHelper.h"

#define WORKSTATE_EXCEL_FN "./public/excel/ba-work-state.xlsx"
#define WORKSTATE_EXCEL_SN ZH_WORDS_GETTER("excel.sheet.s1")

// 实现上传一个工作状态文件接口执行函数
StringJsonVO::Wrapper WorkStateController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 初始化读取器
	API_MULTIPART_INIT(container, reader);
	// 配置读取器
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	// 读取数据
	request->transferBody(&reader);
	// 解析数据
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	// 非空校验
	if (!file)
	{
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Not Found File");
		return jvo;
	}
	
	ExcelComponent excel;
	auto data = excel.readIntoVector(file->data(), file->size(), ZH_WORDS_GETTER("wsf.excel.summary"));

	WorkStateService service;
	bool res = service.uploadData(data,payload);
	auto jvo = StringJsonVO::createShared();
	if (res) {
		jvo->success("OK");
		return jvo;
	}
	else {
		jvo->fail("error");
		return jvo;
	}
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> WorkStateController::execDownloadExcel(const String& filename)
{
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));
	WorkStateService service;

	std::vector<std::vector<std::string>> data;
	std::vector<std::vector<std::string>> DB;
	DB = service.getVectorData();
	std::string info1 = ZH_WORDS_GETTER("goods.download.info1");
	std::string info2 = ZH_WORDS_GETTER("goods.download.info2");

	std::vector<std::string> infoVec{ info1,info2};
	stringstream ss;
	// 名称
	data.push_back(infoVec);
	for (int i = 0; i < DB.size(); i++)
	{
		std::vector<std::string> row;
		for (int j = 0; j < 2; j++)
		{
			ss.clear();
			ss << DB[i][j];
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}


	std::string fileName = WORKSTATE_EXCEL_FN;
	std::string sheetName = WORKSTATE_EXCEL_SN;


	// 将Excel数据导出到String中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("file.field.filename"), data);
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






// 删除工作状态接口执行函数
Uint64JsonVO::Wrapper WorkStateController::execRemoveWorkState(const String& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (atoi(id->c_str()) <= 0) //具体是想让string转换成int类型，让后进行参数校验
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WorkStateService service;
	auto ans = service.removeData(string(id->c_str()));
	// 执行数据删除
	if (ans) {
		jvo->success(ans);
	}
	else
	{
		jvo->fail(ans);
	}
	// 响应结果
	return jvo;
}