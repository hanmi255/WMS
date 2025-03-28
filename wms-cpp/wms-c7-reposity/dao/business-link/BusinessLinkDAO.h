#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunyin

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
#ifndef _BUSINESS_LINK_DAO_H_
#define _BUSINESS_LINK_DAO_H_
#include "BaseDAO.h"

#include "../../domain/query/business-link/BusinessLinkQuery.h"
#include "../../domain/do/bussiness-link/BusinessLinkDO.h"

/**
 * 业务环节表数据库操作实现
 */


class BusinessLinkDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    BusinessLinkDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const BusinessLinkQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const BusinessLinkQuery::Wrapper& query, SqlParams& params);
public:
	// 查询所有业务环节名称
	std::list<BusinessLinkNameDO> selectAllName();
	// 分页查询数据
	std::list<BusinessLinkDO> selectWithPage(const BusinessLinkQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const BusinessLinkDO& iObj);
	// 统计数据条数
	uint64_t count(const BusinessLinkQuery::Wrapper& query);
};


#endif // !_BUSINESS_LINK_DAO_H_
