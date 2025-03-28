#include "stdafx.h"
#include "ExpirationDateEarlyWarningController.h"
//#include "../../service/sample/SampleService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "service/expiration-date-early-warning/ExpirationDateEarlyWarningService.h"
#include "domain/vo/expiration-date-early-warning/ExpirationDateEarlyWarningVO.h"

ExpirationDateEarlyWarningPageJsonVO::Wrapper ExpirationDateEarlyWarningController::execQueryListOfWarning(const ExpirationDateEarlyWarningQuery::Wrapper& query, const PayloadDTO& payload) {
	ExpirationDateEarlyWarningService service;
	auto re = service.listAll(query);
	auto jvo = ExpirationDateEarlyWarningPageJsonVO::createShared();
	jvo->success(re);
	return jvo;
}
