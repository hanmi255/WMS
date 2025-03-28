#pragma once
#ifndef _EXPENSETYPEMAPPER_
#define _EXPENSETYPEMAPPER_

#include "Mapper.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"

/**
 * 库存表字段匹配映射
 */
class ExpenseTypeMapper : public Mapper<ExpenseTypeDO>
{
public:
	ExpenseTypeDO mapper(ResultSet* resultSet) const override
	{
		ExpenseTypeDO data;
		data.setId(resultSet->getString(1));                   // 编号  
		data.setCreate_name(resultSet->getString(2));           // 创建人名称  
		data.setCreate_by(resultSet->getString(3));            // 创建人登录名称  
		data.setCreate_date(resultSet->getString(4));           // 创建日期  
		data.setUpdate_name(resultSet->getString(5));            // 更新人名称  
		data.setUpdate_by(resultSet->getString(6));             // 更新人登录名称  
		data.setUpdate_date(resultSet->getString(7));           // 更新日期  
		data.setSys_org_code(resultSet->getString(8));           // 所属部门  
		data.setSys_company_code(resultSet->getString(9));       // 所属公司  
		data.setCost_type_code(resultSet->getString(10));             // 费用代码
		data.setCost_type_name(resultSet->getString(11));           // 费用名称
		data.setCost_type_del(resultSet->getString(12));       // 停用
		
		return data;
	}
};

/**
 * 库存表字段匹配映射-创建智能指针对象
 */
class PtrExpenseTypeMapper : public Mapper<PtrExpenseTypeDO>
{
public:
	PtrExpenseTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ExpenseTypeDO>();
		data->setId(resultSet->getString(1));                   // 编号  
		data->setCreate_name(resultSet->getString(2));           // 创建人名称  
		data->setCreate_by(resultSet->getString(3));            // 创建人登录名称  
		data->setCreate_date(resultSet->getString(4));           // 创建日期  // 修复：添加缺失的create_date字段  
		data->setUpdate_name(resultSet->getString(5));            // 更新人名称  
		data->setUpdate_by(resultSet->getString(6));             // 更新人登录名称  
		data->setUpdate_date(resultSet->getString(7));           // 更新日期  
		data->setSys_org_code(resultSet->getString(8));           // 所属部门  
		data->setSys_company_code(resultSet->getString(9));       // 所属公司  
		data->setCost_type_code(resultSet->getString(10));             // 费用代码
		data->setCost_type_name(resultSet->getString(11));           // 费用名称
		data->setCost_type_del(resultSet->getString(12));       // 停
		return data;
	}
};

#endif // !_EXPENSETYPEMAPPER_