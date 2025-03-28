#include "stdafx.h"
#include "BaActTypeDAO.h"

#include <sstream>

std::string BaActTypeDAO::queryConditionBuilder(const BaActTypeQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->act_type_code)
    {
        sqlCondition << " AND `act_type_code` LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->act_type_code.getValue(""));
    }
    if (query->act_type_name)
    {
        sqlCondition << " AND `act_type_name` LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->act_type_name.getValue(""));
    }
    if (query->oper_step_code)
    {
        sqlCondition << " AND `oper_step_code` LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->oper_step_code.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t BaActTypeDAO::count(const BaActTypeQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT COUNT(*) FROM ba_act_type ";
    sql += queryConditionBuilder(query, params);
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<BaActTypeDO> BaActTypeDAO::selectWithPage(const BaActTypeQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT id, create_name, create_by, create_date, update_name, update_by, update_date, "
                      "sys_org_code, sys_company_code, act_type_code, act_type_name, oper_step_code FROM ba_act_type ";
    sql += queryConditionBuilder(query, params);
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    BaActTypeMapper mapper;
    return sqlSession->executeQuery<BaActTypeDO>(sql, mapper, params);
}




PtrBaActTypeDO BaActTypeDAO::selectById(const std::string& id)
{
    std::string sql = "SELECT id, create_name, create_by, create_date, update_name, update_by, update_date, "
                      "sys_org_code, sys_company_code, act_type_code, act_type_name, oper_step_code FROM ba_act_type WHERE `id`=?";
    PtrBaActTypeMapper mapper;
    return sqlSession->executeQueryOne<PtrBaActTypeDO>(sql, mapper, "%s", id);
}

uint64_t BaActTypeDAO::insert(const BaActTypeDO& iObj)
{
    std::string sql = "INSERT INTO `ba_act_type` "
                      "(`id`, `create_name`, `create_by`, `create_date`, `update_name`, `update_by`, `update_date`, "
                      "`sys_org_code`, `sys_company_code`, `act_type_code`, `act_type_name`, `oper_step_code`) "
                      "VALUES (?, ?, ?, now(), ?, ?, now(), ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s",
        iObj.getId(),
        iObj.getCreateName(),
        iObj.getCreateBy(),
        iObj.getUpdateName(),
        iObj.getUpdateBy(),
        iObj.getSysOrgCode(),
        iObj.getSysCompanyCode(),
        iObj.getActTypeCode(),
        iObj.getActTypeName(),
        iObj.getOperStepCode());
}


uint64_t BaActTypeDAO::insert_noid(const BaActTypeDO& iObj)
{
    std::string sql = "INSERT INTO `ba_act_type` "
        "(`id`, `create_name`, `create_by`, `create_date`, `update_name`, `update_by`, `update_date`, "
        "`sys_org_code`, `sys_company_code`, `act_type_code`, `act_type_name`, `oper_step_code`) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s",
        iObj.getId(),
        iObj.getCreateName(),
        iObj.getCreateBy(),
        iObj.getCreateDate(),
        iObj.getUpdateName(),
        iObj.getUpdateBy(),
        iObj.getUpdateDate(),
        iObj.getSysOrgCode(),
        iObj.getSysCompanyCode(),
        iObj.getActTypeCode(),
        iObj.getActTypeName(),
        iObj.getOperStepCode());
}



int BaActTypeDAO::update(const BaActTypeDO& uObj)
{
    std::string sql = "UPDATE `ba_act_type` SET "
                      "`act_type_code`=?, `act_type_name`=?, `oper_step_code`=?, `update_date`=now() WHERE `id`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%s",
        uObj.getActTypeCode(),
        uObj.getActTypeName(),
        uObj.getOperStepCode(),
        uObj.getId());
}

int BaActTypeDAO::deleteById(const std::string id)
{
    std::string sql = "DELETE FROM `ba_act_type` WHERE `id`=?";

    return sqlSession->executeUpdate(sql, "%s", id);
}



std::list<BaActTypeDO> BaActTypeDAO::listAllDO() {
    std::string sql = "SELECT * FROM `ba_act_type`";
    BaActTypeMapperAll mapper;
    return sqlSession->executeQuery<BaActTypeDO>(sql, mapper);
}