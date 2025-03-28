#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: whx
 @Date: 2025/3/5 14:23:49

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
#ifndef _COSTDETAIL_SERVICE_
#define _COSTDETAIL_SERVICE_
#include <list>
#include "domain/vo/cost-detail-ahead/CostDetialVO.h"
#include "domain/query/cost-detail-ahead/CostDetailQuery.h"
#include "domain/dto/cost-detail-ahead/CostDetialDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CostDetailService
{
public:
	// 分页查询所有数据
	CostDetailListPageDTO::Wrapper listAll(const CostDetailQuery::Wrapper& query);
	// 通过ID查询单个数据
	CostDetailBaseDTO::Wrapper getById(uint64_t id);
	// 保存数据
	uint64_t saveData(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload);
	// 通过ID删除数据
	bool removeData(const string& id);
	// 通过多个ID删除批量数据
	bool removeBatchData(const vector<string>& id);

};

#endif // !_COSTDETAIL_SERVICE_

