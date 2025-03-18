#pragma once
#ifndef _XIANGXIXINXIDAO_
#define _XIANGXIXINXIDAO_
#include "BaseDAO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
#include "../../domain/do/BinDO.h"

/**
 * 示例表数据库操作实现
 */
class xiangxixinxiDAO : public BaseDAO
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
	inline std::string xiangxixinxiqueryConditionBuilder(const xiangxixinxiQUERY::Wrapper& query, SqlParams& params);
public:
	// 通过ID查询数据
	std::shared_ptr<BinDO> idchaxun(const xiangxixinxiQUERY::Wrapper& id);

	//	单个ID获取一个表单数据
	std::vector<string> getdataone(string store_code);
	//	获取所有表单数据
	std::vector<std::vector<std::string>> getdataall();

	//导入储位
	std::string addchuweiDAO(const BinDO& bindo, const PayloadDTO& payload);

};
#endif // !_XIANGXIXINXIDAO_