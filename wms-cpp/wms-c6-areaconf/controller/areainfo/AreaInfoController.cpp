#include "stdafx.h"
#include "AreaInfoController.h"
#include "service/areainfo/AreaInfoService.h"
#include "ExcelComponent.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> AreaInfoController::execDownloadExcel()
{

	AreaInfoService service;
	auto vec = service.selectAll();

	// 构建文件全路径
	std::string fullPath = "./file/areainfo.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("AreaInfo.info"), vec);

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
	response->putHeader("Content-Disposition", "attachment; filename=areainfo.xlsx");
	
	// 影响成功结果
	return response;
}

StringJsonVO::Wrapper AreaInfoController::execUploadExcel(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// 构建文件全路径
		std::string fullPath = "./file/areainfo.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("AreaInfo.info"));
		AreaInfoService service;
		service.upload(vec, payload);
	}
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

StringJsonVO::Wrapper AreaInfoController::execModify(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(String("-1"), RS_PARAMS_INVALID);
		return jvo;
	}
	AreaInfoService service;
	if (service.modifyData(dto, payload))
	{
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
}

StringJsonVO::Wrapper AreaInfoController::execDelete(const String& dto)
{
	auto jvo = StringJsonVO::createShared();
	AreaInfoService service;
	if (service.deleteData(dto->data()))
	{
		jvo->success(dto);
	}
	else
	{
		jvo->fail(dto);
	}
	return jvo;
}

AreaNameTreeJsonVO::Wrapper AreaInfoController::execNameTreeAreaInfo()
{
	auto jvo = AreaNameTreeJsonVO::createShared();

	AreaInfoService service;
	for (auto node : service.nameTree())
	{
		jvo->data->push_back(AreaNameTreeDTO::Wrapper(dynamic_pointer_cast<AreaNameTreeDTO>(node), AreaNameTreeDTO::Wrapper::Class::getType()));
	}

	return jvo;
}

AreaInfoPageJsonVO::Wrapper AreaInfoController::execAreaInfoList(const AreaInfoQuery::Wrapper& query)
{
	auto jvo = AreaInfoPageJsonVO::createShared();
	AreaInfoService service;
	auto list = service.List(query);
	jvo->success(list);
	return jvo;
}

StringJsonVO::Wrapper AreaInfoController::execAddAreaInfo(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	AreaInfoService service;
	if (service.addData(dto, payload))
	{
		jvo->success("OK");
	}
	else {
		jvo->fail("NO");
	}
	return jvo;
}