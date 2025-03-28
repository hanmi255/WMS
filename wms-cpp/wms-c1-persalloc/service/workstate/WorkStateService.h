#pragma once
/*
 王也 2025 02 28
*/
#ifndef _WORKSTATE_SERVICE_
#define _WORKSTATE_SERVICE_
#include <list>
#include "domain/vo/workstate/WorkStateVO.h"
#include "domain/dto/workstate/WorkStateDTO.h"
#include "domain/do/workstate/WorkStateDO.h"
/**
 * 工作状态删除服务实现，还有excel文档的导入导出服务实现
 */
class WorkStateService
{
public:
	// 通过ID删除数据
	bool removeData(string id); //可能这里的string数据类型不对

	bool uploadData(const std::vector<std::vector<std::string>>& data, const PayloadDTO& payload);
	std::vector<std::vector<std::string>> getVectorData();
};

#endif // !_WORKSTATE_SERVICE_

