#pragma once
#ifndef _CHUWEI_SERVICE_
#define _CHUWEI_SERVICE_
#include <list>
#include "domain/vo/chuweidingyi/ChuWeiVO.h"
#include "domain/query/chuweidingyi/ChuWeiQuery.h"
#include "domain/dto/chuweidingyi/ChuWeiDTO.h"
#include <oatpp/core/Types.hpp>

/**
 * 储位服务实现
 */
class ChuWeiService
{
public:
	// 分页查询所有数据
	ChuWeiPageDTO::Wrapper listAll(const ChuWeiQuery::Wrapper& query);
	// 修改数据
	bool updateData(const ChuWeiDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(string id);
	// 批量删除方法
	bool batchRemoveData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_CHUWEI_SERVICE_

