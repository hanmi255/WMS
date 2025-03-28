#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

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
#ifndef _DOWNGOODS_SERVICE_
#define _DOWNGOODS_SERVICE_
#include <list>
#include "domain/vo/batch-modify-goods/DownGoodsVO.h"
#include "domain/query/batch-modify-goods/DownGoodsQuery.h"
#include "../../domain/dto/batch-modify-goods/DownGoodsDTO.h"
#include <domain/do/batch-modify-goods/DownGoodsDO.h>

/**
 * 批量修改下架货物服务实现
 */
class DownGoodsService
{
public:
	// 修改数据
	bool updateData(const DownGoodsBatchDTO::Wrapper& dto, const PayloadDTO& payload);
	//生成导出的数据
	list<DownGoodsDO> exportData(const DownGoodsQuery::Wrapper& query);
};

#endif // !_DOWNGOODS_SERVICE_

