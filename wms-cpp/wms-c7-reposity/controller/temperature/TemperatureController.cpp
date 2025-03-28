#include"stdafx.h"
#include "TemperatureController.h"
#include "../../service/temperature/TemperatureService.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include <iterator>
#include <fstream>
#include<iostream>

Uint64JsonVO::Wrapper TemperatureController::execModifyTemperature(const TemperatureModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 参数校验
	string stdId = dto->id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (!dto->id || idValue < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	TemperatureDetailDTO::Wrapper ddto;
	ddto->id = dto->id;
	ddto->deg_type_code = dto->deg_type_code;
	ddto->deg_type_name = dto->deg_type_name;
	ddto->update_name = payload.getUsername();
	ddto->update_by = payload.getRealname();

	//时间使用SimpleDateTimeFormat
	ddto->update_date = SimpleDateTimeFormat::formatWithMilli();
	ddto->sys_org_code = payload.getOrgcode();
	ddto->sys_company_code = payload.getCompanycode();


	//定义service
	TemperatureService service;

	// 执行数据修改并返回相应结果
	if (service.updateData(ddto)) {
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// 响应结果

	return jvo;


}

Uint64JsonVO::Wrapper TemperatureController::execRemoveTemperature(const String& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	if (!id || id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TemperatureService service;
	string stdId = id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (service.removeData(id)) {
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper TemperatureController::execUploadExcel(const std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);

	// 打印上传总部分数 
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* 获取表单数据 */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, ZH_WORDS_GETTER("dictionary.order.id.summary"), id);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, ZH_WORDS_GETTER("dictionary.order.code.summary"), code);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, ZH_WORDS_GETTER("dictionary.order.name.summary"), name);
	/* 打印表单数据 */
	if (id) OATPP_LOGD("Multipart", "id=%s", name.getValue({}).c_str());
	if (code) OATPP_LOGD("Multipart", "code='%s'", code.getValue({}).c_str());
	if (name) OATPP_LOGD("Multipart", "name=%s", name.getValue({}).c_str());

	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());

		/* 上传到FastDFS */
		ZO_CREATE_DFS_CLIENT(dfs);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		//检查文件类型是不是excel表格式
		if (suffix != "xls" && suffix != "xlsx")
		{
			//直接返回文件读取失败
			auto jvo = StringJsonVO::createShared();
			jvo->fail("Failed To Read File");
			return jvo;
		}

		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

		TemperatureService fs;
		if (!fs.insertData(downloadUrl))
		{
			//直接返回数据插入失败
			auto jvo = StringJsonVO::createShared();
			jvo->fail("Failed To Insert Data");
			return jvo;
		}
	}

	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TemperatureController::execDownloadExcel(const String filename)
{
	TemperatureService fs;

	string path = fs.queryData();

	ZO_CREATE_DFS_CLIENT(dfs);

	string savePath = "./public/fastdfs";

	string filePath = dfs.downloadFile(path, &savePath);

	ifstream file(filePath, std::ios::binary);

	string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	// 判断是否读取成功
	if (content.empty())
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, content);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	dfs.deleteFile(filePath);

	// 影响成功结果
	return response;
}

TemperatureNamePageJsonVO::Wrapper TemperatureController::execQueryNameTemperature(const PageQuery::Wrapper& query)
{
	// 定义一个Service
	TemperatureService service;
	// 查询数据
	auto result = service.listTemperatureName(query);
	// 响应结果
	auto jvo = TemperatureNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//分页查询
TemperaturePageJsonVO::Wrapper TemperatureController::execQueryTemperature(const TemperatureQuery::Wrapper& temperatureQuery)
{
	// 定义一个Service
	TemperatureService service;

	// 查询数据
	auto result = service.listQueryTemperature(temperatureQuery);

	// 响应结果
	auto jvo = TemperaturePageJsonVO::createShared();

	jvo->success(result);

	return jvo;
}

Uint64JsonVO::Wrapper TemperatureController::execAddTemperature(const TemperatureAddDTO::Wrapper& adddto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!adddto->deg_type_code || !adddto->deg_type_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 非空校验
	if (adddto->deg_type_code->empty() || adddto->deg_type_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//定义service
	TemperatureService service;
	//生成Id，获取创建人、日期等信息，组合数据生成成DetailDTO
	//使用UUID
	TemperatureDetailDTO::Wrapper detaildto;
	detaildto->id = UuidFacade().genUuid();
	detaildto->deg_type_code = adddto->deg_type_code;
	detaildto->deg_type_name = adddto->deg_type_name;
	//创建人 创建人登录名称 创建日期
	detaildto->create_name = payload.getUsername();
	detaildto->create_by = payload.getRealname();
	//时间使用SimpleDateTimeFormat
	detaildto->create_date = SimpleDateTimeFormat::formatWithMilli();
	//公司部门
	detaildto->sys_org_code = payload.getOrgcode();
	detaildto->sys_company_code = payload.getCompanycode();
	//执行插入服务
	uint64_t id = service.addData(detaildto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	//返回响应结果
	return jvo;



}

