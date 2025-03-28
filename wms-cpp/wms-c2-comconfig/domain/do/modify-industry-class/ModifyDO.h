#pragma once
#ifndef _MODIFY_DO_
#define _MODIFY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ModifyDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 行业分类代码
	CC_SYNTHESIZE(string, classfl_code, Classfl_code);
	// 行业分类名称
	CC_SYNTHESIZE(string, classfl_name, Classfl_name);
	// 停用
	CC_SYNTHESIZE(string, classfl_del, Classfl_del);
public:
	ModifyDO() {
		id = "";
		classfl_code = "";
		classfl_name = "";
		classfl_del = "";
	}
};

// 给ModifyDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ModifyDO> PtrModifyDO;
#endif // !_MODIFY_DO_
