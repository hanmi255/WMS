/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 19:02:17

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CostAttributeDAO.h"
#include "CostAttributeMapper.h"
#include "CostAttributeDAO.h"
#include <sstream>
//#include "id/SnowFlake.h"


// 查询条件构建器
std::string CostAttributeDao::queryConditionBuilder(const CostSxQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    
    // 客户属性名称
    if (query->name) {
        sqlCondition << " AND `kehushuxing_name`=?"; // 使用字段
        SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
    }

    // 客户属性代码
    if (query->code) {
        sqlCondition << " AND `kehushuxing_code`=?"; // 使用字段
        SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue(""));
    }

    // 创建人名称
    if (query->createName) {
        sqlCondition << " AND `create_name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->createName.getValue(""));
    }

    // 创建人记录
    if (query->createBy) {
        sqlCondition << " AND `create_by`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->createBy.getValue(""));
    }

    //// 创建时间
    //if (query->create_date) {
    //    sqlCondition << " AND `create_date`=?";
    //    SQLPARAMS_PUSH(params, "s", std::string, query->create_date.getValue(""));
    //}

    // 更新人名称
    if (query->updateName) {
        sqlCondition << " AND `update_name`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->updateName.getValue(""));
    }

    // 更新人记录
    if (query->updateBy) {
        sqlCondition << " AND `update_by`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->updateBy.getValue(""));
    }

    //// 更新时间
    //if (query->update_date) {
    //    sqlCondition << " AND `update_date`=?";
    //    SQLPARAMS_PUSH(params, "s", std::string, query->update_date.getValue(""));
    //}

    // 系统组织代码
    if (query->sysOrgCode) {
        sqlCondition << " AND `sys_org_code`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->sysOrgCode.getValue(""));
    }

    // 系统公司代码
    if (query->sysCompanyCode) {
        sqlCondition << " AND `sys_company_code`=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->sysCompanyCode.getValue(""));
    }
    
    return sqlCondition.str();
}

// 插入
std::string CostAttributeDao::insert(const CostSxDO& iObj)
{   
    //// 使用雪花算法生成ID
    //SnowFlake sf(1, 1);
    //std::string id = std::to_string(sf.nextId());

    UuidFacade uf(1);
    std::string id = uf.genUuid();

    string sql = "INSERT INTO `ba_kehushuxing` ("
        "`id`, `kehushuxing_code`, `kehushuxing_name`, "
        "`create_name`, `create_by`,`create_date` , "
        "`update_name`, `update_by`, `update_date`, "
        "`sys_org_code`, `sys_company_code`) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    if (sqlSession->executeUpdate(sql,
        "%s%s%s%s%s%s%s%s%s%s%s",
        id,
        iObj.getCode(),
        iObj.getName(),
        iObj.getCreateName(),
        iObj.getCreateBy(),
        iObj.getCreateDate(),
        iObj.getUpdateName(),
        iObj.getUpdateBy(),
        iObj.getUpdateDate(),
        iObj.getSysOrgCode(),
        iObj.getSysCompanyCode()) == 1) {
        return id;
    }
    return "";
}

// 修改
bool CostAttributeDao::update(const CostSxDO& iObj)
{
    string sql = "UPDATE `ba_kehushuxing` SET "
        "`kehushuxing_code` = ?, "
        "`kehushuxing_name` = ?, "
        "`update_name` = ?, "
        "`update_by` = ?,"
        "`update_date` = ?,"
        "`sys_org_code` = ?,"
        "`sys_company_code` = ? "
        "WHERE `id` = ? ";

    return sqlSession->executeUpdate(sql,
        "%s%s%s%s%s%s%s%s",
        iObj.getCode(),
        iObj.getName(),
        iObj.getUpdateName(),
        iObj.getUpdateBy(),
        iObj.getUpdateDate(),
        iObj.getSysOrgCode(),
        iObj.getSysCompanyCode(),
        iObj.getId()) == 1;
}

uint64_t CostAttributeDao::count(const CostSxQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM `ba_kehushuxing` ";
    // 使用查询条件构建器
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CostSxDO> CostAttributeDao::selectNameWithPage(const CostSxQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT `id`,`kehushuxing_name` FROM `ba_kehushuxing` ";
    // 使用查询条件构建器
    sql += queryConditionBuilder(query, params);
   

    // 执行查询
    CostAttributeMapperName mapper;
    return sqlSession->executeQuery<CostSxDO>(sql, mapper, params);
}

std::list<CostSxDO> CostAttributeDao::selectAllWithPage(const CostSxQuery::Wrapper& query)
{
    SqlParams params;
    // 使用 SELECT 语句，查询所有字段
    string sql = "SELECT "
        "`id`, "                           // 主键
        "`kehushuxing_code`, "             // 客户属性代码
        "`kehushuxing_name`, "             // 客户属性名称
        "`create_name`, "                  // 创建人名称
        "`create_by`, "                    // 创建人记录
        "`update_name`, "                  // 更新人名称
        "`update_by`, "                    // 更新人记录
        "`sys_org_code`, "                // 系统组织代码
        "`sys_company_code`, "              // 系统公司代码
        "`create_date`, "                  // 创建时间
        "`update_date` "                  // 更新时间
        "FROM `ba_kehushuxing` ";
    // 使用查询条件构建器
    sql += queryConditionBuilder(query, params);
    // 使用分页参数
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    CostAttributeMapperAll mapper;
    return sqlSession->executeQuery<CostSxDO>(sql, mapper, params);
}
// 删除客户计费属性
int CostAttributeDAO::deleteCostAttribute(const string& id) {
    string sql = "DELETE FROM `ba_kehushuxing` WHERE `id` = ?";
    return sqlSession->executeUpdate(sql, "%s", id);
}

// 导入客户计费属性
uint64_t CostAttributeDAO::importCostAttribute(const CostAttributeDO& dataDO) {
    string sql = "INSERT INTO `ba_kehushuxing` ("
        "`id`,"
        "`create_name`,"
        "`create_by`,"
        "`create_date`,"
        "`update_name`,"
        "`update_by`,"
        "`update_date`,"
        "`sys_org_code`,"
        "`sys_company_code`,"
        "`kehushuxing_code`,"
        "`kehushuxing_name`"
        ") VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s", dataDO.getId(), dataDO.getCreateName(), dataDO.getCreateBy(), dataDO.getCreateDate(), dataDO.getUpdateName(), dataDO.getUpdateBy(), dataDO.getUpdateDate(), dataDO.getSysOrgCode(), dataDO.getSysCompanyCode(), dataDO.getKeHuShuXingCode(), dataDO.getKeHuShuXingName());
}

// 导出客户计费属性
std::list<CostAttributeDO>CostAttributeDAO::exportCostAttribute(void) {
    string sql = "SELECT `kehushuxing_code`, `kehushuxing_name` FROM `ba_kehushuxing`";
    ExportCostAttributeMapper mapper;
    return sqlSession->executeQuery<CostAttributeDO>(sql, mapper);
}
