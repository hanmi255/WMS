#pragma once
#ifndef _MODIFY_SERVICE_
#define _MODIFY_SERVICE_

#include <list>
#include "domain/dto/modify-industry-class/ModifyDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ModifyService
{
public:
	// 修改数据
	bool updateData(const ModifyDTO::Wrapper& dto);
	
};

#endif // !_MODIFY_SERVICE_
