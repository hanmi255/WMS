#include "stdafx.h"
#include "CheckDAO.h"
#include "CheckMapper.h"
#include <sstream>
inline std::string CheckDAO::queryConditionBuilder(const CheckQuery::Wrapper &query, SqlParams &params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->bin_id)
    {

        sqlCondition << " AND bin_id= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
    }
    if (query->tin_id)
    {

        sqlCondition << " AND tin_id= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
    }
    if (query->goods_id)
    {

        sqlCondition << " AND goods_id= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
    }
    if (query->goods_name)
    {

        sqlCondition << " AND `goods_name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
    }
    if (query->goods_qua)
    {

        sqlCondition << " AND `goods_qua`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_qua.getValue(""));
    }
    if (query->goods_unit)
    {

        sqlCondition << " AND `goods_unit`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_unit.getValue(""));
    }
    if (query->goods_pro_data)
    {

        sqlCondition << " AND `goods_pro_data`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data.getValue(""));
    }
    if (query->goods_batch)
    {

        sqlCondition << " AND `goods_batch`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->goods_batch.getValue(""));
    }
    if (query->stt_qua)
    {

        sqlCondition << " AND `stt_qua`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->stt_qua.getValue(""));
    }
    if (query->cus_name)
    {

        sqlCondition << " AND `cus_name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cus_name.getValue(""));
    }
    if (query->cus_code)
    {

        sqlCondition << " AND `cus_code`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cus_code.getValue(""));
    }
    if (query->stt_sta)
    {

        sqlCondition << " AND `stt_sta`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->stt_sta.getValue(""));
    }
    if (query->create_name)
    {

        sqlCondition << " AND `create_name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_name.getValue(""));
    }
    if (query->create_date)
    {

        sqlCondition << " AND create_date=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->create_date.getValue(""));
    }
    if (query->update_name)
    {

        sqlCondition << " AND update_name=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->update_name.getValue(""));
    }
    if (query->update_by)
    {

        sqlCondition << " AND update_by=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->update_by.getValue(""));
    }
    if (query->update_date)
    {

        sqlCondition << " AND update_date=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->update_date.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t CheckDAO::count(const CheckQuery::Wrapper &query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM wm_stt_in_goods ";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CheckDO> CheckDAO::selectWithPage(const CheckQuery::Wrapper &query)
{
    SqlParams params;
    // string sql = "SELECT id,bin_id,tin_id,goods_id,goods_name,goods_qua,goods_unit,goods_pro_data,goods_batch,stt_qua,cus_name,cus_code,stt_sta,create_name,create_date,update_name,update_by,update_date FROM wm_stt_in_goods ";
    string sql = "SELECT * FROM wm_stt_in_goods ";

    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    CheckMapper mapper;
    return sqlSession->executeQuery<CheckDO>(sql, mapper, params);
}
