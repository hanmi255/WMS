#include "stdafx.h"
#include "EduCodeController.h"
#include "../../service/EducationService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include <filesystem>  // C++17 的文件系统库
#include <fstream>     // 文件操作
#include <string>      // 字符串操作
#include <iostream>    // 输出日志

#include "Macros.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper EduCodeController::execDelEducate(const String& code)
{
	auto jvo = StringJsonVO::createShared();
	
	if (!code || code->empty())
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DelRoleService service;
	// 执行数据删除

	if (service.removeData(code)) {
		jvo->success(code);
	}
	else
	{
		jvo->fail(code);
	}
	// 响应结果
	return jvo;
}

EduPageJsonVO::Wrapper EduCodeController::execQueryEdu(const EduQuery::Wrapper& query)
{
	EduService service;
	auto result = service.listAll(query);
	auto jvo = EduPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper EduCodeController::execAddEdu(const EduAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 有效值校验
	if (dto->educode->empty() || dto->eduname->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EduService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;

}

StringJsonVO::Wrapper EduCodeController::execModifyEducode(const EducationalDTO::Wrapper& educationalDTO, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!educationalDTO->code || !educationalDTO->name)
	{
		jvo->fail(" ");
		return jvo;
	}
	// 定义一个Service
	DelRoleService service;
	// 执行数据修改
	if (service.updateData(educationalDTO, payload)) {
		jvo->success(educationalDTO->code);
	}
	else
	{
		jvo->fail(educationalDTO->code);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper EduCodeController::importEduCode(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 从文件中读取
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);

	if (file)
	{
		// 构建文件全路径
		std::string fullPath = "./file/edu.xlsx";
		file.saveToFile(fullPath.c_str());
		std::vector<std::vector<string>> vec = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("education.educode"));
		EduService service;
		service.saveData(vec, payload);
	}

	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;

}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> EduCodeController::execexportEducode()
{
	EduService service;
	auto vec = service.listAll();

	// 构建文件全路径
	std::string fullPath = "./file/edu.xlsx";

	ExcelComponent excel;
	excel.loadFile(fullPath);
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("education.field.educode"), vec);

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
	response->putHeader("Content-Disposition", "attachment; filename=edu.xlsx");

	// 影响成功结果
	return response;
}