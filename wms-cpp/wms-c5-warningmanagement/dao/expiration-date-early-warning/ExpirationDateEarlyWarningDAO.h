#pragma once

#ifndef _EXPIR_DAO_
#define _EXPIR_DAO_

#include "BaseDAO.h"
#include "domain/query/expiration-date-early-warning/ExpirationDateEarlyWarningQuery.h"
#include "domain/do/StockYJDO.h"

class ExpirationDateEarlyWarningDAO :BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const ExpirationDateEarlyWarningQuery::Wrapper& query);
	// 分页查询数据
	std::list<StockYJDO> selectWithPage(const ExpirationDateEarlyWarningQuery::Wrapper& query);



};




#endif // !_EXPIR_DAO_
