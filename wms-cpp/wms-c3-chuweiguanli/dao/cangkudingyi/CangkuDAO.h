#pragma once

#ifndef _CANGKU_DAO_
#define _CANGKU_DAO_

#include "BaseDAO.h"
#include "../../domain/do/BinDO.h"
#include "../../domain/do/StoreDO.h"

class CangkuDAO : public BaseDAO {
public:
	//	查找仓库名称列表
	std::list<StoreDO> getCangkuNameList();
	//	通过仓库代码删除指定仓库
	bool deleteCangkuById(string id);
	//	根据仓库代码获取导出所需的仓库报表数据
	std::vector<string> getExcelData(string store_code);
	//	获取所需的所有仓库报表数据
	std::vector<std::vector<std::string>> getAllExcelData();
};

#endif // !_CANGKU_DAO_
