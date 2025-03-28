
/*
 @Author: yxqf
*/
#include "stdafx.h"
#include "BaActTypeController.h"
#include "../../service/ba_act_type/BaActTypeService.h" 
#include"../../domain/dto/ba_act_type/BaActTypeDTO.h"
#include <iostream>
// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

using std::vector;
using std::string;

// 1. 作业类型分页查询
BaActTypePageJsonVO::Wrapper BaActTypeController::execQueryBaActType(const BaActTypeQuery::Wrapper& query, const PayloadDTO& payload) {
	BaActTypeService service;
	auto result =  service.listAll(query);

	auto jvo = BaActTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 2. 作业类型新增
Uint64JsonVO::Wrapper BaActTypeController::execAddBaActType(const BaActTypeAddDTO::Wrapper& dto) {

	auto jvo = Uint64JsonVO::createShared();
	//BaActTypeDetailDTO::Wrapper data;



	if (!dto->act_type_code || !dto->act_type_name || !dto->oper_step_code) {
		auto jvo = Uint64JsonVO::createShared();
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	BaActTypeService service;
	auto id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}


	return jvo;


}

// 3. 作业类型修改
StringJsonVO::Wrapper BaActTypeController::execModifyBaActType(const BaActTypeDTO::Wrapper& dto) {
	auto jvo = StringJsonVO::createShared();
	if (!dto->act_type_code || !dto->act_type_name || !dto->oper_step_code)
	{
		jvo->init(String("参数为空"), RS_PARAMS_INVALID);
		return jvo;
	}

	BaActTypeService service;
	if (service.updateData(dto)) {
		jvo->init(String("修改成功"), RS_SUCCESS);
	}
	else
	{
		jvo->init(String("服务器错误,重新尝试"), RS_FAIL);
	}
	return jvo;
}

// 4. 作业类型删除
StringJsonVO::Wrapper BaActTypeController::execRemoveBaActType(const String& id) {
	auto jvo = StringJsonVO::createShared();

	if (id == "")
	{
		jvo->init(id, RS_PARAMS_INVALID);
		return jvo;
	}
	BaActTypeService service;
	if (service.removeData(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	return jvo;
}


StringJsonVO::Wrapper BaActTypeController::execUploadOne(std::shared_ptr<IncomingRequest> request) {

	auto createErrorResponse = [](const std::string& msg) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail(msg);
		return jvo;
	};

	try {
		// 生成一个唯一的临时文件名，确保 /tmp 目录存在且有写权限（Windows请改成合适的路径）
		std::string tempFile = "/tmp/ba_act_type_import_" +
			std::to_string(time(nullptr)) + "_" +
			std::to_string(rand()) + ".xlsx";

		// 1. 初始化 Multipart 读取器
		API_MULTIPART_INIT(container, reader);

		// 2. 配置读取器：设置字段 "file" 以内存方式存储（可选：若文件较大，可改为文件模式）
		API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
		API_MULTIPART_CONFIG_MEMO(reader, "file", -1);

		// 3. 读取请求数据
		request->transferBody(&reader);

		// 4. 解析文件字段 "file"
		API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
		if (!file) {
			return createErrorResponse("no file");
		}
		else
		{
			/* 打印文件名称 */
			string filename = partfile->getFilename().getValue("");
			OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
			/* 测试将文件保存到磁盘上面 */
			string fullPath = "123" + filename;
			file.saveToFile(fullPath.c_str());
			cout << fullPath<< "     " << filename << endl;;
			string sheetname = ZH_WORDS_GETTER("ba_act_type.export.sheet");
			cout << "sheetname:  " << sheetname << endl;
			//加载保存的excl
			ExcelComponent excl;
			excl.loadFile(fullPath);
			auto data = excl.readIntoVector(fullPath,sheetname);
			BaActTypeService server;
			server.saveData_noid(data);
		}

		// 7. 返回响应结果
		auto jvo = StringJsonVO::createShared();
		jvo->success("文件上传成功");
		return jvo;

	}
	catch (const std::exception& e) {
		OATPP_LOGE("Upload", "处理失败: %s", e.what());
		return createErrorResponse("系统处理错误: " + std::string(e.what()));
	}
}




std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
BaActTypeController::execDownloadFile(const String& filename) {

	BaActTypeService server;


	auto actTypeList = server.listAll();

	vector<vector<string>> data;


	// 插入表头
	data.push_back({
		ZH_WORDS_GETTER("ba_act_type.field.id"),
		ZH_WORDS_GETTER("ba_act_type.field.create_name"),
		ZH_WORDS_GETTER("ba_act_type.field.create_by") ,
		ZH_WORDS_GETTER("ba_act_type.field.create_date"),
		ZH_WORDS_GETTER("ba_act_type.field.update_name"),
		ZH_WORDS_GETTER("ba_act_type.field.update_by"),
		ZH_WORDS_GETTER("ba_act_type.field.update_date"),
		ZH_WORDS_GETTER("ba_act_type.field.sys_org_code"),
		ZH_WORDS_GETTER("ba_act_type.field.sys_company_code"),
		ZH_WORDS_GETTER("ba_act_type.field.act_type_code"),
		ZH_WORDS_GETTER("ba_act_type.field.act_type_name"),
		ZH_WORDS_GETTER("ba_act_type.field.oper_step_code")
		});

	// 遍历数据，构造每一行数据
	for (auto& record : actTypeList) {
		std::vector<std::string> row;
		row.push_back(record.getId());
		row.push_back(record.getCreateName());
		row.push_back(record.getCreateBy());
		row.push_back(record.getCreateDate());
		row.push_back(record.getUpdateName());
		row.push_back(record.getUpdateBy());
		row.push_back(record.getUpdateDate());
		row.push_back(record.getSysOrgCode());
		row.push_back(record.getSysCompanyCode());
		row.push_back(record.getActTypeCode());
		row.push_back(record.getActTypeName());
		row.push_back(record.getOperStepCode());
		data.push_back(row);
	}





	ExcelComponent excel;

	auto sheetName = ZH_WORDS_GETTER("ba_act_type.export.sheet");
	auto buff = excel.writeVectorToBuff(sheetName, data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());


	if (!fstring) {
		std::cerr << "Failed to generate Excel file: " << std::strerror(errno) << std::endl;
		return createResponse(oatpp::web::protocol::http::Status::CODE_500, "File generation failed");
	}

	auto response = createResponse(Status::CODE_200, fstring);

	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
	return response;
}




