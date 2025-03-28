#pragma once

#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class EmployedStatusDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 名称pos_sta_name
	CC_SYNTHESIZE(string, name, Name);
	// 编码pos_sta_code
	CC_SYNTHESIZE(string, code, Code);

public:
	EmployedStatusDO() {
		id = "";
		name = "";
		code = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<EmployedStatusDO> PtrSampleDO;