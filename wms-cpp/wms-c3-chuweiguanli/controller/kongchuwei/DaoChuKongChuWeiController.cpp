#include "stdafx.h"
#include "DaoChuKongChuWeiController.h"
#include "../../service/kongchuwei/QueryService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DaoChuKongChuWeiController::execDownloadFile(const DaoChuKongChuWeiQuery::Wrapper& query) {
	QueryService service;
	auto result = service.listAll(query);
	vector<vector<string>> data;
	vector<string> seq;
	seq.push_back(ZH_WORDS_GETTER("store.field.bin_store"));
	seq.push_back(ZH_WORDS_GETTER("store.field.ku_wei_shu_xing"));
	seq.push_back(ZH_WORDS_GETTER("store.field.CHP_SHU_XING"));
	seq.push_back(ZH_WORDS_GETTER("store.field.ku_wei_bian_ma"));
	seq.push_back(ZH_WORDS_GETTER("store.field.suo_shu_ke_hu"));
	seq.push_back(ZH_WORDS_GETTER("store.field.zui_da_ti_ji"));
	seq.push_back(ZH_WORDS_GETTER("store.field.shang_jia_ci_xu"));
	seq.push_back(ZH_WORDS_GETTER("store.field.chang"));
	seq.push_back(ZH_WORDS_GETTER("store.field.kuan"));
	seq.push_back(ZH_WORDS_GETTER("store.field.gao"));
	seq.push_back(ZH_WORDS_GETTER("store.field.zui_da_tuo_pan"));
	seq.push_back(ZH_WORDS_GETTER("store.field.ting_yong"));
	seq.push_back(ZH_WORDS_GETTER("store.field.ku_wei_lei_xing")); 
	data.push_back(seq);
	for (auto item : *(result->rows)) {
		vector<string> sub;
		sub.push_back(item->bin_store);
		sub.push_back(item->ku_wei_shu_xing);
		sub.push_back(item->CHP_SHU_XING);
		sub.push_back(item->ku_wei_bian_ma);
		sub.push_back(item->suo_shu_ke_hu);
		sub.push_back(item->zui_da_ti_ji);
		sub.push_back(item->shang_jia_ci_xu);
		sub.push_back(item->chang);
		sub.push_back(item->kuan);
		sub.push_back(item->gao);
		sub.push_back(item->zui_da_tuo_pan);
		sub.push_back(item->ting_yong);
		sub.push_back(item->ku_wei_lei_xing);
		data.push_back(sub);
	}
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("excel.sheet.s1"), data);
	const char* tsdata = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsdata,buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename= kongchuwei.xlsx" );

	// 影响成功结果
	return response;
}