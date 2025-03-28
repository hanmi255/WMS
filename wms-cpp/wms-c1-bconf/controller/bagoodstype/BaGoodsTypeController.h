#pragma once
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/bagoodstype/BaGoodsTypeDTO.h"
#include "domain/query/bagoodstype/BaGoodsTypeQuery.h"
#include "domain/vo/bagoodstype/BaGoodsTypeVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class BaGoodsTypeController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(BaGoodsTypeController);
public:
    //查询产品属性接口描述
    ENDPOINT_INFO(getBaGoodsType) {
        //信息
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ba_goods_type.get.summary"));
        //授权
        API_DEF_ADD_AUTH();
        //分页查询
        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_RSP_JSON_WRAPPER(BaGoodsTypePageJsonVO);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_type_code", ZH_WORDS_GETTER("ba_goods_type.field.goods_type_code"), "zz", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_type_name", ZH_WORDS_GETTER("ba_goods_type.field.goods_type_code"), "11", false);
    }
    //查询产品属性接口处理
    ENDPOINT("GET", "/pa/list-pa", getBaGoodsType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, BaGoodsTypeQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryBaGoodsType(userQuery, authObject->getPayload()));
    }

private:
    //分页查询产品属性
    BaGoodsTypePageJsonVO::Wrapper execQueryBaGoodsType(const BaGoodsTypeQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) ///< En