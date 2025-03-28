#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/08 11:08:56

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
#ifndef _COSTGOODS_SERVICE_
#define _COSTGOODS_SERVICE_
#include <list>
#include "domain/vo/cost-goods/CostGoodsVO.h"
#include "domain/query/cost-goods/BillingProductCategoryQuery.h"
#include "domain/dto/cost-goods/CostGoodsDTO.h"
#include "domain/do/public-do/GoodsClassDO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CostGoodsService
{
public:
	// 通过code删除数据
	bool removeData(string code);

	// 保存数据
	uint64_t saveData(const BPCExcelUploadDTO::Wrapper& dto);
	
	// 查询所有数据
	list<GoodsClassDO> listAll();
};

#endif // !_COSTGOODS_SERVICE_

#pragma once
