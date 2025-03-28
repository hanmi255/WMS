#include "StuCodeDAO.h"
#define STUCODE_TERAM_PARSE(query,sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `sex_sta_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->code) { \
	sql << " AND `sex_sta_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \
} 

list<StuCodeDO> StuCodeDAO::selectStuCodeWithPage(const StuCodeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT sex_sta_name,sex_sta_code,id FROM ba_sex_sta";
	STUCODE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	StuCodeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<StuCodeDO, StuCodeMapper>(sqlStr, mapper, params);
}

uint64_t StuCodeDAO::countCode(const StuCodeQuery::Wrapper& query)
{
	std::cout << "=-------=-=-=-=========" << std::endl;
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `ba_sex_sta` ";
	STUCODE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t StuCodeDAO::updateStuCode(const StuCodeDTO::Wrapper& dto, const PayloadDTO auth)
{
	stringstream sql;
	sql << "UPDATE ba_sex_sta SET updata_name = ?,updata_by = ?,updata_date = ?,sys_org_code = ?,sys_company_code = ?,sex_sta_name = ?,sex_sta_code = ? WHERE id = ?";
	string time = SimpleDateTimeFormat::format();
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, auth.getUsername());
	SQLPARAMS_PUSH(params, "s", std::string, auth.getRealname());
	SQLPARAMS_PUSH(params, "s", std::string, time);
	SQLPARAMS_PUSH(params, "s", std::string, auth.getOrgcode());
	SQLPARAMS_PUSH(params, "s", std::string, auth.getCompanycode());
	SQLPARAMS_PUSH(params, "s", std::string, dto->name.getValue({}));
	SQLPARAMS_PUSH(params, "s", std::string, dto->code.getValue({}));
	SQLPARAMS_PUSH(params, "s", std::string, dto->id.getValue({}));
	uint64_t count = 0;
	//sqlSession->beginTransaction();
	count += sqlSession->executeUpdate(sql.str(), params);
	return count;
}

uint64_t StuCodeDAO::insertStuCode(const StuCodeDTO::Wrapper& dto, const PayloadDTO auth)
{
	stringstream sql;
	sql << "INSERT INTO ba_sex_sta (`id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`sex_sta_code`,`sex_sta_name`) \
VALUES (?,?,?,?,?,?,?,?,?,?,?)";
	string time = SimpleDateTimeFormat::format();
	SnowFlake ls(0, 5);
	string id = std::to_string(ls.nextId());

	uint64_t count = sqlSession->executeUpdate(sql.str(), "%s%s%s%s%s%s%s%s%s%s%s", id, auth.getUsername(),
		auth.getRealname(), time, auth.getUsername(),auth.getRealname(),
		time, auth.getOrgcode(), auth.getCompanycode(), dto->code.getValue({}), dto->name.getValue({}));

	//std::cout << count << std::endl;

	return count;
}

uint64_t StuCodeDAO::deleteSexCode(const StuCodeDelDTO::Wrapper& dto)
{
	auto list = dto->delList;
	stringstream sql;
	sql << "DELETE FROM ba_sex_sta WHERE id = ?";

	SqlParams params;

	uint64_t count = 0;

	for (int i = 0; i < list->size(); i++)
	{
		//std::cout << list[i]->code.getValue({}) << std::endl;
		//std::cout << list[i]->name.getValue({}) << std::endl;
		SQLPARAMS_PUSH(params, "s", std::string, list[i].getValue({}));
		count += sqlSession->executeUpdate(sql.str(), params);
		params.clear();
	}
	return count;
}
