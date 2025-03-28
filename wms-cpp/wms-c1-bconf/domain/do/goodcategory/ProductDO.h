#pragma once
#ifndef _PRODUCT_DO_
#define _PRODUCT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ProductDO
{
	
	// 商品编码
	CC_SYNTHESIZE(string, categorynum, Categorynum);
	// 商品类目名称
	CC_SYNTHESIZE(string, categoryname, Categoryname);
	// 商品级别
	CC_SYNTHESIZE(int, categorylevel, Categorylevel);
	//pid
	CC_SYNTHESIZE(int, pid, PID);
	//top_node
	CC_SYNTHESIZE(string, topnode, Topnode);
public:
	ProductDO() {
		categorynum = "";
		categoryname = "";
		categorylevel = -1;
		pid = -1;
		topnode = "";
	}
};

// 给ProductDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ProductDO> PtrProductDO;
#endif // !_SAMPLE_DO_