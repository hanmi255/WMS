#pragma once
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/goodstype/GoodsTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class GoodsController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(GoodsController)
public:
    // 录入产品属性
    ENDPOINT_INFO(addType) {
        API_DEF_ADD_AUTH();
        info->summary = ZH_WORDS_GETTER("goods.add.summary");
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    ENDPOINT("POST", "/pa/add", addType, BODY_DTO(GoodsTypeAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execAddGoodsType(dto, authObject->getPayload()));
    }

private:
    Uint64JsonVO::Wrapper execAddGoodsType(const GoodsTypeAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen