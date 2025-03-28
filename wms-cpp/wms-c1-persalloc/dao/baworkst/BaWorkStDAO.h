#ifndef _BAWORKST_DAO_
#define _BAWORKST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/baworkst/BaWorkStDO.h"
#include "../../domain/query/baworkst/BaWorkStQuery.h"

/**
 * 示例表数据库操作实现
 */
class BaWorkStDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const BaWorkStQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const BaWorkStQuery::Wrapper& query);
	// 分页查询数据
	std::list<BaWorkStDO> selectWithPage(const BaWorkStQuery::Wrapper& query);
	// 录入工作状态
	uint64_t insert(const BaWorkStDO& iObj);
	// 修改工作状态
	int update(const BaWorkStDO& uObj);
};
#endif // !_BAWORKST_DAO_
