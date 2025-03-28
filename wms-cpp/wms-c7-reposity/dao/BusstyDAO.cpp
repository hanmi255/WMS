
#include "stdafx.h"
#include "BusstyDAO.h"
#include "../lib-mysql/include/jdbc/cppconn/resultset.h"
#include "../lib-mysql/include/SqlSession.h"
#include "../wms-c7-reposity/dao/BusstyMapper.h"
#include "../wms-c7-reposity/domain/dto/BusstyDTO.h"

int BusstyDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `ba_buss_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
int BusstyDAO::deleteByID(uint64_t id)
{
	string sql = "DELETE FROM `ba_buss_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
std::list<ba_buss_typeDO> BusstyDAO::leadout()
{
	string sql = "SELECT * FROM ba_buss_type ";
	// 执行查询
	BusstyMapper mapper;
	return sqlSession->executeQuery<ba_buss_typeDO>(sql, mapper);
}
int BusstyDAO::leadin(ba_buss_typeDO data)
{
	string sql = "INSERT INTO `ba_buss_type` (`num`, `name`, `desc`) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s", data.getNum(), data.getName(), data.getDesc());
}
