#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2022/10/25 14:23:49

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
#ifndef _COSTWAY_DAO_
#define _COSTWAY_DAO_
#include "../../domain/do/cost-way/CostwayDO.h"
#include "BaseDAO.h"
#include "../../domain/query/cost-way/DeleteQuery.h"

/**
 * 示例表数据库操作实现
 */
class CostwayDAO : public BaseDAO
{
private:
	
	inline std::string queryConditionBuilder(const DeleteQuery::Wrapper& query, SqlParams& params);
public:
	// 通过计费方式编码删除数据
	int deleteById(string pronut_code);
	uint64_t insert(const CostwayDO& iObj);
	// 查询数据
	std::list<CostwayDO> select();
};
#endif // !_COSTWAY_DAO_

