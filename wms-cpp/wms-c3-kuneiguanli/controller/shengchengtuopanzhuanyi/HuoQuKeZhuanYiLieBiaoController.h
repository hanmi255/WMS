#pragma once
#ifndef _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_CONTROLLER_
#define _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_CONTROLLER_
#include "domain/GlobalInclude.h"
#include "domain/vo/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoVO.h"
#include "domain/query/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
 可转移列表
*/
class HuoQuKeZhuanYiLieBiaoController : public oatpp::web::server::api::ApiController {

    API_ACCESS_DECLARE(HuoQuKeZhuanYiLieBiaoController);

public:
    ENDPOINT_INFO(queryALL) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tuopanzhuanyi.query-all.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(HuoQuKeZhuanYiLieBiaoPageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义其他查询参数描述
        //API_DEF_ADD_QUERY_PARAMS(String, "move_date", ZH_WORDS_GETTER("tuopanzhuanyi.field.move_date"), "2022/2/22", false);
        API_DEF_ADD_QUERY_PARAMS(String, "kuctype", ZH_WORDS_GETTER("tuopanzhuanyi.field.kuctype"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("tuopanzhuanyi.field.ku_wei_bian_ma"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("tuopanzhuanyi.field.bin_id"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("tuopanzhuanyi.field.cus_code"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "zhong_wen_qch", ZH_WORDS_GETTER("tuopanzhuanyi.field.zhong_wen_qch"), "zhang san", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_id"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "shp_ming_cheng", ZH_WORDS_GETTER("tuopanzhuanyi.field.shp_ming_cheng"), "kele", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_date", ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_pro_date"), "2022/2/2", false);
    }

    ENDPOINT(API_M_GET, "/kuneiguanli/shengchengtuopanzhuanyi/query-move-list", queryALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(kezhuanyiQuery, HuoQuKeZhuanYiLieBiaoQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryAll(kezhuanyiQuery));
    }

private:
    HuoQuKeZhuanYiLieBiaoPageJsonVO::Wrapper execQueryAll(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // !_HUO_QU_KE_ZHUAN_YI_LIE_BIAO_CONTROLLER_