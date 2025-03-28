#include "stdafx.h"
#include "GoodsStateDAO.h"
#include "GoodsStateMapper.h"
#include "domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"
#include <cstdarg> // 用于可变参数
// 批量删除
int GoodsStateDAO::deleteByIds(const std::vector<std::string>& ids) {
    if (ids.empty()) {
        OATPP_LOGE("GoodsStateDAO", "No IDs provided for batch deletion");
        return 0;
    }
    // 构建 SQL 语句，动态生成占位符
    std::string sql = "DELETE FROM `ba_qm_sta` WHERE `id` IN (";
    for (size_t i = 0; i < ids.size(); ++i) {
        sql += "?";
        if (i < ids.size() - 1) {
            sql += ",";
        }
    }
    sql += ")";

    // 动态构建参数列表
    std::vector<std::string> params;
    for (const auto& id : ids) {
        if (id.empty()) {
            OATPP_LOGE("GoodsStateDAO", "Empty ID found in batch deletion");
            return 0;
        }
        params.push_back(id);
    }

    // 调用 SqlSession 的 executeUpdate 方法
    try {
        return sqlSession->executeUpdate(sql, params);
    }
    catch (const std::exception& e) {
        OATPP_LOGE("GoodsStateDAO", "Failed to execute batch delete: %s", e.what());
        return 0;
    }
}
//插入数据
uint64_t GoodsStateDAO::insert(const GoodsStateControllerDO& iObj) {
	std::string sql = "INSERT INTO ba_qm_sta (id, create_name, create_by, create_date, update_name, update_by, update_date, sys_org_code, sys_company_code, qm_sta_code, qm_sta_name) "
		"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s",
		iObj.getId(), iObj.getCreate_name(), iObj.getCreate_by(), iObj.getCreate_date(),
		iObj.getUpdate_name(), iObj.getUpdate_by(), iObj.getUpdate_date(),
		iObj.getSys_org_code(), iObj.getSys_company_code(), iObj.getQm_sta_code(), iObj.getQm_sta_name());
}
// 分页查询数据表中的数据
std::list<GoodsStateControllerDO> GoodsStateDAO::QueryWithPage(const GoodStateQuery::Wrapper& query)
{
	std::list<GoodsStateControllerDO> res;
	std::string sql = "SELECT * FROM ba_qm_sta";
	// 1.执行查询
	GoodsStateMapper mapper;
    res = sqlSession->executeQuery<GoodsStateControllerDO>(sql, mapper);
	//1.2 检查查询结果是否为空 判空处理很重要*****
	if (res.empty()) {
		OATPP_LOGE("GoodsStateDAO", "Query returned no results");
	}
	return res;
}