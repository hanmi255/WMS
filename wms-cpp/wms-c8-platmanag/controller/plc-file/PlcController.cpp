#include "stdafx.h"
#include "PlcController.h"
#include "../../service/plc-file/PlcService.h"
#include "../ApiDeclarativeServicesHelper.h"

PlcPageJsonVO::Wrapper PlcController::execQueryAll(const PlcFileQuery::Wrapper& query)
{
	PlcService service;
	auto result = service.listAll(query);
	auto jvo = PlcPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
PlcJsonVO::Wrapper PlcController::execQueryById(const String& id)
{
	// 定义返回数据对象
	auto jvo = PlcJsonVO::createShared();
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	//if (id.getValue({}) <= 0)
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// 定义一个Service
	PlcService service;
	// 执行数据新增
	auto res = service.getById(id);
	jvo->success(res);

	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper PlcController::execAddPlc(const PlcAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	/*if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// 有效值校验
	/*if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/
	// 定义一个Service
	PlcService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload.getUsername(), payload.getRealname(), payload.getOrgcode(), payload.getCompanycode());
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
Uint64JsonVO::Wrapper PlcController::execModifyPlc(const PlcdetailDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 定义一个Service
	PlcService service;
	// 执行数据修改
	uint64_t id = service.updateData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	return jvo;
}
Uint64JsonVO::Wrapper PlcController::execRemovePlc(const String& id)
{
	auto jvo = Uint64JsonVO::createShared();
	PlcService service;
	uint64_t Idd = service.removeData(id);
	if (Idd > 0) {
		jvo->success(UInt64(Idd));
	}
	else
	{
		jvo->fail(UInt64(Idd));
	}
	return jvo;
}

StringJsonVO::Wrapper PlcController::execUploadFiles(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);
	// 2 配置读取器
	//API_MULTIPART_CONFIG_FILE(reader, "file0", "public/static/file/test0.png");
	//API_MULTIPART_CONFIG_FILE(reader, "file1", "public/static/file/test1.png");
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	// 4 解析数据
	/* TODO: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/* 获取文件部分 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file0", file0);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file1", file1);
	/* 断言文件是否获取到 */
	OATPP_ASSERT_HTTP(partfile0, Status::CODE_400, "file0 is null");
	OATPP_ASSERT_HTTP(partfile1, Status::CODE_400, "file1 is null");
	/* 打印文件保存路径 */
	OATPP_LOGD("Multipart", "file0 save path: %s", partfile0->getPayload()->getLocation()->c_str());
	OATPP_LOGD("Multipart", "file1 save path: %s", partfile1->getPayload()->getLocation()->c_str());
	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PlcController::execDownloadFile(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));
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
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}