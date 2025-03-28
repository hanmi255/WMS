#pragma once
#include "BaseDAO.h"
#include "../lib-oatpp/include/oatpp/core/data/mapping/type/Vector.hpp"
#include "domain/GlobalInclude.h"
#include "../arch-demo/Macros.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../wms-c7-reposity/domain/do/ba_buss_typeDO.h"
/**
 * 示例表数据库操作实现
 */
class BusstyDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int deleteById(uint64_t id);
	int deleteByID(uint64_t ID);
	//业务类型导出
	std::list<ba_buss_typeDO> leadout();
	//业务类型导入
	int leadin(ba_buss_typeDO data);
	
};
