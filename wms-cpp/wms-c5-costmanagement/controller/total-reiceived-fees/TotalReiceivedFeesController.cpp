
#include "stdafx.h"
#include "TotalReiceivedFeesController.h"
//#include "../../service/sample/SampleService.h"
#include "../../service/total-reiceived-fees/TotalReiceivedFeesService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"

TotalReiceivedFeesPageJsonVO::Wrapper TotalReiceivedFeesController::execQueryListOfTotalFees(const TotalReiceivedFeesQuery::Wrapper& query, const PayloadDTO& payload) {
	TotalReiceivedFeesService service;
	auto re = service.listAll(query);
	auto jvo = TotalReiceivedFeesPageJsonVO::createShared();
	jvo->success(re);
	return jvo;
}



std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>   TotalReiceivedFeesController::execExport(const TotalReiceivedFeesQuery::Wrapper& query, const PayloadDTO& payload) {
	//调用service层导出全部数据
	TotalReiceivedFeesService service;
	auto result = service.exportAll(query);
	//给查询结果加上表头
	vector<string> title = {
		ZH_WORDS_GETTER("TRF.feedate"),
		ZH_WORDS_GETTER("TRF.customers"),
		ZH_WORDS_GETTER("TRF.customersname"),
		ZH_WORDS_GETTER("TRF.fees"),
		ZH_WORDS_GETTER("TRF.feesname"),
		ZH_WORDS_GETTER("TRF.billingquantity"),
		ZH_WORDS_GETTER("TRF.unityofquantity"),
		ZH_WORDS_GETTER("TRF.originalprice"),
		ZH_WORDS_GETTER("TRF.taxexclusiveprice"),
		ZH_WORDS_GETTER("TRF.taxamount"),
		ZH_WORDS_GETTER("TRF.taxinclusiveprice"),
	};
	result.insert(result.begin(), title);
	//导入excel
	ExcelComponent excel;
	//excel.writeVectorToFile("C:/Users/wcy/Desktop/save.xlsx", ZH_WORDS_GETTER("cost-detail.download.field.sheetname"), result);//保存到本地
	//返回给前端
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("TRF.sheetname"), result);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());
	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to export data: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Data Not Found");
	}
	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);
	// 设置响应头信息
   // 设置 Content-Type 为 Excel 文件类型
	//response->putHeader("Content-Type", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
	// 设置 Content-Disposition 头，指定文件名并添加 .xlsx 扩展名
	String filename = "totalreceivedfees.xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);

	// 影响成功结果
	return response;
}
