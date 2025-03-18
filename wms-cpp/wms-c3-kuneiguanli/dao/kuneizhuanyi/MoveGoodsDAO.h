#pragma once
<<<<<<< HEAD

#include "BaseDAO.h"
#include "domain/do/kuneizhuanyi/MoveGoodsDO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"

class MoveGoodsDAO : public BaseDAO {
private:
	/**
	 * @brief 查询条件构造器
	 * @param query 查询条件
	 * @param params SQL参数
	 * @return 查询条件SQL语句
	 * @note 该方法用于构造查询条件SQL语句，并将参数填充到SQL参数列表中
	 */
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);

public:
	// 统计数据条数
	uint64_t count(const MoveGoodsQuery::Wrapper& query);

	// 分页查询转移任务
	std::list<MoveGoodsDO> selectWithPage(const MoveGoodsQuery::Wrapper& query);

	// 修改转移任务
	std::string updateMoveGoods(const MoveGoodsDO& moveGoods);

	// 批量转移任务
	std::string updateMoveGoodsBatch(const std::vector<MoveGoodsDO>& moveGoodsList);
};
=======
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
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
