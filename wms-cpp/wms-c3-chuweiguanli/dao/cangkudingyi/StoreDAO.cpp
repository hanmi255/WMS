#include "stdafx.h"
#include "StoreDAO.h"
#include "../lib-common/include/id/SnowFlake.h"


#define ADD_PARAM `create_name`, `create_by`, `create_date`
#define Modify_PARAM `update_name`, `update_by`, `update_date`

string get_id()
{
	SnowFlake sf(1, 1);
	return to_string(sf.nextId());
}

string StoreDAO::add(const StoreDO& obj)
{
	string Id = get_id();
	string sql = "INSERT INTO `ba_store` \
		(`store_code`, `store_name`, `store_text`,\
		`create_name`, `create_by`, `create_date`,  \
		`sys_org_code`,`sys_company_code`, `id`)\
		VALUES(? , ? , ? , ? , ? , ? , ? , ? , ?)";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", 
		obj.getStoreCode(), 
		obj.getStoreName(),
		obj.getStoreText(),
		obj.getCreateName(), 
		obj.getCreateBy(), 
		obj.getCreateDate(),
		obj.getSysOrgCode(), 
		obj.getSysCompanyCode(), Id);
	if (res > 0)
	{
		return Id;
	}
	return string{"failed"};
}

string StoreDAO::modify(const StoreDO& obj)
{
	string sql = R"(UPDATE `ba_store`
SET 
    `store_code` = COALESCE(NULLIF(?, ''), `store_code`),
    `store_name` = COALESCE(NULLIF(?, ''), `store_name`),
    `store_text` = COALESCE(NULLIF(?, ''), `store_text`),
    `update_name` = ?,
    `update_by` = ?,
    `update_date` = ?
WHERE `id` = ?)";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s",
		obj.getStoreCode(),
		obj.getStoreName(),
		obj.getStoreText(),
		obj.getUpdateName(),
		obj.getUpdateBy(),
		obj.getUpdateDate(),
		obj.getId());
	if (res > 0)
	{
		return obj.getId();
	}
	return string{ "failed" };
}