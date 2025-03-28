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
#ifndef _COMPANYINFO_CONTROLLER_
#define _COMPANYINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/companyinfo/CompanyInfoDTO.h"
#include "domain/vo/companyinfo/CompanyInfoVO.h"
#include "service/companyinfo/CompanyInfoService.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CompanyInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CompanyInfoController);
	// 3 定义接口
public:
	// 3.1 定义企业信息录入接口描述
	ENDPOINT_INFO(addCompanyInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("companyinfo.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyInfoJsonVO);
	}
	// 3.2 定义企业信息录入接口处理
	ENDPOINT(API_M_POST, "/cominfo/add-info", addCompanyInfo, BODY_DTO(CompanyAddInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCompanyInfo(dto, authObject->getPayload()));
	}

	// 3.1 定义企业信息修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("companyinfo.modify"), modifyCompanyInfo, CompanyInfoJsonVO::Wrapper);
	// 3.2 定义企业信息修改接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cominfo/modify-info", modifyCompanyInfo, BODY_DTO(CompanyInfoDTO::Wrapper, dto), execModifyCompanyInfo(dto, authObject->getPayload()));
	ENDPOINT(API_M_PUT, "/cominfo/modify-info", modifyCompanyInfo, BODY_DTO(CompanyUpdateInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifyCompanyInfo(dto, authObject->getPayload()));
	}

	// 3.1 定义企业信息删除接口描述
	ENDPOINT_INFO(removeCompanyInfo) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("companyinfo.delete"), CompanyInfoJsonVO::Wrapper);
		// 定义其他路径参数说明
//		API_DEF_ADD_PATH_PARAMS(UInt64, "ids", ZH_WORDS_GETTER("companyinfo.companyId"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cominfo/remove-info/{id}", removeCompanyInfo, BODY_DTO(CompanyRemoveInfoDTO::Wrapper, id), execRemoveCompanyInfo(id));
private:
	// 3.3 演示企业信息录入数据
	CompanyInfoJsonVO::Wrapper execAddCompanyInfo(const CompanyAddInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示企业信息录修改数据
	CompanyInfoJsonVO::Wrapper execModifyCompanyInfo(const CompanyUpdateInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示企业信息录删除数据
	CompanyInfoJsonVO::Wrapper execRemoveCompanyInfo(const CompanyRemoveInfoDTO::Wrapper& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COMPANYINFO_CONTROLLER_