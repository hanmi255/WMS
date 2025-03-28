#pragma once
#pragma once
#ifndef _ADDITION_DO_
#define _ADDITION_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class AdditionDO
{
	// 唯一主键
	CC_SYNTHESIZE(string, id, Id);
	// 原始单据编码order_id  
	CC_SYNTHESIZE(string, order_id, Order_id);
	//  商品编码goods_id
	CC_SYNTHESIZE(string, goods_id, Goods_id);
	// 商品名称
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	CC_SYNTHESIZE(string, goods_qua, Goods_qua);
public:
	AdditionDO() {
		id = "";
		order_id = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<AdditionDO> PtrAdditionDO;
#endif // !_SAMPLE_DO_