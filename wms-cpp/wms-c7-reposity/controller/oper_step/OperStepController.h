/*
/*@File Name         : OperStepController.h                                                     
/*@Author            : 智商局局长
/*@Description       :
*/

#ifndef _OPERSTEP_CONTROLLER_
#define _OPERSTEP_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/oper_step/OperStepVO.h"
#include "domain/dto/oper_step/OperStepDTO.h"
#include "ApiHelper.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Code gen

class OperStepController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OperStepController);
public:
	//修改接口
	ENDPOINT_INFO(modifyOperStep) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("business-link.del.delete"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PATH_PARAMS(String, "ID", ZH_WORDS_GETTER("business-link.field.ID"), "001", true);
		API_DEF_ADD_PATH_PARAMS(String, "update_name", ZH_WORDS_GETTER("business-link.field.update-name"), "001", true);
        API_DEF_ADD_PATH_PARAMS(String, "update_by", ZH_WORDS_GETTER("business-link.field.update-by"), "001", true);
        API_DEF_ADD_PATH_PARAMS(String, "update_date", ZH_WORDS_GETTER("business-link.field.update-date"), "001", true);
        API_DEF_ADD_PATH_PARAMS(String, "oper_step_code", ZH_WORDS_GETTER("business-link.field.oper-step-code"), "001", true);
        API_DEF_ADD_PATH_PARAMS(String, "oper_step_name", ZH_WORDS_GETTER("business-link.field.oper-step-name"), "001", true);
        API_DEF_ADD_PATH_PARAMS(String, "sys_org_code", ZH_WORDS_GETTER("business-link.field.sys-org-code"), "001", true);
        API_DEF_ADD_PATH_PARAMS(String, "sys_company_code", ZH_WORDS_GETTER("business-link.field.sys-company-code"), "001", true);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH("PUT", "/repository/operstep/modify", modifyOperStep, BODY_DTO(OperStepDTO::Wrapper, dto), execModifyOperStep(dto, authObject->getPayload()));

	// 删除接口
	ENDPOINT_INFO(deleteOperStep) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("business-link.del.delete"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PATH_PARAMS(String, "ID", ZH_WORDS_GETTER("business-link.field.ID"), "001", true);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_DEL, "/OperStep/delete", deleteOperStep, BODY_DTO(OperStepDeleteDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteOperStep(dto, authObject->getPayload()));
	}

	// 上传接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("business-link.post.import"), uploadExcel, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH("POST", "/repository/operstep/uploadexcel", uploadExcel, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadExcel(request, authObject->getPayload()));

	// 文件下载接口
	// 定义描述
	ENDPOINT_INFO(exportExcel) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("business-link.get.export"),Void);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/repository/operstep/exportexcel", exportExcel) {
		return execExportExcel();
	};



private:

	StringJsonVO::Wrapper execModifyOperStep(const OperStepDTO::Wrapper& dto, const PayloadDTO& payload);

	StringJsonVO::Wrapper execDeleteOperStep(const OperStepDeleteDTO::Wrapper& dto, const PayloadDTO& payload);

	StringJsonVO::Wrapper execUploadExcel(const std::shared_ptr<IncomingRequest>& request, const PayloadDTO& payload);

	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportExcel();
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Code gen
#endif // _OPERSTEP_CONTROLLER_