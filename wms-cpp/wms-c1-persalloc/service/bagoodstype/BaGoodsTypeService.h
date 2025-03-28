#ifndef _BaGoodsType_SERVICE_
#define _BaGoodsType_SERVICE_
#include <list>
#include "domain/vo/bagoodstype/BaGoodsTypeVO.h"
#include "domain/query/bagoodstype/BaGoodsTypeQuery.h"
#include "domain/dto/bagoodstype/BaGoodsTypeDTO.h"

/**
 * 工作状态服务实现
 */
class BaGoodsTypeService
{
public:                                     
	// 分页查询所有数据
	BaGoodsTypeNamePageDTO::Wrapper listAll(const BaGoodsTypeQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_