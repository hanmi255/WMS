#include "Mapper.h"
#include "../../domain/do/goodstype/GoodsTypeDO.h"

/**
 * 示例表字段匹配映射
 */
class GoodsTypeMapper : public Mapper<GoodsTypeDO>
{
public:
	GoodsTypeDO mapper(ResultSet* resultSet) const override
	{
		GoodsTypeDO data;
		data.setId(resultSet->getUInt64(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		return data;
	}
};
