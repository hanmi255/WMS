#pragma once
#ifndef _MOVEGOODS_DAO_
#define _MOVEGOODS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MoveGoodsDO.h"
#include "../../domain/query/kuneizhuanyi/MoveGoodsQuery.h"


class MoveGoodsDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);
public:
	// 通过ID查询转移任务详细数据
	PtrMoveGoodsDO selectDetailedById(const oatpp::String  queryID);
	// 通过ID查询转移任务导出数据
	std::vector<std::vector<string>> selectDownLoadById(const vector<string>& ids);
	// 通过ID删除数据
	int deleteById(const vector<string> id,const string usrName);
};
#endif // !_MOVEGOODS_DAO_