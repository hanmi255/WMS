#pragma once
#ifndef _COST_NAME_SERVICE_
#define _COST_NAME_SERVICE_
#include <list>
#include "domain/vo/billing-configuration/CostNameVO.h"
#include "domain/query/billing-configuration/CostNameQuery.h"
#include "domain/dto/billing-configuration/CostNameDTO.h"


class CostNameService
{
public:
    // 查询所有数据
    CostListDTO::Wrapper listAll(const CostNameQuery::Wrapper& query);
    // 分页查询所有数据
    CostListPageDTO::Wrapper listAllByPage(const CostNameQuery::Wrapper& query);
    // 保存数据
    bool saveData(const CostAddDTO::Wrapper& dto, const PayloadDTO& payload);
    // 修改数据
    bool updateData(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif