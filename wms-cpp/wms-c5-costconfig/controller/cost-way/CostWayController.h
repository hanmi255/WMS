#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/05/17 11:37:57

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
#ifndef _COSTWAY_CONTROLLER_
#define _COSTWAY_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/cost-way/DeleteQuery.h"
#include "domain/dto/cost-way/DeleteDTO.h"
#include "domain/vo/cost-way/DeleteVO.h"
#include "domain/vo/cost-way/DownloadExcelVO.h"
#include "domain/vo/cost-way/UploadExcelVO.h"
#include<list>
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 客户计费方式-删除计费方式
 */
class DeleteController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteController);
	// 3 定义接口
public:
	//// 3.1 定义删除接口描述
	//ENDPOINT_INFO(waydelete) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost-way.delete"), StringJsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("cost-way.id"), 1, true);
	//}
	//// 3.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL,"/delete/{id}", waydelete, PATH(String, id), execwaydelete(id));


	// 定义删除客户计费属性接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost-way.deleteall"), deleteCostway, DeleteJsonVO::Wrapper);
	// 定义删除客户计费属性接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-config/cost-way/delete-way", deleteCostway, BODY_DTO(oatpp::List<String>, ids), execDeleteCostway(ids));
	// 3.1 定义批量接口描述
	
	// 3.2 定义删除接口处理
private:


	// 3.3 删除数据
	//StringJsonVO::Wrapper execwaydelete(const String& id);
	StringJsonVO::Wrapper execDeleteCostway(const oatpp::List<String>&ids);

};

//定义excel下载接口
class DownloadExcelController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DownloadExcelController);
public:
	// 计费方式excel下载接口
		// 定义描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("file.field.download"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.excel-filename"), "test.xlsx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cost-config/cost-way/excel-download", downloadFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		
		return execDownloadFile(filename);
	}
private:
	// 执行excel文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

//定义excel上传接口
class UploadExcelController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(UploadExcelController);
public:
	// 定义一个单文件上传接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.field.upload"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/cost-config/cost-way/excel-upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));
private: // 定义接口执行函数
	// 执行单文件上传处理
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 