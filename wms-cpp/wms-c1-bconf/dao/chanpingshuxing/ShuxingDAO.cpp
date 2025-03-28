#include "stdafx.h"
#include "ShuxingDAO.h"


int ShuxingDAO::update(const ShuxingDO& sdo)
{
	string sql = "UPDATE `ba_goods_type` SET `update_name`=?,`update_by`= ? ";
	sql+=", `update_date`= NOW(), `goods_type_name`= ? ,`goods_type_code`=? WHERE `id`= ? ";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", sdo.getUpdate_name(),
		sdo.getUpdate_by(), sdo.getGoods_type_name(),sdo.getGoods_type_code(), sdo.getId());
}

int ShuxingDAO::delete_data(const vector<ShuxingDO>& sdos)
{
	string sql = "DELETE FROM `ba_goods_type` WHERE `id`= ? ";
	int ans = 0;
	for (auto& i : sdos) {
		ans += sqlSession->executeUpdate(sql, "%s", i.getId());
	}
	return ans;
}

std::list<ShuxingDO> ShuxingDAO::upload_data()
{
	string sql = "SELECT goods_type_name,goods_type_code  FROM `ba_goods_type` ";
	ShuxingMapper mapper;
	
	return sqlSession->executeQuery<ShuxingDO>(sql, mapper);
}

int ShuxingDAO::load_data(const ShuxingDO& sdos)
{
	string sql = "INSERT INTO `ba_goods_type`(";
	SqlParams params;
	stringstream sqlcontidion1, sqlcontidion2;
	sqlcontidion2 << "VALUES(";
	if (sdos.getCreate_name().size()) {
		sqlcontidion1 << "create_name,";
		sqlcontidion2 << "?,";
		SQLPARAMS_PUSH(params, "s", std::string, sdos.getCreate_name());
	}
	if (sdos.getCreate_by().size()) {
		sqlcontidion1 << "create_by,";
		sqlcontidion2 << "?,";
		SQLPARAMS_PUSH(params, "s", std::string, sdos.getCreate_by());
	}
	if (sdos.getSys_org_code().size()) {
		sqlcontidion1 << "sys_org_code,";
		sqlcontidion2 << "?,";
		SQLPARAMS_PUSH(params, "s", std::string, sdos.getSys_org_code());
	}
	if (sdos.getSys_company_code().size()) {
		sqlcontidion1 << "sys_company_code,";
		sqlcontidion2 << "?,";
		SQLPARAMS_PUSH(params, "s", std::string, sdos.getSys_company_code());
	}
	if (sdos.getGoods_type_code().size()) {
		sqlcontidion1 << "goods_type_code,";
		sqlcontidion2 << "?,";
		SQLPARAMS_PUSH(params, "s", std::string, sdos.getGoods_type_code());
	}
	if (sdos.getGoods_type_name().size()) {
		sqlcontidion1 << "goods_type_name,";
		sqlcontidion2 << "?,";
		SQLPARAMS_PUSH(params, "s", std::string, sdos.getGoods_type_name());
	}
	sqlcontidion1 << "id,create_date)";
	sqlcontidion2 << "?,NOW())";
	sql += sqlcontidion1.str() + sqlcontidion2.str();
	
	/*SnowFlake sf(1,1);
	SQLPARAMS_PUSH(params, "s", std::string, to_string(sf.nextId()));*/
	UuidFacade uuid;
	SQLPARAMS_PUSH(params, "s", std::string, uuid.genUuid());
	//cout << sql;
	return sqlSession->executeUpdate(sql,params);
}

 
