#pragma once  
#ifndef _BAACTTYPE_CONTROLLER_
#define _BAACTTYPE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/ba_act_type/BaActTypeQuery.h"
#include "domain/dto/ba_act_type/BaActTypeDTO.h"
#include "domain/vo/ba_act_type/BaActTypeVO.h"

 // 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * BaActTypeController：用于处理作业类型（BaActType）相关的 API 请求
 */
class BaActTypeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(BaActTypeController);

public:
    // 1 定义查询接口描述
    ENDPOINT_INFO(queryBaActType) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ba_act_type.query-all.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(BaActTypePageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "act_type_name", ZH_WORDS_GETTER("ba_act_type.field.act_type_name"), "Sample Type", false);
    }
    // 1 定义查询接口处理
    ENDPOINT(API_M_GET, "/repository/queryall-baacttype", queryBaActType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为 Query 领域模型
        API_HANDLER_QUERY_PARAM(userQuery, BaActTypeQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryBaActType(userQuery, authObject->getPayload()));
    }

    // 2 定义新增接口描述
    ENDPOINT_INFO(addBaActType) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ba_act_type.add.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 2 定义新增接口处理
    ENDPOINT(API_M_POST, "/repository/add-baacttype", addBaActType, BODY_DTO(BaActTypeAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execAddBaActType(dto));
    }

    // 3 定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ba_act_type.modify.summary"), modifyBaActType, Uint64JsonVO::Wrapper);
    // 3 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/baActType", modifyBaActType, BODY_DTO(BaActTypeDTO::Wrapper, dto), execModifyBaActType(dto));



    // 4 定义删除接口描述
    ENDPOINT_INFO(removeBaActType) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ba_act_type.delete.summary"), Uint64JsonVO::Wrapper);
        // 定义路径参数说明
        API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("ba_act_type.field.id"), 1, true);
    }
    // 4 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/repository/delete-baacttype/{id}", removeBaActType, PATH(String, id), execRemoveBaActType(id));



    // 定义一个单文件上传接口
    // 定义描述
    API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
    // 定义端点
    API_HANDLER_ENDPOINT(API_M_POST, "reposity/upload-baacttypefile", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));




    // 定义一个文件下载接口
// 定义描述
    ENDPOINT_INFO(downloadFile) {
        API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
        API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "test.xlsx", true);
    }
    // 定义端点
    ENDPOINT(API_M_GET, "reposity/download-baacttypefile", downloadFile, QUERY(String, filename)) {
        return execDownloadFile(filename);
    }


 

private:
    // 1 作业类型分页查询数据
    BaActTypePageJsonVO::Wrapper execQueryBaActType(const BaActTypeQuery::Wrapper& query, const PayloadDTO& payload);
    // 2 作业类型新增数据
    Uint64JsonVO::Wrapper execAddBaActType(const BaActTypeAddDTO::Wrapper& dto);
    // 3 作业类型修改数据
    StringJsonVO::Wrapper execModifyBaActType(const BaActTypeDTO::Wrapper& dto);
    // 4 作业类型删除数据
    StringJsonVO::Wrapper execRemoveBaActType(const String& id);
    // 5执行单文件上传处理
    StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest>request);
    // 6执行文件下载处理
    std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _BAACTTYPE_CONTROLLER_
