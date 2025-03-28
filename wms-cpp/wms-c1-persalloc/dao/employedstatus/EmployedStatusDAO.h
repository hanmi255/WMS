#pragma once
#include "BaseDAO.h"
#include "oatpp/core/Types.hpp"
#include "../../domain/do/employedstatus/EmployedStatusDO.h"
#include "domain/dto/PayloadDTO.h"
typedef oatpp::data::mapping::type::String String;
/**
 * 示例表数据库操作实现
 */
class EmployedStatusDAO : public BaseDAO
{
private:

public:

	// 通过ID删除数据
	int deleteById(const EmployedStatusDO& id);

	// 导出在职状态表中的所有数据
	bool exportAllData(vector<vector<string>>& xdata);
	// 导入所有数据
	bool importAllData(const vector<vector<string>>& xdata, const PayloadDTO& payload);
};