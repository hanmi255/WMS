#pragma once
#ifndef _MODIFY_DAO_
#define _MODIFY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/modify-industry-class/ModifyDO.h"


/**
 * 示例表数据库操作实现
 */
class ModifyDAO : public BaseDAO
{

public:	
	// 修改数据
	int update(const ModifyDO& uObj);
};
#endif // !_MODIFY_DAO_
