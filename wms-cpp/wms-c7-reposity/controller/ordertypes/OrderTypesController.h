/*
 @Author: nanbowan
*/
#ifndef _ORDERTYPES_CONTROLLER_
#define _ORDERTYPES_CONTROLLER_

#include "domain/GlobalInclude.h"
#include"domain/vo/BaseJsonVO.h"
#include "domain/dto/ordertypes/OrderTypesDTO.h" 

#include OATPP_CODEGEN_BEGIN(ApiController)


class OrderTypesController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(OrderTypesController);

public:
     //定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictionary.ope.modify.summary"), modifySample, Uint64JsonVO::Wrapper);
    // 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/repository/ord/modify", modifySample, BODY_DTO(ModifyOrderTypeDTO::Wrapper, dto), execModifyOrd(dto));

    // 3.1 定义删除接口描述
    ENDPOINT_INFO(deleteOrd) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictionary.ope.delete.summary"), Uint64JsonVO::Wrapper);
        // 定义其他路径参数说明
        API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("dictionary.ope.delete.summary"), 1, true);
    }
    // 3.2 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/repository/ord-delete/{id}", deleteOrd, PATH(oatpp::String, id), execDeleteOrd(id));

private:
    Uint64JsonVO::Wrapper execModifyOrd(const ModifyOrderTypeDTO::Wrapper& dto);

    Uint64JsonVO::Wrapper execDeleteOrd(const oatpp::String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _ORDERTYPES_CONTROLLER_