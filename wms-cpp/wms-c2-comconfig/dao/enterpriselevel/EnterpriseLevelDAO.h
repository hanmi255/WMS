#pragma once
#ifndef _ENTERPRISELEVEL_DAO_
#define _ENTERPRISELEVEL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customerlevel/ba_com_degDO.h"
#include "../../domain/query/enterprise-level/GetEnterPirseLevelNameQuery.h"


/**
 * 示例表数据库操作实现
 */
class EnterpriseLevelDAO : public BaseDAO
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


	//获取企业等级数据
	std::list<CustomerLevelDO> getEnterpriseName();

};
#endif // !_ENTERPRISELEVEL_DAO_

