#pragma once
#include "SqlSession.h"
#include "domain/GlobalInclude.h"
#include "../lib-oatpp/include/oatpp/core/data/mapping/type/Vector.hpp"
#include "../wms-c7-reposity/dao/BusstyDAO.h"
#include "../arch-demo/Macros.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../wms-c7-reposity/domain/dto/BusstyDTO.h"
/**
 * 示例表数据库操作实现
 */
class BusstyService
{
public:
	// 通过ID删除数据
	bool removeData(uint64_t id);
	bool removedata(const uint64_t ID);
	// 业务类型导出
	std::list<ba_buss_typeDO> leadout();
	//业务类型导入
	bool leadin(std::vector<std::string> v);
};
