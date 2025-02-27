#pragma once

#ifndef _CHUWEI_CONTROLLER_
#define _CHUWEI_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/chuweidingyi/ChuWeiVO.h"
#include "domain/query/chuweidingyi/ChuWeiQuery.h"
#include "domain/dto/chuweidingyi/QueryCWDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class ChuWeiController : public oatpp::web::server::api::ApiController {//继承控制器
	//定义控制器访问入口
	API_ACCESS_DECLARE(ChuWeiController);
	//定义接口
public:
	//[获取储位列表（条件+分页）]接口描述
	ENDPOINT_INFO(queryChuwei) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("chuwei.get.summary"));
		//定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ChuWeiPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "store", ZH_WORDS_GETTER("chuwei.field.store"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_code", ZH_WORDS_GETTER("chuwei.field.store_code"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_barcode", ZH_WORDS_GETTER("chuwei.field.store_barcode"), "xxx", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "store_type", ZH_WORDS_GETTER("chuwei.field.store_type"), "是/否", false);   下拉选择实现？
		API_DEF_ADD_QUERY_PARAMS(String, "x_axis", ZH_WORDS_GETTER("chuwei.field.x_axis"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "y_axis", ZH_WORDS_GETTER("chuwei.field.y_axis"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "z_axis", ZH_WORDS_GETTER("chuwei.field.z_axis"), "N", false);
	}

	// [储位分页查询]接口处理
	ENDPOINT(API_M_GET, "/chuweiguanli/chuweidingyi/query-chuwei", queryChuwei, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(chuweiQuery, ChuWeiQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryChuwei(chuweiQuery, authObject->getPayload()));
	}



	// [储位修改]接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("chuwei.modify.summary"), modifyChuwei, Uint64JsonVO::Wrapper);
	// [储位修改]接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/chuweiguanli/chuweidingyi/modify-chuwei", modifyChuwei, BODY_DTO(ChuWeiDTO::Wrapper, dto), execModifyChuwei(dto));

	//[删除储位]接口描述
	ENDPOINT_INFO(removeChuwei) {	
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("chuwei.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);

	}
	// [删除储位]接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/chuweidingyi/delect-chuwei/{id}", removeChuwei, PATH(String, id), execRemoveChuwei(id));


private:
	//分页查询储位数据
	ChuWeiPageJsonVO::Wrapper ChuWeiController::execQueryChuwei(const ChuWeiQuery::Wrapper& query, const PayloadDTO& payload);
	//储位修改数据
	Uint64JsonVO::Wrapper ChuWeiController::execModifyChuwei(const ChuWeiDTO::Wrapper& dto);
	//储位删除数据
	Uint64JsonVO::Wrapper ChuWeiController::execRemoveChuwei(const String& id);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // _CHUWEI_CONTROLLER_