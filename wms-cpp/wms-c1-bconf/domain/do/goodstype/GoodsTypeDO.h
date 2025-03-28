#pragma once
#include "../DoInclude.h"

/**
 * 产品属性数据库实体类
 */
class GoodsTypeDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编码
	CC_SYNTHESIZE(string, code, Code);
public:
	GoodsTypeDO() {
		id = 0;
		name = "";
		code = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<GoodsTypeDO> PtrGoodsTypeDO;