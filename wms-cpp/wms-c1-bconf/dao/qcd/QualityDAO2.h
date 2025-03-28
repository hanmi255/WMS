#pragma once
#ifndef _QUALITYDAO_H_
#define _QUALITYDAO_H_
#include "BaseDAO.h"
#include "domain/query/qcd/QualityQuery2.h"
#include "domain/do/qcd/QualityDO2.h"

class QualityDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int deleteById(string id);
	// 批量删除数据
	int deleteByIds(const std::vector<std::int32_t>& ids);
	//统计数据条数
	uint64_t count(const QualityQuery::Wrapper& query);
	// 分页查询数据
	std::list<QualityDO> QueryWithPage(const QualityQuery::Wrapper& query);
	// 插入数据
	uint64_t insert2(const QualityDO& iObj);
};
#endif // ! _QUALITYDAO_H_	