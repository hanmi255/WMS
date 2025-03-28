/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/03/01 14:12:06

.
*/
#ifndef _GOODSSERVICE_H_
#define _GOODSSERVICE_H_

#include "Macros.h"
#include "../../dao/goods/GoodsMapper.h"
#include "../../domain/dto/goods/GoodsDTO.h"
#include "../../domain/do/goods/GoodsDo.h"
#include "../../dao/goods/GoodsDao.h"
#include "../../domain/query/goods/GoodsQuery.h"
#include <iostream>


class GoodsService
{
public:
	CombineGoodsDTO::Wrapper getData();
	CombineGoodsDTO::Wrapper getTOP();
	CombineGoodsDTO::Wrapper getById(uint64_t id);
	std::vector<std::vector<std::string>> getVectorData();
	bool uploadData(const std::vector<std::vector<std::string>> &data, const PayloadDTO& payload);

};



#endif // !_GOODSSERVICE_H_