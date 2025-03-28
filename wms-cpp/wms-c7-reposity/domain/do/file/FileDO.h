#pragma once
/*
 @Author: nanbowan
*/

#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * 订单类型数据库实体类
 */
class FileDO
{
	// 订单类型代码
	CC_SYNTHESIZE(string, order_type_code, Code);
	// 订单类型名称
	CC_SYNTHESIZE(string, order_type_name, Name);

public:
	FileDO() {
		order_type_code = "";
		order_type_name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<FileDO> PtrFileDO;
#endif // !_SAMPLE_DO_

