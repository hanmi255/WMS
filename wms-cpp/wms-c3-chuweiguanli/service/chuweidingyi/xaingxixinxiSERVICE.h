#pragma once

#ifndef _XIANGXIXINXISERVICE_
#define _XIANGXIXINXISERVICE_
#include <list>
#include "../../domain/dto/chuweidingyi/xiangxixinxiDTO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
 


class xiangxixinxiSERVICE
{
public:

	// 通过ID查询单个数据
	xiangxixinxiDTO::Wrapper getById(const xiangxixinxiQUERY::Wrapper& id);

	//通过ID返回查找数据, 返回文件路径
	string daochuchuweiCONTROLLER(oatpp::List<oatpp::String>&  chuwei);

	//导入储位
	std::string addchuweiSERVICE(const  xiangxixinxiDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_XIANGXIXINXISERVICE_