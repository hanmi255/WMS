#pragma once

#ifndef _BILLING_NAME_CONTROLLER_
#define _BILLING_NAME_CONTROLLER_


#include "../../domain/dto/billing-name/BillingNameDTO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"

#include "../../domain/query/billing-name/BillingNameQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 费用名称控制器，演示费用名称相关接口的使用
 */
class BillingNameController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(BillingNameController);

public:
    //批量删除
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(batchdeleteBillingName) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("billing-name.delete.batchdelete"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("billing-name.delete.id"), "123456", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/billing-name/batch-delete/{id}", batchdeleteBillingName, BODY_DTO(BillingNameBatchDTO::Wrapper, bathdto), execbatchdeleteBillingName(bathdto));
  
    
    
    //
    ///*导出费用名称--*/
    ENDPOINT_INFO(exportBillingName) {
    //    // 定义接口标题
       API_DEF_ADD_TITLE(ZH_WORDS_GETTER("billing-name.filedownload.excel"));
       API_DEF_ADD_AUTH();
    //    // 定义响应参数格式
       API_DEF_ADD_QUERY_PARAMS(String, "cost_code", ZH_WORDS_GETTER("billing-name.field.cost_code"), "123456", false);
       API_DEF_ADD_QUERY_PARAMS(String, "cost_name", ZH_WORDS_GETTER("billing-name.field.cost_name"), "123456", false);
       API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("billing-name.field.cost_type_code"), "123456", false);
    }
    //// 定义端点
    ENDPOINT(API_M_GET, "/billing-name/download", exportBillingName, QUERIES(QueryParams, exportParams), API_HANDLER_AUTH_PARAME) {
    //    // 解析查询参数为ExportGoodsDiffPostQuery领域模型
       API_HANDLER_QUERY_PARAM(exportQuery, BillingNameQuery, exportParams);
    //    // 呼叫执行函数响应结果

       return execExportName(exportQuery);
    }
    //导入费用名称
    ENDPOINT_INFO(uploadBillingName) {
        //    // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("billing-name.fileupload.excel"));
        API_DEF_ADD_AUTH();
    }
    
    API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/billing-name/upload", uploadBillingName, REQUEST(std::shared_ptr<IncomingRequest>, request), execuploadName(request));

 
private:
	StringJsonVO::Wrapper execbatchdeleteBillingName(const BillingNameBatchDTO::Wrapper& bathdto);
    std::shared_ptr<OutgoingResponse> execExportName(const BillingNameQuery::Wrapper& query);
    StringJsonVO::Wrapper execuploadName(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COST_NAME_CONTROLLER_