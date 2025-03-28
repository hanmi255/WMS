#pragma once

#ifndef _ENTERPRISE_SERVICE_
#define _ENTERPRISE_SERVICE_
#include <list>
#include "domain/dto/enterpriseDTO.h"
#include "domain/query/enterprisePageQuery.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/enterpriseJsonVO.h"

#include <chrono>
#include "../lib-common/include/SimpleDateTimeFormat.h"
class enterpriseService
{
public:
	//新增企业分类信息
	uint64_t saveData(const addEnterpriseDTO::Wrapper& enterpriseInfo, const PayloadDTO& payload);
	//分页查询
	enterprisePageDTO::Wrapper  listAll(const enterprisePageQuery::Wrapper& query);
	//获取企业分类名称列表
	enterpriseNameDTO::Wrapper getEnterpriseName();//const PageQuery::Wrapper& query

};
#endif
