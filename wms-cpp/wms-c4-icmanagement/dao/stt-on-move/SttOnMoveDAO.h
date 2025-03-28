#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/02 13:23:49

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

#ifndef _STT_ON_MOVE_DAO_
#define _STT_ON_MOVE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/stt-on-move/SttOnMoceDO.h"
#include "../../domain/query/stt-on-move/SttOnMoveQuery.h"

/*
*  动碰盘视图查询操作实现
*/
class SttOnMoveDAO : public BaseDAO
{
private:
//************************************
// Method:      queryConditionBuilder
// FullName:    SttOnMoveDAO::queryConditionBuilder
// Access:      private 
// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
// Parameter:   const SttOnMoveQuery::Wrapper& query 查询数据对象
// Parameter:   SqlParams& params 存放查询数据的参数对象
// Description: 查询条件构建器，根据SttOnMoveQuery对象动态构建查询条件相关参数
//************************************
	inline std::string queryConditionBuilder(const SttOnMoveQuery::Wrapper& query, SqlParams& params);

public:
	// 查询数据条数
	uint64_t count(const SttOnMoveQuery::Wrapper& query);
	// 分页查询数据
	std::list<SttOnMoveDO> selectWithPage(const SttOnMoveQuery::Wrapper& query);
	// 根据id查询数据
	PtrSttOnMoveDO selectWithId(string id);
};


#endif