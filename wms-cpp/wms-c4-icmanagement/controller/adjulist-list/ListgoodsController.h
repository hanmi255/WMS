#pragma once
#ifndef _LISTGOODSCONTROLLER_
#define _LISTGOODSCONTROLLER_

/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ListgoodsController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/26 17:04
    *  @brief    : brief
*****************************************************************************/

#include "domain/GlobalInclude.h"
#include "domain/vo/adjust-list/ListgoodsVO.h"
#include "domain/dto/adjust-list/ListgoodsDTO.h"
#include "domain/query/adjust-list/ListgoodsQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "ExcelComponent.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
*上架货物-上架货物信息管理
*/


class ListgoodsController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(ListgoodsController);


public:

    /**
    *查询接口
    */
    ENDPOINT_INFO(queryALL) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("lis.query-all.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(ListgoodsPageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "id", "id", "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("lis.field.credate"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_qua", ZH_WORDS_GETTER("lis.field.goodsqua"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("lis.field.goodscode"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("lis.field.kuweicode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("lis.field.goodsname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_unit", ZH_WORDS_GETTER("lis.field.goodsunit"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("lis.field.orgbillcode"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("lis.field.tuobancode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("lis.field.huozhu"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "base_unit", ZH_WORDS_GETTER("lis.field.baseunit"),"", false);
        API_DEF_ADD_QUERY_PARAMS(String, "base_goodscount", ZH_WORDS_GETTER("lis.field.basegoodscount"), "", false);
    }

    ENDPOINT(API_M_GET, "/lis/qurry", queryALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(listQuery, ListgoodsQuery1, queryParams);
        // 呼叫执行函数响应结果
       API_HANDLER_RESP_VO(execQueryPage(listQuery, authObject->getPayload()));
        //API_HANDLER_RESP_VO(execQueryPage(lisQuery));

    }



    ENDPOINT_INFO(queryDETAIL)
    {
        // 定义通用描述
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("lis.query-all.detail"), ListgoodsdetailJsonVO::Wrapper);
        // 定义参数描述
		
		API_DEF_ADD_QUERY_PARAMS(String, "goods_qua", ZH_WORDS_GETTER("lis.field.goodsqua"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("lis.field.goodscredata"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("lis.field.tuobancode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("lis.field.kuweicode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "base_unit", ZH_WORDS_GETTER("lis.field.baseunit"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("lis.field.credate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("lis.field.goodscode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_unit", ZH_WORDS_GETTER("lis.field.goodsunit"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("lis.field.orgbillcode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("lis.field.huozhu"), "" , false);
        API_DEF_ADD_QUERY_PARAMS(String, "base_goodscount", ZH_WORDS_GETTER("lis.field.basegoodscount"), "", false);


        //API_DEF_ADD_QUERY_PARAMS(String, "id", "id", "0", true);
        //API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("lis.field.goodsname"), ZH_WORDS_GETTER("lis.field.meat"), false);
			/* API_DEF_ADD_QUERY_PARAMS(String, "create_name", ZH_WORDS_GETTER("lis.field.crename"), "1", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "create_by", ZH_WORDS_GETTER("lis.field.creloginame"), "2", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "update_name", ZH_WORDS_GETTER("lis.field.updname"), "3", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "update_by", ZH_WORDS_GETTER("lis.field.updloginame"), "2", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "update_date", ZH_WORDS_GETTER("lis.field.upddate"), "3", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "sys_org_code", ZH_WORDS_GETTER("lis.field.sysorgcode"), "4", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "sys_company_code", ZH_WORDS_GETTER("lis.field.syscompanycode"), "5", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "order_type_code", ZH_WORDS_GETTER("lis.field.orgbilltype"), "6", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "order_id_i", ZH_WORDS_GETTER("lis.field.orgbillrow"), "7", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "wm_to_up_id", ZH_WORDS_GETTER("lis.field.goodsupid"), "8", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("lis.field.goodsbatch"), "22", false);
			 API_DEF_ADD_QUERY_PARAMS(String, "act_type_code", ZH_WORDS_GETTER("lis.field.acttypecode"), "33", false);*/
		
	}

    API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/lis/qurrydetail", queryDETAIL, QUERY(String, id), execQuerydetail(id));


;
    



    /**
    *修改接口
    */

    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lis.modify-list.summary"), modifyList, StringJsonVO::Wrapper);

    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/lis/adjustlistgoods", modifyList, BODY_DTO(ListgoodsadjustDTO::Wrapper, dto), execModifyListgoods(dto, authObject->getPayload()));


    /*导出上架商品数据---by qingbingwei*/
    ENDPOINT_INFO(exportListGoods) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("lis.exportData.detail"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        //API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_QUERY_PARAMS(String, "goodsqua", ZH_WORDS_GETTER("lis.field.goodsqua"), "5", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goodscredata", ZH_WORDS_GETTER("lis.field.goodscredata"), "xxxx-xx-xx", false);
        API_DEF_ADD_QUERY_PARAMS(String, "tuobancode", ZH_WORDS_GETTER("lis.field.tuobancode"), "ATP002", false);
        API_DEF_ADD_QUERY_PARAMS(String, "kuweicode", ZH_WORDS_GETTER("lis.field.kuweicode"), "X1-1-01", false);
        API_DEF_ADD_QUERY_PARAMS(String, "baseunit", ZH_WORDS_GETTER("lis.field.baseunit"), ZH_WORDS_GETTER("lis.field.box"), false);
        API_DEF_ADD_QUERY_PARAMS(String, "credate", ZH_WORDS_GETTER("lis.field.credate"), "xxxx-xx-xx", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goodscode", ZH_WORDS_GETTER("lis.field.goodscode"), "RL001", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goodsname", ZH_WORDS_GETTER("lis.field.goodsname"), ZH_WORDS_GETTER("lis.field.meat"), false);
        API_DEF_ADD_QUERY_PARAMS(String, "goodsunit", ZH_WORDS_GETTER("lis.field.goodsunit"), ZH_WORDS_GETTER("lis.field.box"), false);
        API_DEF_ADD_QUERY_PARAMS(String, "orgbillcode", ZH_WORDS_GETTER("lis.field.orgbillcode"), "RK20240320-0003", false);
        API_DEF_ADD_QUERY_PARAMS(String, "huozhu", ZH_WORDS_GETTER("lis.field.huozhu"), "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")), false);
    }
    // 定义端点
    ENDPOINT(API_M_GET, "/lis/export-data", exportListGoods, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
        // 解析查询参数为ExportGoodsDiffPostQuery领域模型
        API_HANDLER_QUERY_PARAM(exportQuery, ExportDataQuery, exportParams);
        // 呼叫执行函数响应结果
        //API_HANDLER_RESP_VO(execQueryAll(goodsQuery, authObject->getPayload()));
        //API_HANDLER_RESP_VO(execExportDiffPost(exportQuery));
        return execExportData(exportQuery);
    }

private:
    //分页查询所有上架货物数据
    ListgoodsPageJsonVO::Wrapper execQueryPage(const ListgoodsQuery1::Wrapper& query, const PayloadDTO& payload);

	//查询上架货物的详细数据
    ListgoodsdetailJsonVO::Wrapper execQuerydetail(const String& id);

    //修改上架货物数据
    StringJsonVO::Wrapper execModifyListgoods(const ListgoodsadjustDTO::Wrapper& dto, const PayloadDTO& payload);

    std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportData(const  ExportDataQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_LISTGOODSCONTROLLER_