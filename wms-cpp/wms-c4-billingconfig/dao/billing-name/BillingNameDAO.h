#pragma once
#ifndef _BILLINGNAME_DAO_
#define _BILLINGNAME_DAO_
#include "BaseDAO.h"
//#include "../../domain/do/sample/SampleDO.h"
//#include "../../domain/do/addition-adjustment/AdditionDO.h"
#include "../../domain/do/billing-name/BillingNameDO.h"
#include "../../domain/query/billing-name/BillingNameQuery.h"
//#include "../../domain/do/"
//#include "../../domain/query/sample/SampleQuery.h"
//#include "../../domain/query/removal-adjustment/RemovalQuery.h"
/**
 * 示例表数据库操作实现
 */
class BillingNameDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const BillingNameQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	//uint64_t count(const RemovalQuery::Wrapper& query);
	// 分页查询数据
	//std::list<RemovalDO> selectWithPage(const RemovalQuery::Wrapper& query);
	// 通过姓名查询数据
	//std::list<SampleDO> selectByName(const string& name);
	// 通过ID查询数据
	//PtrRemovalDO selectById(const string& id);
	// 插入数据
	//uint64_t insert(const SampleDO& iObj);
	// 修改数据
	int batchdelete(const BillingNameDO& uObj);
	int batchinsert(const BillingNameDO& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);
	std::list<BillingNameDO> selectWithConditions(const BillingNameQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_