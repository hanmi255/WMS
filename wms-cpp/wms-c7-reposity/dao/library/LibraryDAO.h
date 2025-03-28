/*
 @Author: nanbowan
*/
#pragma once

#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "domain/do/library/LibraryDO.h"
#include "domain/dto/library/LibraryDTO.h"

/**
 * 表数据库操作实现
 */
class LibraryDAO : public BaseDAO
{
private:
public:
	// 修改数据
	int update(const LibraryDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_

