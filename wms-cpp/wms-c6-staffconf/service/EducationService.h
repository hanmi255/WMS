#pragma once
#ifndef _EDU_SERVICE_
#define _EDU_SERVICE_
#include <list>
#include "domain/vo/education/EduVO.h"
#include "domain/query/education/EduQuery.h"
#include "domain/dto/education/EduDTO.h"

/**
 * 学历服务实现
 */
class EduService
{
public:
	// 分页查询所有数据
	EduPageDTO::Wrapper listAll(const EduQuery::Wrapper& query);
	std::vector<std::vector<std::string>> listAll();
	// 保存数据
	uint64_t saveData(const EduAddDTO::Wrapper& dto, const PayloadDTO& payload);
	void saveData(std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload);
};

#endif // !_EDU_SERVICE_