#include "stdafx.h"
#include "MoveGoodsService.h"
#include "dao/kuneizhuanyi/MoveGoodsDAO.h"

static string getTimeStr()
{
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
	return ss.str();
}

MoveGoodsPageDTO::Wrapper MoveGoodsService::listMoveGoodsPage(const MoveGoodsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MoveGoodsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MoveGoodsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
		return pages;

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	std::list<MoveGoodsDO> result = dao.selectWithPage(query);

	// 将DO转换成DTO
	for (MoveGoodsDO sub : result) {
		auto dto = MoveGoodsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			id, Id,
			create_name, CreateName,
			create_date, CreateDate,
			update_name, UpdateName,
			update_date, UpdateDate,
			goods_id, GoodsId,
			goods_name, GoodsName,
			goods_qua, GoodsQua,
			base_goodscount, BaseGoodscount,
			goods_pro_data, GoodsProData,
			to_goods_pro_data, ToGoodsProData,
			goods_unit, GoodsUnit,
			cus_code, CusCode,
			cus_name, CusName,
			tin_from, TinFrom,
			tin_id, TinId,
			bin_from, BinFrom,
			bin_to, BinTo,
			move_sta, MoveSta,
			run_sta, RunSta,
			to_cus_code, ToCusCode,
			to_cus_name, ToCusName);
		pages->addData(dto);
	}

	return pages;
}

std::string MoveGoodsService::updateMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	MoveGoodsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id,
		BaseGoodscount, base_goodscount,
		GoodsProData, goods_pro_data,
		ToGoodsProData, to_goods_pro_data,
		ToCusCode, to_cus_code,
		ToCusName, to_cus_name,
		TinId, tin_id,
		BinTo, bin_to,
		MoveSta, move_sta);
	data.setUpdateName(payload.getUsername());
	data.setUpdateBy(payload.getId());
	data.setUpdateDate(getTimeStr());

	// 执行数据修改
	MoveGoodsDAO dao;
	return dao.updateMoveGoods(data);
}

std::string MoveGoodsService::updateMoveGoodsBatch(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 检查items是否为空
	if (!dto->items || dto->items->size() == 0) 
		return std::string{ "failed" };

	// 组装DO数据
	std::vector<MoveGoodsDO> dataList;
	dataList.reserve(dto->items->size());

	// 遍历items中的每个元素
	for (const auto& item : *dto->items) {
		MoveGoodsDO data;
		// 从每个item映射到DO对象
		ZO_STAR_DOMAIN_DTO_TO_DO(data, item,
			Id, id,
			BaseGoodscount, base_goodscount,
			TinId, tin_id,
			BinTo, bin_to);
		data.setUpdateName(payload.getUsername());
		data.setUpdateBy(payload.getId());
		data.setUpdateDate(getTimeStr());

		dataList.push_back(data);
	}

	// 执行数据修改
	MoveGoodsDAO dao;
	return dao.updateMoveGoodsBatch(dataList);
}
