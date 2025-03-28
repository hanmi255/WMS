#pragma once
/*
 @Author: tutu
 @Date: 2025/03/05 14:23:49
*/
#ifndef _PLC_DAO_
#define _PLC_DAO_
#include "BaseDAO.h"
#include "../../domain/do/plc-file/PlcFileDO.h"
#include "../../domain/query/plc-file/PlcFileQuery.h"

class PlcDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    PlcDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const PlcFileQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据PlcFileQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const PlcFileQuery::Wrapper& query, SqlParams& params);
	std::string getCurrentDateTime();
public:
	// 统计数据条数
	uint64_t count(const PlcFileQuery::Wrapper& query);
	//分页查询数据
	std::list<PlcBaseDO> selectWithPage(const PlcFileQuery::Wrapper& query);
	// 通过姓名查询数据
	//std::list<PlcDO> selectByName(const string& name);
	// 通过ID查询数据
	PtrPlcDO selectById(string id);
	// 插入数据
	int insert(const PlcDO& iObj, string name, string realname, string orgcode, string companycode);
	// 修改数据
	int update(const PlcDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif
