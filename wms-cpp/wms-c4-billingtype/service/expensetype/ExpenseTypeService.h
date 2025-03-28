#pragma once

#ifndef _EXPENSETYPESERVICE_
#define _EXPENSETYPESERVICE_
#include <list>



#include "domain/query/expensetype/ExpenseTypeQuery.h"


/**
 * 费用类型服务实现
 */
class ExpenseTypeService
{
public:
	std::string exportData(const ExpenseTypeQuery::Wrapper& query);
};

#endif // !_EXPENSETYPESERVICE_
