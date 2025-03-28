#pragma once

#ifndef _SEX_DO_
#define _SEX_DO_
#include "../DoInclude.h"

/**
 * 性别信息数据库实体类
 */
class SexDO
{
	//字段id
	CC_SYNTHESIZE(string, id, Id);
	// 性别代码
	CC_SYNTHESIZE(string, sexcode, SexCode);
	// 性别名称
	CC_SYNTHESIZE(string, sexname, SexName);
public:
	SexDO() {
		id = "";
		sexcode = "";
		sexname = "";
	}
};

// 给SexDO智能指针设定一个别名方便使用
typedef std::shared_ptr<SexDO> PtrSexDO;
#endif // !_SEX_DO_