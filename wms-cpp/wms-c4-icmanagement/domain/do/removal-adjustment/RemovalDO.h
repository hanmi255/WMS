#pragma once
#ifndef _REMOVAL_DO_
#define _REMOVAL_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class RemovalDO
{
	// 唯一主键
	CC_SYNTHESIZE(string, id, Id);
	// 原始单据编码order_id  
	CC_SYNTHESIZE(string, order_id, Order_id);
	//  商品编码goods_id
	CC_SYNTHESIZE(string, goods_id, Goods_id);
	// 商品名称
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	CC_SYNTHESIZE(string , goods_qua, Goods_qua);
public:
	RemovalDO() {
		id = "";
		order_id = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RemovalDO> PtrRemovalDO;
#endif // !_SAMPLE_DO_