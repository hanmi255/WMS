#pragma once
#ifndef _DELETE_DAO_
#define _DELETE_DAO_
#include "BaseDAO.h"

/**
 * 示例表数据库操作实现
 */
class DeleteDAO : public BaseDAO
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
public:

		// 通过ID批量删除数据
	int deleteById(vector<string>& ids);
};
#endif // !_DELETE_DAO_
