#pragma once
#ifndef _QUERYADDENTERPRISESTATUS_SERVICE_
#define _QUERYADDENTERPRISESTATUS_SERVICE_
#include <list>
#include "../../domain/vo/enterprise-status/GetEnterpriseStatusVO.h"
#include "../../domain/query/enterprise-status/GetEnterpriseStatusQuery.h"
#include "../../domain/dto/enterprise-status/GetEnterpriseStatusDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class EnterpriseStatusService
{
public:
	// 分页查询所有数据
	EnterpriseStatusPageDTO::Wrapper listAll(const GetEnterpriseStatusQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const EnterpriseStatusDTO::Wrapper& dto);

};

#endif // !_QUERYADDENTERPRISESTATUS_SERVICE_
