#pragma once
#ifndef _EXPIRA_SERVICE_
#define _EXPIRA_SERVICE_

#include "domain/vo/expiration-date-early-warning/ExpirationDateEarlyWarningVO.h"
#include "domain/query/expiration-date-early-warning/ExpirationDateEarlyWarningQuery.h"

class ExpirationDateEarlyWarningService {
public:
	ExpirationDateEarlyWarningPageVO::Wrapper listAll(const ExpirationDateEarlyWarningQuery::Wrapper& query);
};


#endif // !_EXPIRA_SERVICE_

