#pragma once
#ifndef _ENTERPRISESTATUSSERVICE_
#define _ENTERPRISESTATUSSERVICE_
#include <list>
#include "domain/vo/md-cus-other/EnterpriseVO.h"
#include "domain/query/md-cus-other/EnterpriseQuery.h"
#include "domain/dto/md-cus-other/EnterpriseDTO.h"


class EnterpriseStatusService
{
public:
	// 分页查询所有企业状态数据
	EnterpriseListPageDTO::Wrapper queryAll(const EnterpriseQuery::Wrapper& query);
	// 获取所有企业状态下拉列表
	EnterpriseStatusListDTO::Wrapper queryForList();
};

#endif // !_ENTERPRISESTATUSSERVICE_
