#pragma once
/*
 @Author: S4turday
 @Date: 2025年3月8日15:35:04

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
#ifndef _QUALITY_DAO_
#define _QUALITY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/quality/QualityDO.h"
#include "../../domain/query/quality/QualityQuery.h"

/**
 * 品质代码数据库操作实现
 */
class QualityDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    QualityDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const QualityQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据QualityQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const QualityQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const QualityQuery::Wrapper& query);
	// 分页查询数据
	std::list<QualityDO> selectWithPage(const QualityQuery::Wrapper& query);
	// 通过品质代码名称查询数据
	std::list<QualityDO> selectByName(const string& name);
	// 通过品质代码查询数据
	std::list<QualityDO> selectByCode(const string& code);
	// 插入数据
	uint64_t insert(const QualityDO& iObj);
	// 修改数据
	int update(const QualityDO& uObj);
};
#endif // !_QUALITY_DAO_