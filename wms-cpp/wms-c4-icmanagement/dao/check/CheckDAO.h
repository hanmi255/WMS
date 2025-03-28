#pragma once
#ifndef _CHECK_DAO_
#define _CHECK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/check/CheckDO.h"
#include "../../domain/query/check/CheckQuery.h"

/**
 * 示例表数据库操作实现
 */
class CheckDAO : public BaseDAO
{
private:
    //************************************
    // Method:      queryConditionBuilder
    // FullName:    CheckDAO::queryConditionBuilder
    // Access:      private
    // Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
    // Parameter:   const CheckQuery::Wrapper& query 查询数据对象
    // Parameter:   SqlParams& params 存放查询数据的参数对象
    // Description: 查询条件构建器，根据CheckQuery对象动态构建查询条 件相关参数
    //************************************
    inline std::string queryConditionBuilder(const CheckQuery::Wrapper &query, SqlParams &params);

public:
    // 统计数据条数
    uint64_t count(const CheckQuery::Wrapper &query);
    // 分页查询数据
    std::list<CheckDO> selectWithPage(const CheckQuery::Wrapper &query);
    // 不分页查询数据
    std::list<CheckDO> selectWithConditions(const CheckQuery::Wrapper &query);
};
#endif // !_CHECK_DAO_
