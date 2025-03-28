#pragma once
#ifndef _REGION_INFO_DAO_
#define _REGION_INFO_DAO_
#include "BaseDAO.h"
#include "domain/do/regioninfo/RegionInfoDO.h"
/**
 * 示例表数据库操作实现
 */

class RegionInfoDAO : public BaseDAO
{
public:
	uint64_t insert(const RegionInfoDO& iObj);
	void insert(const list<RegionInfoDO>& iObj);
	uint64_t remove(std::string region_code);
	uint64_t update(const RegionInfoDO& iObj);
	// 通过姓名查询数据
	std::list<RegionNameDO> selectByName();
};

#endif // !_SAMPLE_DAO_
