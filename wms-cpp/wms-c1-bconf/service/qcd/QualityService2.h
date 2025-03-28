#pragma once
#ifndef _QUALITYSERVICE_H_
#define _QUALITYSERVICE_H_
#include <list>
#include "domain/vo/qcd/QualityVO2.h"
#include "domain/query/qcd/QualityQuery2.h"
#include "domain/dto/qcd/QualityDTO2.h"
class QualityService
{
public:
	// 通过ID删除数据
	int removeData(const std::vector<std::int32_t>& ids);
	// 分页查询所有数据
	std::list<QualityDTO::Wrapper>  QueryAll(const QualityQuery::Wrapper& query);
	// 新增数据
	bool importData(const std::vector<std::vector<std::string>>& data, const PayloadDTO& payload);
};
#endif // !_QUALITYSERVICE_H_
