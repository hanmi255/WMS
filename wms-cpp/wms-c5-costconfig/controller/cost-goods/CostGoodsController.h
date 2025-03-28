//#pragma once
///*
// Copyright Zero One Star. All rights reserved.
//
// @Author: Jane
// @Date: 2025/02/26 11:19:05
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	  https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*/
//#ifndef _COSTGOODSCONTROLLER_H_
//#define _COSTGOODSCONTROLLER_H_
//
//#include "domain/vo/BaseJsonVO.h"
//#include "ApiHelper.h"
//#include "ServerInfo.h"
//#include "domain/query/cost-goods/BillingProductCategoryQuery.h"
//#include "domain/dto/cost-goods/CostGoodsDTO.h"
//#include "domain/vo/cost-goods/CostGoodsVO.h"
//#include <service/cost-goods/CostGoodsService.h>
//
//// 0 定义API控制器使用宏
//#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
//
///**
// * 客户计费方式-删除计费方式
// */
//class CostGoodsController : public oatpp::web::server::api::ApiController // 1 继承控制器
//{
//	// 2 定义控制器访问入口
//	API_ACCESS_DECLARE(CostGoodsController);
//public:
//	// 3.1 定义删除接口描述
//	ENDPOINT_INFO(waydelete) {
//		// 定义标题和返回类型以及授权支持
//		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("CostGoodsQuery.delete.query"), StringJsonVO::Wrapper);
//		// 定义其他路径参数说明
//		API_DEF_ADD_PATH_PARAMS(String, "code", ZH_WORDS_GETTER("CostGoodsQuery.way.code"), "1", true);
//	}
//	// 3.2 定义删除接口处理
//	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-goods/delete/{code}", waydelete, PATH(String, code), execwaydelete(code));
//
//	// 计费方式excel下载接口
//	// 定义描述
//	ENDPOINT_INFO(downloadFile) {
//		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("CostGoodsQuery.file.download"), Void);
//		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.excel-filename"), "excel/test.xlsx", true);
//	}
//	// 定义端点
//	ENDPOINT(API_M_GET, "/cost-goods/file-download", downloadFile, QUERY(String, filename)) {
//		return execDownloadFile(filename);
//	}
//
//	// 定义一个单文件上传接口
//	// 定义描述
//	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("CostGoodsQuery.file.upload"), uploadFile, StringJsonVO::Wrapper);
//	// 定义端点
//	API_HANDLER_ENDPOINT(API_M_POST, "/cost-goods/file-upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));
//
//private:
//	// 3.3 删除数据
//	StringJsonVO::Wrapper execwaydelete(const String& code);
//
//	// 执行excel文件下载处理
//	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
//
//	// 执行单文件上传处理
//	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
//};
//
//// 0 取消API控制器使用宏
//#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
//#endif 
