#pragma once

#ifndef _CHUWEI_CONTROLLER_
#define _CHUWEI_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/chuweidingyi/ChuWeiVO.h"
#include "domain/query/chuweidingyi/ChuWeiQuery.h"
#include "domain/dto/chuweidingyi/ChuWeiDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class ChuWeiController : public oatpp::web::server::api::ApiController {//继承控制器
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ChuWeiController);
	// 定义接口
public:
	//[获取储位列表（条件+分页）]接口描述
	ENDPOINT_INFO(queryChuwei) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Chuwei.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ChuWeiPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("Chuwei.field.bin_store"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("Chuwei.field.ku_wei_bian_ma"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_tiao_ma", ZH_WORDS_GETTER("Chuwei.field.ku_wei_tiao_ma"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_lei_xing", ZH_WORDS_GETTER("Chuwei.field.ku_wei_lei_xing"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xnode", ZH_WORDS_GETTER("Chuwei.field.xnode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ynode", ZH_WORDS_GETTER("Chuwei.field.ynode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "znode", ZH_WORDS_GETTER("Chuwei.field.znode"), "", false);
	}

	// [储位分页查询]接口处理
	ENDPOINT(API_M_GET, "/chuweiguanli/chuweidingyi/query-chuwei", queryChuwei, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(chuweiQuery, ChuWeiQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryChuwei(chuweiQuery, authObject->getPayload()));
	}


	// [储位修改]接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Chuwei.modify.summary"), modifyChuwei, StringJsonVO::Wrapper);
	// [储位修改]接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/chuweiguanli/chuweidingyi/modify-chuwei", modifyChuwei, BODY_DTO(ChuWeiDTO::Wrapper, dto), execModifyChuwei(dto));

	//[删除储位]接口描述
	ENDPOINT_INFO(removeChuwei) {	
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Chuwei.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	// [删除储位]接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/chuweidingyi/delect-chuwei/{id}", removeChuwei, PATH(String, id), execRemoveChuwei(id));

	// [批量删除储位]接口描述
	ENDPOINT_INFO(batchRemoveChuwei) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Chuwei.delete.batch_summary"), StringJsonVO::Wrapper);
		info->addConsumes<Object<BatchDeleteDTO>>("application/json"); // 显式声明请求体
	}
	// [批量删除储位]接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/chuweidingyi/batch-delete-chuwei", batchRemoveChuwei,
		BODY_DTO(BatchDeleteDTO::Wrapper, dto), execBatchRemoveChuwei(dto));


private:
	//分页查询储位数据
	ChuWeiPageJsonVO::Wrapper execQueryChuwei(const ChuWeiQuery::Wrapper& query, const PayloadDTO& payload);
	//储位修改数据
	StringJsonVO::Wrapper execModifyChuwei(const ChuWeiDTO::Wrapper& dto);
	//储位删除数据
	StringJsonVO::Wrapper execRemoveChuwei(const String& id);
	StringJsonVO::Wrapper execBatchRemoveChuwei(const BatchDeleteDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // _CHUWEI_CONTROLLER_