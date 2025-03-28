#pragma once
#include "../arch-demo/domain/do/DoInclude.h"

class ba_buss_typeDO
{
	// 编号
	CC_SYNTHESIZE(uint16_t, id, Id);
	// 业务类型代码
	CC_SYNTHESIZE(string, num, Num);
	// 业务类型名称
	CC_SYNTHESIZE(string, name, Name);
	// 业务类型备注
	CC_SYNTHESIZE(string, desc, Desc);
public:
	ba_buss_typeDO() {
		id = 1;
		num = "";
		name = "";
		desc = "";
	}
};