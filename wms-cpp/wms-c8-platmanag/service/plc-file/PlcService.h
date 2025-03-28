#pragma once
/*
 @Author: tutu
*/
#ifndef _PLC_SERVICE_
#define _PLC_SERVICE_
#include <list>
#include "domain/vo/plc-file/PlcFileVO.h"
#include "domain/query/plc-file/PlcFileQuery.h"
#include "domain/dto/plc-file/PlcFileDto.h"

class PlcService
{
public:
	// 分页查询所有数据
	PlcListPageDTO::Wrapper listAll(const PlcFileQuery::Wrapper& query);
	// 通过ID查询单个数据
	PlcdetailDTO::Wrapper getById(string id);
	// 保存数据
	bool saveData(const PlcAddDTO::Wrapper& dto, string name, string realname, string orgcode, string companycode);
	// 修改数据
	bool updateData(const PlcdetailDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(string id);
};

#endif

