#pragma once
#ifndef _ENTERPRISE_DAO_
#define _ENTERPRISE_DAO_
#include "BaseDAO.h"
#include "domain/dto/enterpriseDTO.h"
#include "domain/do/enterpriseDO.h"
#include "domain/query/enterprisePageQuery.h"
#include "domain/do/enterpriseDO.h"
#include "RedisClient.h"
#include "domain/do/EnterpriseDoMapper.h"
class enterpriseDAO : public BaseDAO
{
public:
	//增加企业分类信息
	uint64_t insert(const EnterpriseDO& enterpriseInfo);

	//企业分类数据分页查询
	std::list<EnterpriseDO> selectWithPage(const enterprisePageQuery::Wrapper& query);

	//获取企业分类数据
	std::list<EnterpriseDO> getEnterpriseName();


	uint64_t count(const enterprisePageQuery::Wrapper& query);

	//查询条件构建器
	std::string queryCondionBuilder(const enterprisePageQuery::Wrapper& query, SqlParams& params);
};
#endif