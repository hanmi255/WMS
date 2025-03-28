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

#ifndef _MOVINGBIN_DAO_
#define _MOVINGBIN_DAO_

#include "BaseDAO.h"
#include "../../domain/do/moving-bin/MovingBinDO.h"
#include "../../domain/query/moving-bin/MovingBinQuery.h"
/**
 * 示例表数据库操作实现
 */
class MovingBinDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const MovingBinQuery::Wrapper& query, SqlParams& params);
		
public:
	uint64_t count(const MovingBinQuery::Wrapper& query);
	// 分页查询数据
	std::list<MovingBinDO> selectWithPage(const MovingBinQuery::Wrapper& query);
	// 不分页查询数据
	std::list<MovingBinDO> selectWithConditions(const MovingBinQuery::Wrapper& query);
};
#endif // !_MOVINGBIN_DAO_