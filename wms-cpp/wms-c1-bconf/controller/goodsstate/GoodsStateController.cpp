#include "stdafx.h"
#include "GoodsStateController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/goodsstate/GoodsStateService.h"
#include "../../domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"
#include "../../domain/dto/goodsstate/GoodStateDTO.h"
#include "ExcelComponent.h"
#include "domain/vo/goodsstate/GoodsStateVO.h"
#include "Macros.h"
// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
//数据的导入功能
// 导入数据
StringJsonVO::Wrapper GoodsStateController::execUploadOne(std::shared_ptr<IncomingRequest> request) {
	// 1. 初始化
	API_MULTIPART_INIT(container, reader);
	// 2. 配置读取器，读取用户传入的 file 类型的文件
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);

	// 3. 读取数据
	request->transferBody(&reader);

	// 4. 解析 Excel 文件
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (!file) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail("No file uploaded");
		return jvo;
	}

	// 5. 读取 Excel 文件内容
	ExcelComponent excel;
	auto data = excel.readIntoVector(file->data(), file->size(), ZH_WORDS_GETTER("goodsstate.name"));
	// 5.1 确保数据不为空
	if (data.empty()) {
		auto jvo = StringJsonVO::createShared();
		jvo->fail("Sheet '品检状态表' not found or empty");
		return jvo;
	}
	// 6. 校验数据并导入到数据库
	GoodsStateService service;
	bool result = service.importData(data);

	// 7. 返回导入结果
	auto jvo = StringJsonVO::createShared();

	if (result) {
		jvo->fail("Failed to import data");
	}
	else {
		jvo->success("Data imported successfully");
	}
	return jvo;
}
//数据的导出
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> GoodsStateController::execDownloadFile(const String& filename)
{
	//1.定义一个Service,查询数据 此时得到的数据时DTO 从数据库读取到的数据
	GoodsStateService service;
	auto query = GoodStateQuery::createShared();
	auto dtoList = service.QueryAll(query);	

	// 2.1检查 dto 是否为空  判空处理这一步很重要，否者报权限错误*****
	if (dtoList.empty()) {
		return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	}
	// 2. 将 DTO数据转换为二维数组
	std::vector<std::vector<std::string>> data;
	//std::vector<std::string> header = { "ID", "Create Name", "Create By", "Create Date", "Update Name", "Update By", "Update Date", "Sys Org Code", "Sys Company Code", "QM Sta Code", "QM Sta Name" };
	std::vector<std::string> header = { 
	ZH_WORDS_GETTER("goodsstate.id"),
	ZH_WORDS_GETTER("goodsstate.create_name"),
	ZH_WORDS_GETTER("goodsstate.create_by"),
	ZH_WORDS_GETTER("goodsstate.create_date"),
	ZH_WORDS_GETTER("goodsstate.update_name"),
	ZH_WORDS_GETTER("goodsstate.update_by"), 
	ZH_WORDS_GETTER("goodsstate.update_date"), 
	ZH_WORDS_GETTER("goodsstate.sys_org_code"), 
	ZH_WORDS_GETTER("goodsstate.sys_company_code"), 
	ZH_WORDS_GETTER("goodsstate.qm_qa_code"), 
	ZH_WORDS_GETTER("goodsstate.qm_qa_name")};

	data.push_back(header); // 添加表头

	// 3.将 DTO 数据填充到二维数组中
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
		row.push_back(dto->qm_sta_code);
		row.push_back(dto->qm_sta_name);
		data.push_back(row); // 将每一行数据添加到二维数组中
	}

	///3. 使用 ExcelComponent 将数据写入 Excel 文件
	ExcelComponent excle;
	auto buff=excle.writeVectorToBuff(ZH_WORDS_GETTER("goodsstate.name"), data); // 生成 Excel 文件
	// 4. 返回 Excel 文件给前端
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	//5. 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	//6. 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue("")+".xlsx");

	// 影响成功结果
	return response;
}
// 批量删除
StringJsonVO::Wrapper GoodsStateController::execBatchRemoveGoodsState(const BatchDeleteRequestDTO::Wrapper& dto) {
	//1.定义返回参数类型
	auto jvo = StringJsonVO::createShared();
	if (!dto || dto->ids->empty()) {
		jvo->fail("No IDs provided for batch deletion");
		return jvo;
	}
	// 将 DTO 中的 ID 列表转换为 vector<string>
	std::vector<std::string> ids;
	for (const auto& id : *dto->ids) {
		ids.push_back(id); // oatpp::String 可以隐式转换为 std::string
	}
	// 调用 Service 层进行批量删除
	GoodsStateService service;
	bool result = service.removeDates(ids);
	if (result) {
		jvo->success("deletion successful");
	}
	else {
		jvo->fail("deletion failed");
	}
	return jvo;
}
