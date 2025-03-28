#include "stdafx.h"
#include "RegionInfoDAO.h"
#include "RegionInfoMapper.h"
#include <sstream>

uint64_t RegionInfoDAO::insert(const RegionInfoDO& iObj)
{
	string sql = "INSERT INTO `ba_barea` (`id`,`create_name`, `create_by`, `create_date`, `update_name`, `update_by`, `update_date`, `sys_org_code`, `sys_company_code`, `barea_code`, `barea_name`, `barea_rdata`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%d", iObj.getId(), iObj.getCreate_name(), iObj.getCreate_by(), iObj.getCreate_date(), iObj.getUpdate_name(), iObj.getUpdate_by(), iObj.getUpdate_date(), iObj.getSys_org_code(), iObj.getSys_company_code(), iObj.getRegion_code(), iObj.getRegion_name(), iObj.getRegion_rdata());
}
void RegionInfoDAO::insert(const list<RegionInfoDO>& iObj)
{
	for (auto sub : iObj)
	{
		insert(sub);
	}
}
uint64_t RegionInfoDAO::remove(std::string region_code)
{
	string sql = "DELETE FROM `ba_barea` WHERE `barea_code`=?";
	return sqlSession->executeUpdate(sql, "%s", region_code);
}
uint64_t RegionInfoDAO::update(const RegionInfoDO& iObj)
{
	string sql = "UPDATE `ba_barea` SET `barea_code`=?, `barea_name`=?, `barea_rdata`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%d%s", iObj.getRegion_code(), iObj.getRegion_name(), (double)iObj.getRegion_rdata(), iObj.getId());
}
std::list<RegionNameDO> RegionInfoDAO::selectByName()
{
	std::string sql;
	RegionNameMapper mapper;
		sql = "SELECT DISTINCT id,area_name FROM ba_area";
		return sqlSession->executeQuery<RegionNameDO>(sql, mapper);
}