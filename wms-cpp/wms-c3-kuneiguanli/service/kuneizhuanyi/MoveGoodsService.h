
#pragma once
#ifndef _MOVEGOODS_SERVICE_
#define _MOVEGOODS_SERVICE_
#include <list>
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class MoveGoodsService
{
public:
	
	// 通过ID查询详细转移任务信息
	MoveGoodsDetailedDTO::Wrapper getDetailedById(const oatpp::String queryID);
	// 通过ID删除数据
	bool removeMoveGoods(const vector<string> id,const string usrName);
	// 通过ID查询导出转移任务信息
	vector<vector<string>> getDownLoadById(const vector<string>& ids);
};

#endif // !_MOVEGOODS_SERVICE_