#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/3/5 16:09
 
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

#ifndef  _GOODSCLASS_DAO_
#define  _GOODSCLASS_DAO_

#include "stdafx.h"
#include "BaseDAO.h"
#include "../../domain/do/public-do/GoodsClassDO.h"
#include "../../domain/query/goods-class/GoodsClassQuery.h"
#include "id/UuidFacade.h"
#include <iostream>


// 操作计费商品类表
class GoodsClassDAO : public BaseDAO
{
	// 根据查询条件构造对应的查询条件
	inline std::string queryConditionBuilder(const GoodClassQuery::Wrapper& query, SqlParams& params);
public:
	// 录入计费商品类  返回操作的id，操作失败返回0
	std::string insert(const GoodsClassDO& udo);

	// 修改计费商品类 返回操作的id，操作失败返回0
	bool  update(const GoodsClassDO& udo);

	// 统计数据条数
	uint64_t count(const GoodClassQuery::Wrapper& query);
	// 分页查询数据
	std::list<GoodsClassDO> selectName(const GoodClassQuery::Wrapper& query);
	// 分页查询数据
	std::list<GoodsClassDO> selectAllWithPage(const GoodClassQuery::Wrapper& query);

};


#endif //  _GOODSCLASS_DAO_