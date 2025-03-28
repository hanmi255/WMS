


#ifndef _CUSTOMER_DAO_
#define _CUSTOMER_DAO_
#include "BaseDAO.h"
#include "domain/do/customer-bill/CustomerBillDO.h"
#include "domain/do/public-do/DayCostDO.h"
#include "domain/query/customer-bill/CustomerBillQuery.h"


// 给DayCostDO智能指针设定一个别名方便使用
//typedef std::shared_ptr<DayCostDO> PtrDayCostDO;


/**
 * 分页查询数据库操作实现
 */
class CustomerBillDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const CustomerBillQuery::Wrapper& query, SqlParams& params);
	inline std::string idConditionBuilder( oatpp::String& id, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const CustomerBillQuery::Wrapper& query);
	// 分页查询数据
	std::list<CustomerBillDO> selectWithPage(const CustomerBillQuery::Wrapper& query);
	// 通过ID查询数据
	std::list<DayCostDO> selectById(oatpp::String id);
	//通过date查询数据
	std::list<DayCostDO> selectBydate(const PeriodQuery::Wrapper& file);

};

#endif // !_SAMPLE_DAO_
