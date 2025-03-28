#include "stdafx.h"
#include "CityTypeController.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "service/citytype/CityTypeService.h"
#ifdef _WIN32
#include <direct.h>  // Windows 的 _mkdir
#define mkdir(path, mode) _mkdir(path)  // 适配 Windows
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

StringJsonVO::Wrapper CityTypeController::execModifyCityTypeCode(const CityTypeDTO::Wrapper& dto, const PayloadDTO& payload) {
	CityTypeService service;
	auto jvo = StringJsonVO::createShared();
	if (service.Udp(dto, payload))
	{
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail("-1");
	}
    return jvo;
}

CityTypeNameListJsonVO::Wrapper CityTypeController::execGetCityTypeNamesList() {
	CityTypeService service;
	auto ans = service.nameList();
	auto jvo = CityTypeNameListJsonVO::createShared();
	jvo->success(ans);
	return jvo;
}

CityTypePageJsonVO::Wrapper CityTypeController::execGetCityTypeList(const CityTypeQuery::Wrapper& query) {
	CityTypeService service;
	auto ans = service.listAll(query);
	auto jvo = CityTypePageJsonVO::createShared();
	jvo->success(ans);
    return jvo;
}

StringJsonVO::Wrapper CityTypeController::execCreateCityType(const CitytypeBaseDTO::Wrapper& dto, const PayloadDTO& payload) {
	CityTypeService service;
	auto jvo = StringJsonVO::createShared();
	std::string id = service.Add(dto, payload);
	if (id != "")
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail("-1");
	}
    return jvo;
}

StringJsonVO::Wrapper CityTypeController::execCitytypeDel(const String& id)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!id || id->empty())
	{
		jvo->init("-1", RS_PARAMS_INVALID);  
		return jvo;
	}
	// 定义一个Service
	CityTypeService service;
	// 执行数据删除
	if (service.removeData(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper CityTypeController::execCitytypeUpload(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// 构建文件全路径
		std::string fullPath = "./file/citytype.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("citytype.type"));
		CityTypeService service;
		service.import(vec, payload);
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CityTypeController::execCitytypeDownload()
{
	CityTypeService service;
	auto vec = service.listAll();

	// 构建文件全路径
	std::string fullPath = "./file/citytype.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("citytype.type"), vec);

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=citytype.xlsx");

	// 影响成功结果
	return response;
}