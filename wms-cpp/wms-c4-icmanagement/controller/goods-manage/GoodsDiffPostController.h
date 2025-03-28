#pragma once
/*

 @Author: qingbingwei
 @Date: 2025/2/22 14:22

*/
#ifndef _GOODS_DIFF_POST_CONTROLLER_
#define _GOODS_DIFF_POST_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/goods-manage/GoodsDiffPostVO.h"
#include "domain/dto/goods-manage/GoodsDiffPostDTO.h"
#include "domain/query/goods-manage/GoodsDiffPostQuery.h"
#include "Macros.h"
#include "ExcelComponent.h"
//#include "../../../arch-tests/Macros.h"



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 盘点管理-盘点差异过账
 */
class GoodsDiffPostController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GoodsDiffPostController);
	// 3 定义接口
public:

	//查询差异过账（条件+分页）
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("diff-post.goods.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GoodsDiffPostPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述---暂时先这样，后续补上，因为有点多
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("diff-post.goods.field.bin_id"), "X1-1-03", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("diff-post.goods.field.tin_id"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("diff-post.goods.field.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("diff-post.goods.field.goods_name"), ZH_WORDS_GETTER("diff-post.goods.name.demo1"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("diff-post.goods.field.goods_pro_data"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("diff-post.goodsfield.goods_batch"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("diff-post.goods.field.cus_name"), ZH_WORDS_GETTER("diff-post.goods.name.demo2"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("diff-post.goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("diff-post.goods.field.stt_sta"), "null", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date_start", ZH_WORDS_GETTER("diff-post.goods.field.create_date_start"), "2024-09-25 14:18:56", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date_end", ZH_WORDS_GETTER("diff-post.goods.field.create_date_end"), "2024-09-27 17:37:07", false);
	}

	ENDPOINT(API_M_GET, "/goods/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为GoodsDiffPostQuery领域模型
		API_HANDLER_QUERY_PARAM(goodsQuery, GoodsDiffPostQuery, queryParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		API_HANDLER_RESP_VO(execQueryAll(goodsQuery));
	}

	//差异过账
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("diff-post.goods.diff-post.summary"), diffPost, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/goods/diff-post", diffPost, BODY_DTO(GoodsDiffPostDTO::Wrapper, dto), execDiffPost(dto, authObject->getPayload()));

	//导出所有差异过账数据---有查询条件
	ENDPOINT_INFO(exportDiffPost) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("diff-post.goods.export-diff-post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("diff-post.goods.field.bin_id"), "X1-1-03", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("diff-post.goods.field.tin_id"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("diff-post.goods.field.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("diff-post.goods.field.goods_name"), ZH_WORDS_GETTER("diff-post.goods.name.demo1"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("diff-post.goods.field.goods_pro_data"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("diff-post.goods.field.goods_batch"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("diff-post.goods.field.cus_name"), ZH_WORDS_GETTER("diff-post.goods.name.demo2"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("diff-post.goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("diff-post.goods.field.stt_sta"), "null", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date_start", ZH_WORDS_GETTER("diff-post.goods.field.create_date_start"), "2024-09-25 14:18:56", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date_end", ZH_WORDS_GETTER("diff-post.goods.field.create_date_end"), "2024-09-27 17:37:07", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "filename", "filename", "file/test.xlsx", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/goods/export-diff-post", exportDiffPost, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
		// 解析查询参数为ExportGoodsDiffPostQuery领域模型
		API_HANDLER_QUERY_PARAM(exportQuery, ExportGoodsDiffPostQuery, exportParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		//API_HANDLER_RESP_VO(execExportDiffPost(exportQuery));
		return execExportDiffPost(exportQuery);
	}

private:
	GoodsDiffPostPageJsonVO::Wrapper execQueryAll(const GoodsDiffPostQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execDiffPost(const GoodsDiffPostDTO::Wrapper& dto, const PayloadDTO& payload);
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportDiffPost(const ExportGoodsDiffPostQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_GOODS_DIFF_POST_CONTROLLER_
