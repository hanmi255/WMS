/*
/*@File Name         : OperStepController.cpp                                                     
/*@Author            : 智商局局长
/*@Description       :
*/
#include "stdafx.h"
#include "ServerInfo.h"
#include "SimpleDateTimeFormat.h"
#include "OperStepController.h"
#include "ExcelComponent.h"
#include "service/oper_step/OperStepService.h"

StringJsonVO::Wrapper OperStepController::execModifyOperStep(const OperStepDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	OperStepService service;
	if (service.modifyData(dto, payload))
	{
		jvo->success("OK");
	}
	else {
		jvo->fail("NO");
	}
	return jvo;
}

StringJsonVO::Wrapper OperStepController::execDeleteOperStep(const OperStepDeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	OperStepService service;
	if (service.deleteData(dto))
	{
		jvo->success("OK");
	}
	else
	{
		jvo->fail("NO");
	}
	return jvo;
}

StringJsonVO::Wrapper OperStepController::execUploadExcel(const std::shared_ptr<IncomingRequest>& request, const PayloadDTO& payload)
{
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		string fullPath = "./public/static/file/OperStep.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<std::string>> rfile = ExcelComponent::readIntoVector(fullPath, "OperStep");
		OperStepService service;
		service.importData(rfile, payload);
		std::vector<std::vector<std::string>> vec;
		vec = service.selectAll();
		ExcelComponent exc;
		exc.writeVectorToFile(fullPath, "OperStep", vec);
	}

	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> OperStepController::execExportExcel()
{
	// 构建文件全路径
	std::string fullPath = "./public/static/file/OperStep.xlsx";

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
	response->putHeader("Content-Disposition", "attachment; filename=OperStep.xlsx");

	// 影响成功结果
	return response;
}



