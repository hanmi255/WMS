#ifndef _CUSTOMER_MAPPER_
#define _CUSTOMER_MAPPER_

#include "Mapper.h"
#include "domain/do/customer-bill/CustomerBillDO.h"
#include "domain/do/public-do/DayCostDO.h"

//typedef std::shared_ptr<DayCostDO> PtrDayCostDO;
/**
 * 示例表字段匹配映射
 */
class CustomerBillMapper : public Mapper<CustomerBillDO>
{
public:
	CustomerBillDO mapper(ResultSet* resultSet) const override
	{
		CustomerBillDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrSampleMapper : public Mapper<PtrCustomerBillDO>
{
public:
	PtrCustomerBillDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CustomerBillDO>();
		data->setId(resultSet->getString(1));
		data->setName(resultSet->getString(2));

		return data;
	}
};



/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class DayCostMapper : public Mapper<DayCostDO>
{
public:
	DayCostDO mapper(ResultSet* resultSet) const override
	{
		DayCostDO data;
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setCusCode(resultSet->getString(10));
		data.setCusName(resultSet->getString(11));
		data.setCostCode(resultSet->getString(12));
		data.setCostName(resultSet->getString(13));
		data.setCostDate(resultSet->getString(14));
		data.setDayCostYj(resultSet->getString(15));
		data.setDayCostBhs(resultSet->getString(16));
		data.setDayCostSe(resultSet->getString(17));
		data.setDayCostHsj(resultSet->getString(18));
		data.setCostOri(resultSet->getString(19));
		data.setBeiZhu(resultSet->getString(20));
		data.setCostSta(resultSet->getString(21));
		data.setCostSl(resultSet->getString(22));
		data.setCostUnit(resultSet->getString(23));
		data.setCostJs(resultSet->getString(24));


		return data;
	}
};

#endif // !_SAMPLE_MAPPER_