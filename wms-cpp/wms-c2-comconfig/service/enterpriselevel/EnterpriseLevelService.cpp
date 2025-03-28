#include "stdafx.h"
#include "EnterpriseLevelService.h"
#include "../../dao/enterpriselevel/EnterpriseLevelDAO.h"

EnterpriseLevelNameDTO::Wrapper EnterpriseLevelService::getEnterpriseLevelName()
{
	auto dto = EnterpriseLevelNameDTO::createShared();
	return dto;
}