
#include "stdafx.h"
#include"DelEduCodeDAO.h"
#include"DelEduCodeMapper.h"
#include <sstream>


//É¾³ý½ÇÉ«ÐÅÏ¢
int EducationalDAO::deleteById(string id)
{
	//tring sql = "INSERT INTO `org_role` (`xname`, `xunique`, `xsequence`) VALUES (?, ?, ?)";
	//return sqlSession->executeInsert(sql, "%s%s%s", iObj.getName(), iObj.getKey(), iObj.getRefer());
	string sql = "DELETE FROM `ba_edu_sta` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

uint64_t EducationalDAO::insertEduCode(const EducationalDTO::Wrapper& dto, const PayloadDTO auth)
{
	stringstream sql;
	sql << "INSERT INTO ba_edu_sta (`id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`edu_sta_code`,`edu_sta_name`) \
VALUES (?,?,?,?,?,?,?,?,?,?,?)";
	string time = SimpleDateTimeFormat::format();
	SnowFlake ls(0, 5);
	string id = std::to_string(ls.nextId());

	uint64_t count = sqlSession->executeUpdate(sql.str(), "%s%s%s%s%s%s%s%s%s%s%s", id, auth.getUsername(),
		auth.getRealname(), time, auth.getUsername(), auth.getRealname(),
		time, auth.getOrgcode(), auth.getCompanycode(), dto->code.getValue({}), dto->name.getValue({}));

	//std::cout << count << std::endl;

	return count;
}

std::list<EduCodeDO> EducationalDAO::exportEduInfo()
{
	std::string sql = "SELECT edu_sta_code,edu_sta_name FROM ba_edu_sta";
	EduCodeMapper mapper;
	return sqlSession->executeQuery<EduCodeDO>(sql, mapper);
}

#define GET(val) uObj.get##val()
int EducationalDAO::update(const EduCodeDO& uObj)
{
	string sql = "UPDATE `ba_edu_sta` SET  `update_name`,`update_by`,`update_date`,`edu_sta_code`=?, `edu_sta_code`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", GET(Update_name), GET(Update_by), GET(Update_date), GET(Edu_sta_code), GET(Edu_sta_code), GET(Id));
}
#undef GET