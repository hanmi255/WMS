#pragma once
/*

 @Author: qingbingwei
 @Date: 2025/3/10 14:22

*/
#ifndef _REVIEW_STT_CONTROLLER_
#define _REVIEW_STT_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/query/review-stt/ReviewSttQuery.h"
#include "domain/dto/review-stt/ReviewSttDTO.h"
#include "domain/vo/review-stt/ReviewSttVO.h"
#include "Macros.h"
#include "ExcelComponent.h"



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 盘点管理-复盘
 */
class ReviewSttController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ReviewSttController);
	// 3 定义接口
public:

	//查询盘点列表（条件+分页）
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review-stt.goods.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewSttPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述---暂时先这样，后续补上，因为有点多
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("review-stt.goods.field.bin_id"), "X1-1-03", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("review-stt.goods.field.tin_id"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("review-stt.goods.field.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("review-stt.goods.field.goods_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo1"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("review-stt.goods.field.goods_pro_data"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("review-stt.goodsfield.goods_batch"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("review-stt.goods.field.cus_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo2"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("review-stt.goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("review-stt.goods.field.stt_sta"), "null", false);
	}

	ENDPOINT(API_M_GET, "/review/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为ReviewSttQuery领域模型
		API_HANDLER_QUERY_PARAM(goodsQuery, ReviewSttQuery, queryParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		API_HANDLER_RESP_VO(execQueryAll(goodsQuery));
	}

	//复盘
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("review-stt.goods.review.summary"), reviewStt, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/review/review-stt", reviewStt, BODY_DTO(ReviewSttDTO::Wrapper, dto), execReviewStt(dto, authObject->getPayload()));

	//导出所有复盘数据---有查询条件
	ENDPOINT_INFO(exportReviewStt) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review-stt.goods.export-review-stt.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("review-stt.goods.field.bin_id"), "X1-1-03", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("review-stt.goods.field.tin_id"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("review-stt.goods.field.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("review-stt.goods.field.goods_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo1"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("review-stt.goods.field.goods_pro_data"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("review-stt.goods.field.goods_batch"), "2099-12-31", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("review-stt.goods.field.cus_name"), ZH_WORDS_GETTER("review-stt.goods.name.demo2"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus", ZH_WORDS_GETTER("review-stt.goods.field.cus"), "****", false);
		API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("review-stt.goods.field.stt_sta"), "null", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/review/export-review-stt", exportReviewStt, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
		// 解析查询参数为ExportGoodsDiffPostQuery领域模型
		API_HANDLER_QUERY_PARAM(exportQuery, ExportReviewSttQuery, exportParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		//API_HANDLER_RESP_VO(execExportDiffPost(exportQuery));
		return execExportReviewStt(exportQuery);
	}

private:
	ReviewSttPageJsonVO::Wrapper execQueryAll(const ReviewSttQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execReviewStt(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload);
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportReviewStt(const ExportReviewSttQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_REVIEW_STT_CONTROLLER_
