#define _CRT_SECURE_NO_WARNINGS
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#include "stdafx.h"
#include "GoodsManageDAO.h"
#include "GoodsManageMapper.h"
#include <sstream>


inline std::string GoodsManageDAO::queryConditionBuilder(const GoodsDiffPostQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
    // 储位
    if (query->bin_id)
    {
        sqlCondition << "AND `bin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
    }

    // 托盘
    if (query->tin_id)
    {
        sqlCondition << " AND `tin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
    }

    // 商品编码
    if (query->goods_id)
    {
        sqlCondition << " AND `goods_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
    }

    // 商品名称
    if (query->goods_name)
    {
        sqlCondition << " AND `goods_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
    }

    // 生产日期
    if (query->goods_pro_data)
    {
        sqlCondition << " AND `goods_pro_data` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data.getValue(""));
    }

    // 批次
    if (query->goods_batch)
    {
        sqlCondition << " AND `goods_batch` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_batch.getValue(""));
    }

    // 货主名称
    if (query->cus_name)
    {
        sqlCondition << " AND `cus_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cus_name.getValue(""));
    }

    // 货主
    if (query->cus)
    {
        sqlCondition << " AND `cus` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cus.getValue(""));
    }

    // 盘点状态
    if (query->stt_sta)
    {
        sqlCondition << " AND `stt_sta` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->stt_sta.getValue(""));
    }

    // 创建日期--起始（假设数据库列名为 `create_date`）
    if (query->create_date_start)
    {
        sqlCondition << " AND `create_date` >=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_date_start.getValue(""));
    }

    // 创建日期--终止（假设数据库列名为 `create_date`）
    if (query->create_date_end)
    {
        sqlCondition << " AND `create_date` <=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_date_end.getValue(""));
    }
	return sqlCondition.str();
}

// 统计数据条数
uint64_t GoodsManageDAO::count(const GoodsDiffPostQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM wm_stt_in_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}

// 分页查询数据 wm_stt_in_goods
std::list<Wm_Stt_In_GoodsDO> GoodsManageDAO::GoodsManageDAO::selectWithPage(const GoodsDiffPostQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_stt_in_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex-1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    GoodsManageMapper mapper;
    return sqlSession->executeQuery<Wm_Stt_In_GoodsDO>(sql, mapper, params);
}

// 查询数据---不分页
std::list<Wm_Stt_In_GoodsDO> GoodsManageDAO::selectWithConditions(const GoodsDiffPostQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_stt_in_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    GoodsManageMapper mapper;
    return sqlSession->executeQuery<Wm_Stt_In_GoodsDO>(sql, mapper, params);
}

// 通过姓名查询数据
//std::list<Wm_Stt_In_GoodsDO> GoodsManageDAO::selectByName(const string& name)
// {
// 
// }
// 通过ID查询数据
PtrWm_Stt_In_GoodsDO GoodsManageDAO::selectById(uint64_t id)
{
    return {};
}
// 插入数据
uint64_t GoodsManageDAO::insert(const Wm_Stt_In_GoodsDO& iObj)
{
    return {};
}
// 修改数据
int GoodsManageDAO::update(const Wm_Stt_In_GoodsDO& uObj, const PayloadDTO& payload)
{
    if (stoi(uObj.getGoodsQua()) <= stoi(uObj.getSttQua()))
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* now_tm = std::localtime(&now_c);

        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
        std::string date = std::string(buffer);
        string sql = "UPDATE `wm_stt_in_goods` SET `stt_sta`=?, `update_name` = ?, `update_by` = ?,`update_date` = ? WHERE `id`=?";
        return sqlSession->executeUpdate(sql, "%s%s%s%s%s", ZH_WORDS_GETTER("diff-post.goods.stt_sta.sta2"), payload.getUsername(), payload.getRealname(),date, uObj.getId());
    }
    return 0;
}
// 通过ID删除数据
int GoodsManageDAO::deleteById(uint64_t id)
{
    return {};
}