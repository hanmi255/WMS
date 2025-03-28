#pragma once
// 王也 2025 02 28
#ifndef _WORKSTATE_DAO_
#define _WORKSTATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/workstate/WorkStateDO.h"


/**
 * 示例表数据库操作实现
 */
class WorkStateDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int deleteById(string id);

	std::list<WorkStateDO> selectAll();
	std::list<WorkStateDO> selectWork();
	int insert(WorkStateDO tmp);

};
#endif // !_WORKSTATE_DAO_
