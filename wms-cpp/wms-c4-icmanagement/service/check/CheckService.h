#pragma once
#ifndef _CHECK_SERVICE_
#define _CHECK_SERVICE_
#include <list>
#include "domain/vo/check/CheckVO.h"
#include "domain/query/check/CheckQuery.h"
#include "domain/dto/check/CheckDTO.h"
#include "domain/do/check/CheckDO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CheckService
{
public:
    // 分页查询所有数据
    CheckPageDTO::Wrapper listAll(const CheckQuery::Wrapper &query);

    // 生成导出数据
    list<CheckDO> exportData(const CheckQuery::Wrapper &query);
};

#endif // !_CHECK_SERVICE_
