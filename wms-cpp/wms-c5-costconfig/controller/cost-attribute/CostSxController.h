#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: todou
 @Date: 2022/10/25 0:27:04

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

#ifndef _COSTSX_CONTROLLER_
#define _COSTSX_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/cost-attribute/CostSxQuery.h"
#include "domain/dto/cost-attribute/CostSxDTO.h"
#include "domain/vo/cost-attribute/CostSxVO.h"
#include "iostream"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 客户计费属性
 */
class CostSxController : public oatpp::web::server::api::ApiController // 1 继承控制器
{

	API_ACCESS_DECLARE(CostSxController);

public:

	// 查询客户属性名称接口描述
	ENDPOINT_INFO(queryCostSxName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.queryName"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CostSxNameListPageJsonVO);

		

		// 客户属性编码
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("CostSxQuery.filed.code"), ZH_WORDS_GETTER("CostSxMethod.example.add.code"), false);

		// 客户属性名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("CostSxQuery.filed.name"), ZH_WORDS_GETTER("CostSxMethod.example.add.name"), false);

		// 创建人名称
		API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("CostSxQuery.filed.create_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_name"), false);

		// 创建人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "createBy", ZH_WORDS_GETTER("CostSxQuery.filed.create_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_by"), false);

		//// 创建日期
		//API_DEF_ADD_QUERY_PARAMS(String, "createDate", ZH_WORDS_GETTER("CostSxQuery.filed.create_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_date"), false);

		// 更新人名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("CostSxQuery.filed.update_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_name"), false);

		// 更新人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateBy", ZH_WORDS_GETTER("CostSxQuery.filed.update_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_by"), false);

		//// 更新日期
		//API_DEF_ADD_QUERY_PARAMS(String, "updateDate", ZH_WORDS_GETTER("CostSxQuery.filed.update_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_date"), false);

		// 所属部门
		API_DEF_ADD_QUERY_PARAMS(String, "sysOrgCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_org_code"), false);

		// 所属公司
		API_DEF_ADD_QUERY_PARAMS(String, "sysCompanyCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_company_code"), false);

	}
	// 查询客户属性名称接口定义
	// 这个理论上就是下拉查看属性名称吧 ??? 那不需要什么其它的查询条件 ?
	ENDPOINT(API_M_GET, "/cost-config/query-cost-attribute-name", queryCostSxName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(costSxQuery, CostSxQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySxName(costSxQuery));
	}

	//// 查询客户详细属性（分页）接口描述
	ENDPOINT_INFO(queryCostSxPage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.queryPage"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CostSxPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 客户属性编码
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("CostSxQuery.filed.code"), ZH_WORDS_GETTER("CostSxMethod.example.add.code"), false);

		// 客户属性名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("CostSxQuery.filed.name"), ZH_WORDS_GETTER("CostSxMethod.example.add.name"), false);

		// 创建人名称
		API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("CostSxQuery.filed.create_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_name"), false);

		// 创建人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "createBy", ZH_WORDS_GETTER("CostSxQuery.filed.create_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_by"), false);

		//// 创建日期
		//API_DEF_ADD_QUERY_PARAMS(String, "createDate", ZH_WORDS_GETTER("CostSxQuery.filed.create_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.create_date"), false);

		// 更新人名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("CostSxQuery.filed.update_name"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_name"), false);

		// 更新人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateBy", ZH_WORDS_GETTER("CostSxQuery.filed.update_by"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_by"), false);

		//// 更新日期
		//API_DEF_ADD_QUERY_PARAMS(String, "updateDate", ZH_WORDS_GETTER("CostSxQuery.filed.update_date"), ZH_WORDS_GETTER("CostSxMethod.example.add.update_date"), false);

		// 所属部门
		API_DEF_ADD_QUERY_PARAMS(String, "sysOrgCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_org_code"), false);

		// 所属公司
		API_DEF_ADD_QUERY_PARAMS(String, "sysCompanyCode", ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"), ZH_WORDS_GETTER("CostSxMethod.example.add.sys_company_code"), false);
	}
	// 查询客户属性(分页)接口定义
	ENDPOINT(API_M_GET, "/cost-config/query-cost-attribute-page", queryCostSxPage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(costSxQuery, CostSxQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySxPage(costSxQuery));
	}
	// 
	// 新增客户属性接口描述
	ENDPOINT_INFO(addCostSx) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式 
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
	// 新增客户属性接口处理
	ENDPOINT(API_M_POST, "/cost-config/add-cost-attribute", addCostSx, BODY_DTO(CostSxBaseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		CostSxAddDTO::Wrapper adto = buildFullDTO(dto, authObject.get()->getPayload());
		API_HANDLER_RESP_VO(execAddCostSx(adto));
	}


	// 修改客户属性接口描述
	ENDPOINT_INFO(modifyCostSx) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("CostSxMethod.modify"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式 
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
	// 修改客户属性接口处理
	ENDPOINT(API_M_PUT, "/cost-config/update-cost-attribute", modifyCostSx, BODY_DTO(CostSxBaseModifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		//呼叫执行函数响应结果
	   // 如果没有任何字段得到修改会返回错误
		CostSxModifyDTO::Wrapper mdto = buildFullDTO(dto, authObject.get()->getPayload());

		API_HANDLER_RESP_VO(execModifyCostSx(mdto));
	};

private:

	// 新增用户属性接口处理
	StringJsonVO::Wrapper execAddCostSx(const CostSxAddDTO::Wrapper&);
	// 修改用户属性接口处理
	StringJsonVO::Wrapper execModifyCostSx(const CostSxModifyDTO::Wrapper&);
	// 查询用户属性名称接口处理
	CostSxNameListPageJsonVO::Wrapper execQuerySxName(const CostSxQuery::Wrapper&);
	// 查询用户属性(分页)接口处理
	CostSxPageJsonVO::Wrapper execQuerySxPage(const CostSxQuery::Wrapper&);

	// 辅助方法：组装完整DTO
	CostSxModifyDTO::Wrapper buildFullDTO(const CostSxBaseModifyDTO::Wrapper& baseDto, const PayloadDTO& payload);
	CostSxAddDTO::Wrapper buildFullDTO(const CostSxBaseAddDTO::Wrapper& baseDto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 
