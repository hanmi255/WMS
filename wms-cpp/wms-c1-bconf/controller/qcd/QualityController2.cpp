#include "stdafx.h"
#include "QualityController2.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/qcd/QualityService2.h"
#include "../../domain/do/qcd/QualityDO2.h"
#include "../../domain/dto/qcd/QualityDTO2.h"
#include "ExcelComponent.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

// 删除品质代码
StringJsonVO::Wrapper QualityController2::execDeleteQuality(const DeleteDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto || dto->ids->empty()) {
		jvo->code = 10001;
		jvo->message = "params is invalid";
		jvo->data = "0";
		return jvo;
	}

	std::vector<std::int32_t> ids;
	for (const auto& id : *dto->ids) {
		ids.push_back(id);
	}

	// 定义一个Service
	QualityService service;
	// 执行数据删除
	int count = service.removeData(ids);
	if (count > 0) {
		jvo->code = 10000;
		jvo->message = "operation is successful";
		jvo->data = std::to_string(count);
	}
	else
	{
		jvo->code = 10001;
		jvo->message = "operation failed";
		jvo->data = "0";
	}
	// 响应结果
	return jvo;
}

// 单文件上传
StringJsonVO::Wrapper QualityController2::execUploadFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	// 初始化
	API_MULTIPART_INIT(container, reader);

	// 配置读取器
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);

	// 读取数据
	request->transferBody(&reader);

	// 解析文件
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (!file) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Not Found File");
		return jvo;
	}

	// 读取文件内容
	ExcelComponent excel;
	auto data = excel.readIntoVector(file->data(), file->size(), ZH_WORDS_GETTER("qcd.name"));


	// 导入数据库
	QualityService service;
	bool result = service.importData(data, payload);

	// 返回结果
	auto jvo = StringJsonVO::createShared();
	if (result) {
		jvo->code = 10000;
		jvo->message = "operation is successful";
		jvo->data = "1";
	}
	else {
		jvo->code = 10001;
		jvo->message = "operation failed";
		jvo->data = "0";
	}
	return jvo;
}

// 文件下载
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> QualityController2::execDownloadFile(const String& filename)
{
	// 定义Service
	QualityService service;
	auto query = QualityQuery::createShared();
	auto dtoList = service.QueryAll(query);

	// 检查DTO是否为空
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}
	// 转换为二维数组
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> header = {
		ZH_WORDS_GETTER("qcd.id"),
		ZH_WORDS_GETTER("qcd.create_name"),
		ZH_WORDS_GETTER("qcd.create_by"),
		ZH_WORDS_GETTER("qcd.create_date"),
		ZH_WORDS_GETTER("qcd.update_name"),
		ZH_WORDS_GETTER("qcd.update_by"),
		ZH_WORDS_GETTER("qcd.update_date"),
		ZH_WORDS_GETTER("qcd.sys_org_code"),
		ZH_WORDS_GETTER("qcd.sys_company_code"),
		ZH_WORDS_GETTER("qcd.qm_qa_code"),
		ZH_WORDS_GETTER("qcd.qm_qa_name")
	};

	data.push_back(header);

	// 将DTO数据填充到二维数组中
	for (const auto& dto : dtoList) {
		std::vector<std::string> row;
		row.push_back(dto->id);
		row.push_back(dto->create_name);
		row.push_back(dto->create_by);
		row.push_back(dto->create_date);
		row.push_back(dto->update_name);
		row.push_back(dto->update_by);
		row.push_back(dto->update_date);
		row.push_back(dto->sys_org_code);
		row.push_back(dto->sys_company_code);
		row.push_back(dto->qm_qa_code);
		row.push_back(dto->qm_qa_name);

		data.push_back(row);
	}

	// 写入Excel文件
	ExcelComponent excle;
	auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("qcd.name"), data);
	// 返回Excel文件
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	// 判断是否成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);

	// 手动格式化年月日
	char buffer[9];  // 存储格式化后的字符串
	std::strftime(buffer, sizeof(buffer), "%Y%m%d", localTime);

	response->putHeader("Content-Type", "application/vnd.ms-excel");
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue("") + "_" + buffer + ".xlsx");

	// 影响成功结果
	return response;
}