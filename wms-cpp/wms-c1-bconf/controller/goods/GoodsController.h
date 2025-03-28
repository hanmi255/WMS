#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/02/19 10:53:52

.
*/
#ifndef _GOODSCONTROLLER_H_
#define _GOODSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/goods/GoodsDTO.h"
#include "../../domain/vo/goods/GoodsVo.h"
#include "../../domain/query/goods/GoodsQuery.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetGoodsController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetGoodsController);
public: // 定义接口
	// 查询商品类目名称树
	ENDPOINT_INFO(queryGoods) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goods.get.summary"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GoodsJsonVO);
	}
	ENDPOINT(API_M_GET, "/gc/query-category-tree", queryGoods,API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGoods());
	}

	// 3.1 定义ID查询接口描述
	ENDPOINT_INFO(queryById) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("goods.getbyid.summary"), CombineGoodsJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("goods.id"), 1, false);		// 可以不传参数,不传参数获取一级类目数据
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/gc/query-by-id", queryById, QUERY(Int64, id), execById(id));
	

	// 3.1 定义ID查询接口描述
	ENDPOINT_INFO(queryNoId) {
		// 定义通用描述
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goods.getnoid.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CombineGoodsJsonVO);
	}
	// 3.2 定义ID查询接口处理
	ENDPOINT(API_M_GET, "/gc/query-no-id", queryNoId, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execNoId());
	}


	// 文件上传
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("goods.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/gc/export-categories", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne( request,authObject->getPayload() ) );

	//文件下载
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("goods.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("goods.download.summary2"), "goods_category.xlsx", true);
		API_DEF_ADD_AUTH();
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/gc/import-categories", downloadFile, QUERY(String, filename),API_HANDLER_AUTH_PARAME) {
		return execDownloadFile(filename);
	}

private: // 定义接口执行函数
	CombineGoodsJsonVO::Wrapper execQueryGoods();
	CombineGoodsJsonVO::Wrapper execById(const Int64& id);
	CombineGoodsJsonVO::Wrapper execNoId();
	
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GOODSCONTROLLER_H_