#include "stdafx.h"
#include "BareaInfoDAO.h"
#include "BareaInfoMapper.h"

std::list<BareaInfoDO> BareaInfoDAO::exportBareaInfo()
{
	std::string sql = "SELECT barea_code,barea_name,barea_rdata FROM ba_barea";
	BareaInfoExportMapper mapper;
	return sqlSession->executeQuery<BareaInfoDO>(sql, mapper);
}

std::list<BareaNameDO> BareaInfoDAO::nameList()
{
	std::string sql = "SELECT id,barea_name FROM ba_barea";
	BareaNameMapper mapper;
	return sqlSession->executeQuery<BareaNameDO>(sql, mapper);
}

std::list<BareaInfoDO> BareaInfoDAO::infoList(const BareaInfoQuery::Wrapper& query)
{
	SqlParams params;
	std::string sql = "SELECT id,barea_code,barea_name,barea_rdata FROM ba_barea";
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->barea_code)
	{
		sqlCondition << " AND `barea_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->barea_code.getValue(""));
	}
	if (query->barea_name)
	{
		sqlCondition << " AND `barea_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->barea_name.getValue(""));
	}
	sql += sqlCondition.str();
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	BareaInfoMapper mapper;
	return sqlSession->executeQuery<BareaInfoDO>(sql, mapper, params);
}