#pragma once
/*

 @Author: qingbingwei
 @Date: 2025/2/22 14:22

*/
#ifndef _GOODS_DIFF_POST_CONTROLLER_
#define _GOODS_DIFF_POST_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/costconfig/GoodsDiffPostVO.h"
#include "domain/dto/costconfig/GoodsDiffPostDTO.h"
#include "domain/query/costconfig/GoodsDiffPostQuery.h"
#include "Macros.h"
#include "ExcelComponent.h"




// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 盘点管理-盘点企业等级
 */
class GoodsDiffPostController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GoodsDiffPostController);
	// 3 定义接口
public:


	//导出所有企业等级数据---有查询条件
	ENDPOINT_INFO(exportDiffPost) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("diff-post.goods.export-diff-post.summary"));

	}
	// 定义端点
	ENDPOINT(API_M_GET, "/entleve/export-entleve", exportDiffPost, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
		// 解析查询参数为ExportGoodsDiffPostQuery领域模型
		API_HANDLER_QUERY_PARAM(exportQuery, ExportGoodsDiffPostQuery, exportParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
		//API_HANDLER_RESP_VO(execExportDiffPost(exportQuery));
		return execExportDiffPost(exportQuery);
	}

private:
	GoodsDiffPostPageJsonVO::Wrapper execQueryAll(const GoodsDiffPostQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execDiffPost(const GoodsDiffPostDTO::Wrapper& dto);
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportDiffPost(const ExportGoodsDiffPostQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_GOODS_DIFF_POST_CONTROLLER_
