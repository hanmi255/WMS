<<<<<<< HEAD
#pragma once

=======

#pragma once
#ifndef _MOVEGOODS_SERVICE_
#define _MOVEGOODS_SERVICE_
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
#include <list>
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

<<<<<<< HEAD
class MoveGoodsService {
public:
	// 分页获取转移任务数据
	MoveGoodsPageDTO::Wrapper listMoveGoodsPage(const MoveGoodsQuery::Wrapper& query);

	// 修改转移任务
	std::string updateMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload);

	// 批量转移任务
	std::string updateMoveGoodsBatch(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};
=======
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
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
