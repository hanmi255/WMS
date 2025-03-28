/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/03/01 14:03:04


*/
#ifndef _GOODSDAO_H_
#define _GOODSDAO_H_
#include "../../domain/do/goods/GoodsDo.h"
#include "BaseDAO.h"
#include <list>


class GoodsDao : public BaseDAO
{
public:
	std::list<GoodsDo> getAll();
	uint64_t countAll();
	std::list<GoodsDo> getTop();
	GoodsDo getById(uint64_t id);
	int insert(GoodsDo tmp);
};

#endif // !_GOODSDAO_H_