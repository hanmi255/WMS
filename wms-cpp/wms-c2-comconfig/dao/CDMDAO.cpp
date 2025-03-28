#include "stdafx.h"
#include "CDMDAO.h"
#include "../lib-common/include/id/SnowFlake.h"
#include "id/UuidFacade.h"




 string CdmDAO::modify(const CdmDO& obj)
 {
	string sql = R"(UPDATE `ba_store`
 SET 
    `Cdm_name` = COALESCE(NULLIF(?, ''), `Cdm_name`),
    `update_name` = ?,
   `update_date` = ?
WHERE `id` = ?)";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s",
		obj.getCname(),
		obj.getId());
	if (res > 0)
	{
		return obj.getId();
	}
	return string{ "failed" };
 }