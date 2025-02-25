#pragma once
#ifndef _BIN_CONTROLLER_H_
#define _BIN_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/keyongchuwei/BinQuery.h"
#include "domain/vo/keyongchuwei/BinVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class BinController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(BinController);
public:
	ENDPOINT_INFO(exportBinXlsx) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("bin.xlsx.summary"), Void);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "file_path", ZH_WORDS_GETTER("bin.file_path"), "C:\\", true);
		API_DEF_ADD_QUERY_PARAMS(String, "ids", ZH_WORDS_GETTER("bin.ids"), String{ "1,2,3" }, true);
	}
	ENDPOINT(API_M_GET, "/chuweiguanli/keyongchuwei/export-usefulbin-xlsx", exportBinXlsx, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(ids, BinExcelQuery, queryParams);
		return execExportBinXlsx(ids);
	}

	ENDPOINT_INFO(queryBinList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("bin.list.summary"), BinPageJsonVO::Wrapper);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(BinPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("bin.bin_store"), ZH_WORDS_GETTER("bin.bin_store_example"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_shu_xing", ZH_WORDS_GETTER("bin.ku_wei_shu_xing"), ZH_WORDS_GETTER("bin.ku_wei_shu_xing_example"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("bin.ku_wei_bian_ma"), "A-5-1-1-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "suo_shu_ke_hu", ZH_WORDS_GETTER("bin.suo_shu_ke_hu"), "001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "shang_jia_ci_xu", ZH_WORDS_GETTER("bin.shang_jia_ci_xu"), "111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "gao", ZH_WORDS_GETTER("bin.gao"), "10", false);
	}
	ENDPOINT(API_M_GET, "/chuweiguanli/keyongchuwei/query-usefulbin-list", queryBinList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME){
		API_HANDLER_QUERY_PARAM(binQuery, BinPageQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryBinList(binQuery));
	}
private:
	std::shared_ptr<OutgoingResponse> execExportBinXlsx(const BinExcelQuery::Wrapper& ids);
	BinPageJsonVO::Wrapper execQueryBinList(const BinPageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_BIN_CONTROLLER_H_
