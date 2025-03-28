#pragma once
#ifndef _BUSSTYPE_DAO_
#define _BUSSTYPE_DAO_

#include "BaseDAO.h"
#include "../../domain/query/busstype/BussTypeQuery.h"
#include "../../domain/do/busstype/BussTypeDO.h"
#include "../../domain/do/DoInclude.h"

class BussTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const BussTypeQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询数据
	std::list<BussTypeDO> selectWithPage(const BussTypeQuery::Wrapper& query);
	// 通过业务类型名称查询数据
	std::list<BussTypeDO> selectByName(const string& name);
	// 通过业务类型代码查询数据
	std::list<BussTypeDO> selectByCode(const string& code);
	// 通过业务类型备注查询数据
	std::list<BussTypeDO> selectByText(const string& text);
	// 插入数据
	uint64_t insert(const BussTypeDO& iObj);
	// 统计数据条数
	uint64_t count(const BussTypeQuery::Wrapper& query);
	// 修改数据
	int update(const BussTypeDO& uObj);
};
#endif // _BUSSTYPE_DAO_
