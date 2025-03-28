#pragma once
#ifndef  _GOODSSTATEDAO_H_
#define _GOODSSTATEDAO_H_
#include "BaseDAO.h"
#include "domain/query/goodsstate/GoodStateQuery.h"
#include "domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"
//#include "domain/dto/goodsstate/GoodStateDTO.h"
//#include "../../dao/goodsstate/GoodsStateDAO.h"
//#include "domain/vo/goodsstate/GoodsStateVO.h"

class GoodsStateDAO : public BaseDAO
{
public:
	// 分页查询数据
	std::list<GoodsStateControllerDO> QueryWithPage(const GoodStateQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const GoodsStateControllerDO& iObj);
	// 批量删除数据
	int deleteByIds(const std::vector<std::string>& ids);
};
#endif // ! _GOODSSTATEDAO_H_