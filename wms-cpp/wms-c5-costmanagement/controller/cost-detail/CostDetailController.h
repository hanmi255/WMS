#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/2/27 22:17

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
#ifndef _COST_DETAIL_CONTROLLER_
#define _COST_DETAIL_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cost-detail/CostDetailDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CostDetailController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CostDetailController);
	// 3 定义接口
public:
	//1.1批量收款接口描述
	ENDPOINT_INFO(chargeCost) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost-detail.charge.summary"), StringJsonVO::Wrapper);
	}
	//1.2批量收款接口(支持多个数据)
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-management/cost-detail/charge-by-ids", chargeCost, BODY_DTO(List<String>, ids), execChargeCost(ids));

	//2.1批量取消收款接口描述
	ENDPOINT_INFO(dischargeCost) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost-detail.discharge.summary"), StringJsonVO::Wrapper);
	}
	//2.2批量收款接口(支持多个数据)
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-management/cost-detail/discharge-by-ids", dischargeCost, BODY_DTO(List<String>, ids), execDischargeCost(ids));

	//3.1导出费用明细接口描述(文件服务器下载)
	ENDPOINT_INFO(downloadCostDetail) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("cost-detail.download.summary"), Void);
	}
	//3.2导出费用明细接口(文件服务器下载)
	ENDPOINT(API_M_POST, "/cost-management/cost-detail/download", downloadCostDetail,BODY_DTO(List<String>,ids)) {
		return execDownloadCostDetail(ids);
	}

	//4.1导入费用明细接口描述(文件服务器上传)
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost-detail.upload.summary"), uploadCostDetail, StringJsonVO::Wrapper);
	//4.2导入费用明细接口描述(文件服务器上传,目前是单个文件)
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/cost-management/cost-detail/upload", uploadCostDetail, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadCostDetail(request, authObject->getPayload()));

private:
	//1.3批量收款实现
	StringJsonVO::Wrapper execChargeCost(List<String> ids);
	//2.3批量取消收款实现
	StringJsonVO::Wrapper execDischargeCost(List<String> ids);
	//3.3导出费用明细实现
	std::shared_ptr<OutgoingResponse> execDownloadCostDetail(const List<String>& ids);
	//4.3导入费用明细实现
	StringJsonVO::Wrapper execUploadCostDetail(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COST_DETAIL_CONTROLLER_!