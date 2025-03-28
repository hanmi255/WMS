#include "stdafx.h"
#include "BaGoodsTypeService.h"
#include "../../dao/bagoodstype/BaGoodsTypeDAO.h"


BaGoodsTypePageDTO::Wrapper BaGoodsTypeService::listAll(const BaGoodsTypeQuery::Wrapper& query) {
	//返回对象
	auto pages = BaGoodsTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//查询数据总条数
	BaGoodsTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	//DO to DTO
	list<BaGoodsTypeDO> result = dao.selectWithPage(query);
	for (BaGoodsTypeDO sub : result) {
		auto dto = BaGoodsTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,id,Id,goods_type_code,GoodsTypeName,goods_type_name, GoodsTypeName);
		pages->addData(dto);
	}
	return pages;
}