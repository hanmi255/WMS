#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../wms-c7-reposity/domain/dto/file/FileDTO.h" 
#include "domain/vo/BaseJsonVO.h"

/**
 * 服务实现
 */
class FileService
{
public:
	// 查询数据
	string queryData();
	// 插入数据
	bool insertData(string fullpath);
};

#endif // !_SAMPLE_SERVICE_

