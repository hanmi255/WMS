#ifndef _BAGOODSTYPE_MAPPER_
#define _BAGOODSTYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/bagoodstype/BaGoodsTypeDO.h"

/**
 * 工作状态表字段匹配映射
 */
class BaGoodsTypeMapper : public Mapper<BaGoodsTypeDO>
{
public:
	BaGoodsTypeDO mapper(ResultSet* resultSet) const override
	{
		BaGoodsTypeDO data;
		//根据列索引来查询
		data.setId(resultSet->getString(1));
		data.setGoodsTypeCode(resultSet->getString(2));
		data.setGoodsTypeName(resultSet->getString(3));
		return data;
	}
};

/**
 * 工作状态表字段匹配映射-创建智能指针对象
 */
class PtrBaGoodsTypeMapper : public Mapper<PtrBaGoodsTypeDO>
{
public:
	PtrBaGoodsTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BaGoodsTypeDO>();
		data->setId(resultSet->getString(1));
		data->setGoodsTypeCode(resultSet->getString(2));
		data->setGoodsTypeName(resultSet->getString(3));
		return data;
	}
};

#endif // !_BAGOODSTYPE_MAPPER_