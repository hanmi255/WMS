#include "stdafx.h"
#include "ProductDAO.h"
#include "ProductMapper.h"
#include <sstream>


//新增商品类目
uint64_t ProductDAO::save(const ProductDO& iObj)
{
	string sql = "INSERT INTO `product` (`name`, `level`, `categorynum`,`pid`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%i%s%i", iObj.getCategoryname(), iObj.getCategorylevel(), iObj.getCategorynum(), iObj.getPID());
}
//修改商品类目
int ProductDAO::update(const ProductDO& uObj)
{
	string sql = "UPDATE `product` SET `name`=?, `level`=?,`pid`=?,  WHERE `categorynum`=?";
	return sqlSession->executeUpdate(sql, "%s%i%i%s", uObj.getCategoryname(), uObj.getCategorylevel(), uObj.getPID(),uObj.getCategorynum());
}
//通过商品编码删除商品类目
int ProductDAO::remove(std::string id)
{
	string sql = "DELETE FROM `product` WHERE `categorynum`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}