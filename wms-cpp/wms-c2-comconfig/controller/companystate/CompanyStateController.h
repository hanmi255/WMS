#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/2/22 21:02:41

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _COMPANYSTATE_CONTROLLER_
#define _COMPANYSTATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/companystate/CompanyStateDTO.h"
#include "domain/vo/companystate/CompanyStateVO.h"
#include "service/companystate/CompanyStateService.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CompanyStateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CompanyStateController);
	// 3 定义接口
public:
	// 3.1 定义企业信息录入接口描述
	ENDPOINT_INFO(addCompanyState) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("companystate.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyStateJsonVO);
	}
	// 3.2 定义企业信息录入接口处理
	ENDPOINT(API_M_POST, "/comstate/add-state", addCompanyState, BODY_DTO(CompanyAddStateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCompanyInfo(dto, authObject->getPayload()));
	}

	// 3.1 定义企业信息修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("companystate.modify"), modifyCompanyState, CompanyStateJsonVO::Wrapper);
	// 3.2 定义企业信息修改接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cominfo/modify-info", modifyCompanyInfo, BODY_DTO(CompanyInfoDTO::Wrapper, dto), execModifyCompanyInfo(dto, authObject->getPayload()));
	ENDPOINT(API_M_PUT, "/comstate/modify-state", modifyCompanyState, BODY_DTO(CompanyUpdateStateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifyCompanyInfo(dto, authObject->getPayload()));
	}

	// 3.1 定义企业信息删除接口描述
	ENDPOINT_INFO(removeCompanyState) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("companystate.delete"), CompanyStateJsonVO::Wrapper);
		// 定义其他路径参数说明
//		API_DEF_ADD_PATH_PARAMS(UInt64, "ids", ZH_WORDS_GETTER("companyinfo.companyId"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/comstate/remove-state/{id}", removeCompanyState, BODY_DTO(CompanyRemoveStateDTO::Wrapper, id), execRemoveCompanyInfo(id));
private:
	// 3.3 演示企业信息录入数据
	CompanyStateJsonVO::Wrapper execAddCompanyInfo(const CompanyAddStateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示企业信息录修改数据
	CompanyStateJsonVO::Wrapper execModifyCompanyInfo(const CompanyUpdateStateDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示企业信息录删除数据
	CompanyStateJsonVO::Wrapper execRemoveCompanyInfo(const CompanyRemoveStateDTO::Wrapper& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COMPANYINFO_CONTROLLER_