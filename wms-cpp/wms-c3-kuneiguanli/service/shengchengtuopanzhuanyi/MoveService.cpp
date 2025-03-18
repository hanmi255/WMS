#include "stdafx.h"
#include "MoveService.h"
#include "dao/shengchengtuopanzhuanyi/MoveDAO.h"

HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper MoveService::querylist(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = HuoQuKeZhuanYiLieBiaoListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MoveDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MoveDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (MoveDO sub : result)
	{
		auto dto = HuoQuKeZhuanYiLieBiaoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,  kuctype, KucType, ku_wei_bian_ma, KuWeiBianMa, bin_id, BinId, cus_code, CusCode, zhong_wen_qch, ZhongWenQch, goods_id, GoodsId, goods_qua, GoodsQua, shp_ming_cheng, ShpMingCheng, goods_pro_data, GoodsProData, bzhi_qi, BzhiQi, goods_unit, GoodsUnit);
		pages->addData(dto);
	}
	return pages;
}