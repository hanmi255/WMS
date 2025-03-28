#pragma once
/*
 @Author: nanbowan
*/

#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * 温度属性数据库实体类
 */
class LibraryFileDO
{
	// 库位代码
	CC_SYNTHESIZE(string, bin_type_code, Code);
	// 库位名称
	CC_SYNTHESIZE(string, bin_type_name, Name);

public:
	LibraryFileDO() {
		bin_type_code = "";
		bin_type_name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<LibraryFileDO> PtrLibraryFileDO;
#endif 

