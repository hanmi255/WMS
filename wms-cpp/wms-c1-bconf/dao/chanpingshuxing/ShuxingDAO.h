#pragma once
 
#ifndef _SHUXINGDAO_
#define _SHUXINGDAO_
#include "BaseDAO.h"
#include"../../domain/do/chanpingshuxing/ShuxingDO.h"
#include "ShuxingMapper.h"

#include "id/SnowFlake.h"
#include "id/UuidFacade.h"
class ShuxingDAO : public BaseDAO
{
private:
	 
public:
	// 修改数据
	int update(const ShuxingDO& sdo);
	//删除数据
	int delete_data(const vector<ShuxingDO>& sdos);
	//导出数据
	std::list<ShuxingDO> upload_data();
	 //导入数据
	int load_data(const ShuxingDO& sdos);
};
#endif  