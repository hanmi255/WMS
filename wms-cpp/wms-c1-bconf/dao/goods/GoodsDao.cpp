#include "stdafx.h"
#include "GoodsDao.h"
#include "GoodsMapper.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>


std::list<GoodsDo> GoodsDao::getAll()
{
	string sql = "select id,category_code,category_name,category_level,pid,top_node from ba_goods_category";
	GoodsMapper mapper;
	return sqlSession->executeQuery<GoodsDo, GoodsMapper>(sql, mapper);
	
}

uint64_t GoodsDao::countAll()
{
	string sql = "select count(*) from ba_goods_category";
	return sqlSession->executeQueryNumerical(sql);
	
}

std::list<GoodsDo> GoodsDao::getTop()
{
	string sql = "select id,category_code,category_name,category_level,pid,top_node from ba_goods_category \
			where category_level = ? ";
	GoodsMapper mapper;
	uint64_t t = 1;
	return sqlSession->executeQuery<GoodsDo, GoodsMapper>(sql, mapper, "%ull", t);
	

}

GoodsDo GoodsDao::getById(uint64_t id)
{
	string sql = "select id,category_code,category_name,category_level,pid,top_node from ba_goods_category \
			where id = ? ";
	GoodsMapper mapper;
	return sqlSession->executeQueryOne<GoodsDo, GoodsMapper>(sql, mapper, "%ull", id);
	
}

static int queryExsit(string t) {
	SqlSession sqlSession;
	string sql = "SELECT EXISTS (SELECT 1 FROM ba_goods_category WHERE category_code = ?) AS exists_flag";
	return sqlSession.executeQueryNumerical(sql,"%s",t);
}


//static std::string format_time(const std::chrono::system_clock::time_point& tp,
//	const std::string& format = "%Y-%m-%d %H:%M:%S.%3f") {
//	std::time_t now_time = std::chrono::system_clock::to_time_t(tp);
//	std::tm local_tm = *std::localtime(&now_time);
//	char buffer[80];
//	std::strftime(buffer, sizeof(buffer), format.c_str(), &local_tm);
//	return std::string(buffer);
//}

int GoodsDao::insert(GoodsDo tmp)
{
	auto now = std::chrono::system_clock::now();
	if (queryExsit(tmp.getCategory_code()) == 1) {
		string sql = "UPDATE `ba_goods_category` SET `update_name`=?, `update_by`=?,`update_time`=CURRENT_TIMESTAMP ,`category_code`=?, \
			`category_name`=?, `category_level`=?,`pid`=?,`top_node`=? WHERE `category_code`=?";
		return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", \
			tmp.getCreate_name(), tmp.getCreate_by(), tmp.getCategory_code(), tmp.getCategory_name(), \
			std::to_string(tmp.getCategory_level()), std::to_string(tmp.getPID()), tmp.getTop_node(),tmp.getCategory_code()
		);
	}
	else if (queryExsit(tmp.getCategory_code()) == 0) {
		string sql = "INSERT INTO `ba_goods_category` (`create_name`, `create_by`,`create_time`,`sys_org_code` ,`category_code`,`category_name`,`category_level`,`pid`,`top_node`) VALUES (?, ?, CURRENT_TIMESTAMP,?, ?, ?, ?, ?, ?)";
		return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", \
			tmp.getCreate_name(), tmp.getCreate_by(), tmp.getSys_org_code(), tmp.getCategory_code(), tmp.getCategory_name(), \
			std::to_string(tmp.getCategory_level()), std::to_string(tmp.getPID()), tmp.getTop_node()
		);
	}
	else {
		return -1;
	}
}
