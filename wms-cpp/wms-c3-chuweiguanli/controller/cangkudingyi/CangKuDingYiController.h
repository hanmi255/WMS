#pragma once

#ifndef _CANGKUDINGYICONTROLLER_H_
#define _CANGKUDINGYICONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/cangkudingyi/CangkuNameListDTO.h"
#include "domain/dto/cangkudingyi/CangkuListDTO.h"
#include "domain/query/cangkudingyi/CangkuListQuery.h"
#include "domain/dto/cangkudingyi/deleteCangkuDTO.h"
#include "domain/vo/cangkudingyi/CangkuVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CangKuDingYiController : public oatpp::web::server::api::ApiController
{
	//	定义控制器访问入口
	API_ACCESS_DECLARE(CangKuDingYiController);

	//  定义接口
public:

	//	定义获取仓库名称列表接口描述
	ENDPOINT_INFO(listCangkuName) {
		//	定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.get_cangku_name_list"));
		//	定义默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CangkuNameListJsonVO);
	}
	//	定义 获取仓库名称列表接口 处理
	ENDPOINT(API_M_GET, "/chuweiguanli/cangkudingyi/query-cangku-name-list", listCangkuName, API_HANDLER_AUTH_PARAME) {
		//	呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execListCangkuName(authObject->getPayload()));
	}

	//	定义 删除仓库 接口描述
	ENDPOINT_INFO(deleteCangku) {
		//	定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.summary"));
		//	定义默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		////	定义参数：仓库ID列表
		//API_DEF_ADD_PATH_PARAMS(oatpp::List<UInt64>, "id_list", ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.params.ids"), 10086, false);

	}
	//	定义 删除仓库 接口 处理
	ENDPOINT(API_M_DEL, "/chuweiguanli/cangkudingyi/delete-cangku-by-id", deleteCangku, BODY_DTO(DeleteCangkuDTO::Wrapper, id_list), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteCangku(id_list, authObject->getPayload()));
	}

	//	定义 导出仓库接口 描述
	ENDPOINT_INFO(downLoadCangkuExcel) {
		//	定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.summary"));
		//	定义默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//	定义参数：仓库代码

		//API_DEF_ADD_QUERY_PARAMS(oatpp::String, "store_code", ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.params.store_code"), "001-FKD", false);
	}
	//	定义 导出仓库接口 处理

	ENDPOINT(API_M_GET, "/chuweiguanli/cangkudingyi/down-load-cangku-excel", downLoadCangkuExcel, BODY_DTO(ExportCangkuDTO::Wrapper, store_code_list), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDownLoadCangkuExcel(store_code_list, authObject->getPayload()));
	}

	//	定义 获取仓库列表接口 描述
	ENDPOINT_INFO(listCangku)
	{
		//	定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.get_cangku_list"));

		//	定义默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式

		API_DEF_ADD_RSP_JSON_WRAPPER(CangkuListPageJsonVO);
		//	请求参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "store_code", ZH_WORDS_GETTER("store.store_code"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_name", ZH_WORDS_GETTER("store.store_name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_text", ZH_WORDS_GETTER("store.store_text"), "xxx", false);
	}

	//	定义 获取仓库列表接口 处理

	ENDPOINT(API_M_GET, "/chuweiguanli/query-cangku-list", listCangku, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(cangkulistQuery, CangkuListQuery, queryParams);
		//	呼叫执行函数响应结果

		API_HANDLER_RESP_VO(execListCangku(cangkulistQuery, authObject->getPayload()));
	}


	// 定义 导入仓库 描述
	ENDPOINT_INFO(upload)
	{
		//	定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.up_load_cangku_excel.summary"));
		//	定义默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义 导入仓库 端点
	ENDPOINT(API_M_POST, "/chuweiguanli/cangkudingyi/upload", upload, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execUpload(request));
	}
private:
	//	获取仓库名称列表执行函数
	CangkuNameListJsonVO::Wrapper execListCangkuName(const PayloadDTO& payload);
	//	删除仓库执行函数
	StringJsonVO::Wrapper execDeleteCangku(const DeleteCangkuDTO::Wrapper& id_list, const PayloadDTO& payload);
	//	导出仓库执行函数

	StringJsonVO::Wrapper execDownLoadCangkuExcel(const ExportCangkuDTO::Wrapper& store_code_list, const PayloadDTO& payload);
	//	获取仓库列表执行函数

	CangkuListPageJsonVO::Wrapper execListCangku(const CangkuListQuery::Wrapper& query, const PayloadDTO& payload);
	// 导入仓库执行函数
	StringJsonVO::Wrapper execUpload(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)



#endif // _CANGKUDINGYICONTROLLER_H_
