#define _CRT_SECURE_NO_WARNINGS
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/3/4 11:08

*/
#include "stdafx.h"
#include "ListgoodsDAO.h"
#include "ListgoodsMapper.h"
#include <sstream>

inline std::string ListGoodsDAO::queryConditionBuilder(const ExportDataQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 储位
    if (query->creloginame)
    {
        sqlCondition << "AND `creloginame` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->creloginame.getValue(""));
    }

    // 创建日期--起始（假设数据库列名为 `create_date`）
    if (query->credate_start)
    {
        sqlCondition << " AND `create_date` >=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->credate_start.getValue(""));
    }

    // 创建日期--终止（假设数据库列名为 `create_date`）
    if (query->credate_end)
    {
        sqlCondition << " AND `create_date` <=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->credate_end.getValue(""));
    }

    // 商品编码
    if (query->goodscode)
    {
        sqlCondition << " AND `goods_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goodscode.getValue(""));
    }

    // 商品名称
    if (query->goodsname)
    {
        sqlCondition << " AND `goods_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goodsname.getValue(""));
    }
    // 原始单据编码
    if (query->orgbillcode)
    {
        sqlCondition << " AND `order_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->orgbillcode.getValue(""));
    }

    //库位编码
    if (query->kuweicode)
    {
        sqlCondition << " AND `ku_wei_bian_ma` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->kuweicode.getValue(""));
    }

    // 托盘码
    if (query->tuobancode)
    {
        sqlCondition << " AND `bin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->tuobancode.getValue(""));
    }

    // 货主
    if (query->huozhu)
    {
        sqlCondition << " AND `cus_code` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->huozhu.getValue(""));
    }
    return sqlCondition.str();
}

// 统计数据条数
uint64_t ListGoodsDAO::count(const ExportDataQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM wm_to_up_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}

// 分页查询数据 wm_stt_in_goods
std::list<Wm_To_Up_GoodsDO> ListGoodsDAO::selectWithPage(const ExportDataQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_to_up_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    ListGoodsMapper mapper;
    return sqlSession->executeQuery<Wm_To_Up_GoodsDO>(sql, mapper, params);
}

// 查询数据---不分页
std::list<Wm_To_Up_GoodsDO> ListGoodsDAO::selectWithConditions(const ExportDataQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_to_up_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    ListGoodsMapper mapper;
    return sqlSession->executeQuery<Wm_To_Up_GoodsDO>(sql, mapper, params);
}

