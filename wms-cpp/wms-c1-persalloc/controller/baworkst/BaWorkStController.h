#pragma once
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/query/baworkst/BaWorkStQuery.h"
#include "domain/dto/baworkst/BaWorkStDTO.h"
#include "domain/vo/baworkst/BaWorkStVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class BaWorkStController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(BaWorkStController);
public:
    //查询工作状态接口描述
    ENDPOINT_INFO(getBaWorkSt) {
        //信息
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ba_work_st.get.summary"));
        //授权
        API_DEF_ADD_AUTH();

        //分页查询
        API_DEF_ADD_PAGE_PARAMS();
        //条件查询
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("ba_work_st.field.id"), "id", false);
        API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("ba_work_st.field.create_name"), "li ming", false);
        API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("ba_work_st.field.update_name"), "li ming", false);

        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    //查询工作状态接口处理
    ENDPOINT("GET", "/ops/list-ops", getBaWorkSt, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, BaWorkStQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryBaWorkSt(userQuery, authObject->getPayload()));
    }


    //录入工作状态接口描述
    ENDPOINT_INFO(addBaWorkSt) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ba_work_st.post.summary"));
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    //录入工作状态接口处理
    ENDPOINT("POST", "/ops/add-ops", addBaWorkSt, BODY_DTO(BaWorkStAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execAddBaWorkSt(dto, authObject->getPayload()));
    }

    // 3.1 定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ba_work_st.put.summary"), modifyBaWorkSt, StringJsonVO::Wrapper);
    // 3.2 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH("PUT", "/ops/modify-ops", modifyBaWorkSt, BODY_DTO(BaWorkStChangeDTO::Wrapper, dto), execModifyBaWorkSt(dto,authObject->getPayload()));

    ////修改工作状态接口描述
    //ENDPOINT_INFO(updateBaWorkSt) {
    //    info->summary = ZH_WORDS_GETTER("ba_work_st.put.summary");
    //}
    ////修改工作状态接口处理
    //ENDPOINT("PUT", "/BaWorkSt", updateBaWorkSt) {
    //    return createResponse(Status::CODE_200, "success!");
    //}

private:
    //分页查询工作状态
    BaWorkStPageJsonVO::Wrapper execQueryBaWorkSt(const BaWorkStQuery::Wrapper& query, const PayloadDTO& payload);
    //修改工作状态
    StringJsonVO::Wrapper execModifyBaWorkSt(const BaWorkStChangeDTO::Wrapper& dto, const PayloadDTO& payload);
    //录入工作状态
    StringJsonVO::Wrapper execAddBaWorkSt(const BaWorkStAddDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section