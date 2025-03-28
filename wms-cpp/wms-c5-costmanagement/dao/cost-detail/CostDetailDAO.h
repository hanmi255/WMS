#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/4 14:42

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
#ifndef _COST__DETAIL_DAO_
#define _COST__DETAIL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/public-do/DayCostDO.h"
#include "oatpp/core/Types.hpp"
/**
 * "计费管理-费用明细"数据库操作实现
 */
class CostDetailDAO : public BaseDAO
{
private:
	
public:
	//收取费用
	int charge(const oatpp::String& id);
	//取消收取费用
	int discharge(const oatpp::String& id);
	//添加数据
	uint64_t insert(const DayCostDO& iObj);
	//导出全部数据
	list<DayCostDO> exportAll(const oatpp::List<oatpp::String>& ids);
	//按id导出
	DayCostDO selectById(const oatpp::String& id);
};
#endif // !_COST__DETAIL_DAO_
