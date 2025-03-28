#include "stdafx.h"
#include "GetCostList.h"
#include "../../service/cost-sum/CostSumService.h"
 CostSumPageJsonVO ::Wrapper GetCostSumList::executequery(const CostSumQuery::Wrapper& query)
{
	 auto cs = CostSumPageJsonVO::createShared();
	 CostSumService service;
	 auto res = service.listall(query);
	 cs->success(res);
	 return cs;
}
 std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> GetCostSumList::execDownloadFile(const CostSumQuery::Wrapper& query)
 {
	 CostSumService service;
	 list<CostSumDO> res = service.exportdata(query);
	 std::vector<std::vector<std::string>> data;
	 std::vector<std::string> title;
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_data"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cus_code"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cus_name"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_code"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_name"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_sl"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_unit"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_yj"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_bhs"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_se"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_hsj"));
	 title.push_back(ZH_WORDS_GETTER("cost.field.cost_js"));
	 data.push_back(title);
	 for (auto a : res)
	 {
		 std::vector<std::string> row;
		 row.push_back(a.getcost_date());
		 row.push_back(a.getclient_c());
		 row.push_back(a.getclient_name());
		 row.push_back(a.getcost_c());
		 row.push_back(a.getcost_name());
		 row.push_back(a.getNumber());
		 row.push_back(a.getUnit());
		 row.push_back(a.getorg_price());
		 row.push_back(a.getno_tax());
		 row.push_back(a.getTax());
		 row.push_back(a.gettax_price());
		 row.push_back(a.getCost_Js());
		 data.push_back(row);
	 }
	 ExcelComponent excel;
	 auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("excel.info"), data);
	 const char* resData = reinterpret_cast<const char*>(buff.data());
	 auto fstring = String(resData, buff.size());

	 // 判断是否读取成功
	 if (!fstring)
	 {
		 std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		 return createResponse(Status::CODE_404, "File Not Found");
	 }

	 // 创建响应头
	 auto response = createResponse(Status::CODE_200, fstring);
	 // 获取当前时间点
	 auto now = std::chrono::system_clock::now();

	 // 将时间点转换为时间戳
	 std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	 // 使用 stringstream 进行时间格式化
	 std::ostringstream oss;
	 oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");

	 //设置文件名
	 string filename = "loading_fee_" + oss.str() + ".xlsx";
	 // 设置响应头信息
	 response->putHeader("Content-Disposition", "attachment; filename="+filename);
	 return response;
 }