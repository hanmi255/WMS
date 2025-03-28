#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 17:28:32

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

#ifndef  _COST_ATTRIBUTE_DAO_
#define  _COST_ATTRIBUTE_DAO_

#include "stdafx.h"
#include "BaseDAO.h"
#include "../../domain/do/cost-attribute/CostAttributeDO.h"
#include "../../domain/query/cost-attribute/CostAttributeQuery.h"
#include "../../domain/query/cost-attribute/CostSxQuery.h"
#include "id/UuidFacade.h"
#include <iostream>

// 客户计费属性
class CostAttributeDao : public BaseDAO
{
	// 查询条件构建
	inline std::string queryConditionBuilder(const CostSxQuery::Wrapper& query, SqlParams& params);
public:
	// 录入用户属性 
	std::string insert(const CostSxDO& udo);

	// 更新用户属性
	bool  update(const CostSxDO& udo);

	// 统计个数
	uint64_t count(const CostSxQuery::Wrapper& query);
	// 分页查询名称
	std::list<CostSxDO> selectNameWithPage(const CostSxQuery::Wrapper& query);
	// 分页查询所有
	std::list<CostSxDO> selectAllWithPage(const CostSxQuery::Wrapper& query);
	
};


class CostAttributeDAO : public BaseDAO
{
private:
public:
	// 删除客户计费属性
	int deleteCostAttribute(const string& id);
	// 导入客户计费属性
	uint64_t importCostAttribute(const CostAttributeDO& dataDO);
	// 导出客户计费属性
	list<CostAttributeDO> exportCostAttribute();
};


#endif //  _COST_ATTRIBUTE_DAO_
