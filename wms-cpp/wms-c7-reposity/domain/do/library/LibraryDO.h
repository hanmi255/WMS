#pragma once
/*
 @Author: nanbowan
*/
#include "../DoInclude.h"

/**
 * 订单类型数据库实体类
 */
class LibraryDO
{
	// 唯一id
	CC_SYNTHESIZE(string, id, Id);
	// 库位代码
	CC_SYNTHESIZE(string, bin_type_code, Code);
	// 库位名称
	CC_SYNTHESIZE(string, bin_type_name, Name);

public:
	LibraryDO() {
		id = "0";
		bin_type_code = "";
		bin_type_name = "";
	}
};

// 给DO智能指针设定一个别名方便使用
typedef std::shared_ptr<LibraryDO> PtrLibraryDO;


