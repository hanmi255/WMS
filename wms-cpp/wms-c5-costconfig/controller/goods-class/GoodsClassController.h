#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/2/23 17:46
 
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

#ifndef _GOODSCLASS_CONTROLLER_
#define _GOODSCLASS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/goods-class/GoodsClassQuery.h"
#include "domain/dto/goods-class/GoodsClassDTO.h"
#include "domain/vo/goods-class/GoodsClassVO.h"
#include "iostream"


// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


/**
 * 计费商品类
 */
class GoodsClassController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GoodsClassController);
	// 定义接口
public:

	// 查询计费商品类名称接口描述
	ENDPOINT_INFO(queryGoodsClassName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goodsclass.query-name.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GoodsClassNameListPageJsonVO);

		//// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();


		// 计费商品类编码
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("goodsclass.filed.code"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.code"), false);

		// 计费商品类名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("goodsclass.filed.name"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.name"), false);

		// 创建人名称
		API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("goodsclass.filed.create_name"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.create_name"), false);

		// 创建人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "createBy", ZH_WORDS_GETTER("goodsclass.filed.create_by"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.create_by"), false);

		//// 创建日期
		//API_DEF_ADD_QUERY_PARAMS(String, "createDate", ZH_WORDS_GETTER("goodsclass.filed.create_date"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.create_date"), false);

		// 更新人名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("goodsclass.filed.update_name"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.update_name"), false);

		// 更新人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateBy", ZH_WORDS_GETTER("goodsclass.filed.update_by"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.update_by"), false);

		//// 更新日期
		//API_DEF_ADD_QUERY_PARAMS(String, "updateDate", ZH_WORDS_GETTER("goodsclass.filed.update_date"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.update_date"), false);

		// 所属部门
		API_DEF_ADD_QUERY_PARAMS(String, "sysOrgCode", ZH_WORDS_GETTER("goodsclass.filed.sys_org_code"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.sys_org_code"), false);

		// 所属公司
		API_DEF_ADD_QUERY_PARAMS(String, "sysCompanyCode", ZH_WORDS_GETTER("goodsclass.filed.sys_company_code"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.sys_company_code"), false);


	}
	// 查询计费商品类名称接口定义
	ENDPOINT(API_M_GET, "/cost-config/goods-class/query-goods-class-name", queryGoodsClassName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(goodClassQuery, GoodClassQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGoodClassName(goodClassQuery));
	}


	// 查询计费商品类（分页）接口描述
	ENDPOINT_INFO(queryGoodsClassPage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goodsclass.query-page.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GoodsClassPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();


		// 计费商品类编码
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("goodsclass.filed.code"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.code"), false);

		// 计费商品类名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("goodsclass.filed.name"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.name"), false);

		// 创建人名称
		API_DEF_ADD_QUERY_PARAMS(String, "createName", ZH_WORDS_GETTER("goodsclass.filed.create_name"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.create_name"), false);

		// 创建人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "createBy", ZH_WORDS_GETTER("goodsclass.filed.create_by"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.create_by"), false);

		//// 创建日期
		//API_DEF_ADD_QUERY_PARAMS(String, "createDate", ZH_WORDS_GETTER("goodsclass.filed.create_date"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.create_date"), false);

		// 更新人名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateName", ZH_WORDS_GETTER("goodsclass.filed.update_name"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.update_name"), false);

		// 更新人登录名称
		API_DEF_ADD_QUERY_PARAMS(String, "updateBy", ZH_WORDS_GETTER("goodsclass.filed.update_by"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.update_by"), false);

		//// 更新日期
		//API_DEF_ADD_QUERY_PARAMS(String, "updateDate", ZH_WORDS_GETTER("goodsclass.filed.update_date"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.update_date"), false);

		// 所属部门
		API_DEF_ADD_QUERY_PARAMS(String, "sysOrgCode", ZH_WORDS_GETTER("goodsclass.filed.sys_org_code"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.sys_org_code"), false);

		// 所属公司
		API_DEF_ADD_QUERY_PARAMS(String, "sysCompanyCode", ZH_WORDS_GETTER("goodsclass.filed.sys_company_code"), ZH_WORDS_GETTER("GoodsClassMethod.example.add.sys_company_code"), false);

	}
	// 查询计费商品类名称接口定义
	ENDPOINT(API_M_GET, "/cost-config/goods-class/query-goods-class-page", queryGoodsClassPage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(goodClassQuery, GoodClassQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGoodClassPage(goodClassQuery));
	}


	// 新增计费商品类接口描述
	ENDPOINT_INFO(addGoodsClass) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goodsclass.post.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式 
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 新增计费商品类接口处理
	ENDPOINT(API_M_POST, "/cost-config/goods-class/add-goods-class", addGoodsClass, BODY_DTO(GoodsClassBaseAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		GoodsClassAddDTO::Wrapper adto = buildFullDTO(dto, authObject.get()->getPayload());
		API_HANDLER_RESP_VO(execAddGoodsClass(adto));
	}


	// 修改计费商品类接口描述
	ENDPOINT_INFO(modifyGoodsClass) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goodsclass.put.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式 
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 修改计费商品类接口处理
	ENDPOINT(API_M_PUT, "/cost-config/goods-class/modify-goods-class", modifyGoodsClass, BODY_DTO(GoodsClassBaseModifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		GoodsClassModifyDTO::Wrapper mdto = buildFullDTO(dto, authObject.get()->getPayload());

		API_HANDLER_RESP_VO(execModifyGoodsClass(mdto));
	};

private:
	// 新增计费商品类接口处理
	StringJsonVO::Wrapper execAddGoodsClass(const GoodsClassAddDTO::Wrapper& dto);
	// 修改计费商品类接口处理
	StringJsonVO::Wrapper execModifyGoodsClass(const GoodsClassModifyDTO::Wrapper& dto);
	// 查询计费商品类名称接口处理
	GoodsClassNameListPageJsonVO::Wrapper execQueryGoodClassName(const GoodClassQuery::Wrapper& dto);
	// 查询计费商品类(分页)接口处理
	GoodsClassPageJsonVO::Wrapper execQueryGoodClassPage(const GoodClassQuery::Wrapper& query);

	// 辅助方法：组装完整DTO
	GoodsClassModifyDTO::Wrapper buildFullDTO(const GoodsClassBaseModifyDTO::Wrapper& baseDto, const PayloadDTO& payload);
	GoodsClassAddDTO::Wrapper buildFullDTO(const GoodsClassBaseAddDTO::Wrapper& baseDto, const PayloadDTO& payload);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GOODSCLASS_CONTROLLER_