#pragma once

#ifndef _LADMOD_DAO_
#define _LADMOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/lad-mod/LadModDO.h"
#include "../../domain/query/lad-mod/LadModQuery.h"
#include "../../domain/dto/lad-mod/BatchDeleteRequestDto.h"

/**
 * 示例表数据库操作实现
 */
class LadModDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    LadModDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const LadModQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据LadModQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const LadModQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const LadModQuery::Wrapper& query);
	// 分页查询数据
	std::list<LadModDO> selectWithPage(const LadModQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const LadModDO& iObj);
	// 修改数据
	int update(const LadModDO& uObj);
	// 通过ID删除提货方式
	int deleteById(oatpp::UInt64 id);
	// 批量删除提货方式
	int batchDelete(const BatchDeleteRequestDto::Wrapper& dto);
	// 查询出所有的提货方式的code和name
	std::list<LadModDO> selectAll();
	// 插入大量数据
	uint64_t insert(const list<LadModDO>& data);
};
#endif // !_LadMod_DAO_
