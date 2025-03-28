#pragma once
/*
 @Author: 002
 @Date: 2025.3.7
*/
#ifndef _REGION_INFO_SERVICE_
#define _REGION_INFO_SERVICE_
#include <list>
#include "domain/dto/regioninfo/RegioninfoDTO.h"
#include "domain/do/regioninfo/RegionInfoDO.h"
#include "domain/dto/regioninfo/RegionNameDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RegionInfoService
{
public:
	// 保存数据
	uint64_t saveData(const RegionInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// 通过region_code删除数据
	bool removeData(std::string region_code);
	// 修改数据
	bool updateData(const RegionModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// 导入数据
	void import(std::vector<std::vector<std::string>> data, const PayloadDTO& payload);
	oatpp::Vector<RegionNameDTO::Wrapper> getByName();
};

#endif // !_SAMPLE_SERVICE_

#pragma once
