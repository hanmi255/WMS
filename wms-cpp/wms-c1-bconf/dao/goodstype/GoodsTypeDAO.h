#pragma once
#include "BaseDAO.h"
#include "../../domain/do/goodstype/GoodsTypeDO.h"
#include "domain/dto/PayloadDTO.h"
/**
 *  产品属性数据库操作实现
 */
class GoodsTypeDAO : public BaseDAO
{
private:

public:
	// 插入数据
	uint64_t insert(const GoodsTypeDO& iObj, const PayloadDTO& payload);

};