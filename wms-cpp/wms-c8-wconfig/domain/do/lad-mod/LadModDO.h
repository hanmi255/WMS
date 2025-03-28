#pragma once

#ifndef _LADMOD_DO_
#define _LADMOD_DO_
#include "../DoInclude.h"

/**
 * 提货方式-数据库实体类
 */
class LadModDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 提货方式代码
	CC_SYNTHESIZE(string, code, Code);
	// 提货方式名称
	CC_SYNTHESIZE(string, name, Name);
public:
	LadModDO() {
		id = 0;
		code = "";
		name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<LadModDO> PtrLadModDO;
#endif // !_LadMod_DO_
