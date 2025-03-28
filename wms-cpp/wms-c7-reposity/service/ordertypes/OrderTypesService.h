#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/dto/ordertypes/OrderTypesDTO.h" 

/**
 * 服务实现
 */
class OrderTypesService
{
public:
	// 修改数据
	bool updateData(const ModifyOrderTypeDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(string id);;
};

#endif // !_SAMPLE_SERVICE_

