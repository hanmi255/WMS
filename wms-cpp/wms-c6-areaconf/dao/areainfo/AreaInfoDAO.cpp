#include "stdafx.h"
#include "AreaInfoDAO.h"
#include "AreaInfoMapper.h"


bool AreaInfoDAO::delet(const string& id)
{
	string sql = "DELETE FROM `ba_city` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id) == 1;
}

#define GET(val) uObj.get##val()
bool AreaInfoDAO::update(const AreaInfoUpdDO& uObj)
{
	std::string sql = "UPDATE `ba_city` SET  `update_name`=?,`update_by`=?,`update_date`=?,`sys_org_code`=?,`sys_company_code`=?,`city_name`=?,`city_serc`=?,`city_type_code`=(SELECT `city_type_code` FROM `ba_city_type` WHERE `city_type_name`=?),`barea_code`=(SELECT `barea_code` FROM `ba_barea` WHERE `barea_name`=?),`darea_code`=(SELECT `area_code` FROM `ba_area` WHERE `area_name`=?),`city_del`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s", GET(Update_name), GET(Update_by), GET(Update_date), GET(Sys_org_code), GET(Sys_company_code), GET(City_name), GET(City_serc), GET(City_type_code), GET(Barea_code), GET(Darea_code), GET(City_del), GET(Id)) == 1;
}
#undef GET

#define GET(val) obj.get##val()
bool AreaInfoDAO::insertUplExl(const std::list<AreaInfoAddDO>& iObj)
{
	for (const AreaInfoAddDO& obj : iObj)
	{
		std::string sql = "INSERT INTO `ba_city` (`id`, `create_name`, `create_by`, `create_date`,`update_name`, `update_by`, `update_date`,`sys_org_code`,`sys_company_code`, `city_code`, `city_name`, `city_serc`,`city_type_code`, `barea_code`, `darea_code`, `city_del`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, (SELECT `city_type_code` FROM `ba_city_type` WHERE `city_type_name`=?), (SELECT `barea_code` FROM `ba_barea` WHERE `barea_name`=?), (SELECT `area_code` FROM `ba_area` WHERE `area_name`=?), ?)";
		sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", GET(Id), GET(Create_name), GET(Create_by), GET(Create_date), GET(Update_name), GET(Update_by), GET(Update_date), GET(Sys_org_code), GET(Sys_company_code), GET(City_code), GET(City_name), GET(City_serc), GET(City_type_code), GET(Barea_code), GET(Darea_code), GET(City_del));
	}
	return true;
}
#undef GET

std::list<AreaInfoDO> AreaInfoDAO::select()
{
	std::string sql = "SELECT a.city_code,a.city_name,a.city_serc,b.city_type_name,c.barea_name,d.area_name,a.city_del FROM ba_city a LEFT JOIN ba_city_type b ON a.city_type_code=b.city_type_code LEFT JOIN ba_barea c ON a.barea_code=c.barea_code LEFT JOIN ba_area d ON a.darea_code=d.area_code";
	AreaInfoMapper mapper;
	return sqlSession->executeQuery<AreaInfoDO>(sql, mapper);
}

std::list<AreaNameTreeDO> AreaInfoDAO::selectName()
{
	std::string sql = "SELECT id,city_code,city_name FROM ba_city";
	AreaNameTreeMapper mapper;
	return sqlSession->executeQuery<AreaNameTreeDO>(sql, mapper);
}

#define GET(val) uObj.get##val()
bool AreaInfoDAO::add(const AreaInfoAddDO& uObj)
{
	string sql = "INSERT INTO `ba_city` (`id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`city_code`,`city_name`,`city_serc`,`city_type_code`,`barea_code`,`darea_code`,`city_del`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,(SELECT `city_type_code` FROM `ba_city_type` WHERE `city_type_name`=?), (SELECT `barea_code` FROM `ba_barea` WHERE `barea_name`=?), (SELECT `area_code` FROM `ba_area` WHERE `area_name`=?), ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", GET(Id), GET(Create_name), GET(Create_by), GET(Create_date), GET(Update_name), GET(Update_by), GET(Update_date), GET(Sys_org_code), GET(Sys_company_code), GET(City_code), GET(City_name), GET(City_serc), GET(City_type_code), GET(Barea_code), GET(Darea_code), GET(City_del)) == 1;
}
#undef GET

std::list<AreaInfoListDO> AreaInfoDAO::selectList(const AreaInfoQuery::Wrapper& query)
{
	SqlParams params;
	std::string sql = "SELECT a.id,a.city_code,a.city_name,a.city_serc,b.city_type_name,c.barea_name,d.area_name,a.city_del FROM ba_city a LEFT JOIN ba_city_type b ON a.city_type_code=b.city_type_code LEFT JOIN ba_barea c ON a.barea_code=c.barea_code LEFT JOIN ba_area d ON a.darea_code=d.area_code";
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->city_code)
	{
		sqlCondition << " AND a.city_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->city_code.getValue(""));
	}
    if (query->city_name)
	{
		sqlCondition << " AND a.city_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->city_name.getValue(""));
	}
	if (query->city_serc)
	{
		sqlCondition << " AND a.city_serc=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->city_serc.getValue(""));
	}
	if (query->city_type_name)
	{
		sqlCondition << " AND b.city_type_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->city_type_name.getValue(""));
	}
	if (query->barea_name)
	{
		sqlCondition << " AND c.barea_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->barea_name.getValue(""));
	}
	if (query->area_name)
	{
		sqlCondition << " AND d.area_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->area_name.getValue(""));
	}
	if (query->city_del)
	{
		sqlCondition << " AND a.city_del=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->city_del.getValue(""));
	}
	sql += sqlCondition.str();
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	AreaInfoListMapper mapper;
	return sqlSession->executeQuery<AreaInfoListDO>(sql, mapper, params);
}