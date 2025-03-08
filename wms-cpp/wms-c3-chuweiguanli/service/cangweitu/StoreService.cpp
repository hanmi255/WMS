#include "stdafx.h"
#include "StoreService.h"
#include "../../dao/cangweitu/StoreDAO.h"

List<HuoQuCangWeiShuJuDTO::Wrapper> StoreService::listAll(const HuoQuCangWeiShuJuQuery::Wrapper& query)
{
	// 构建返回对象
	//auto pages = HuoQuCangWeiShuJuPageDTO::createShared();
	/*pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;*/

	//// 查询数据总条数
	//SampleDAO dao;
	//uint64_t count = dao.count(query);
	//if (count <= 0)
	//{
	//	return pages;
	//}

	//// 分页查询数据
	//pages->total = count;
	//pages->calcPages();
	auto listdto = List<HuoQuCangWeiShuJuDTO::Wrapper>::createShared();
	
	StoreDAO dao;
	list<WvDO> result = dao.selectWithPage(query);
	for (auto sub : result) {
		auto dto = HuoQuCangWeiShuJuDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, bin_store, BinStore, bin_id, BinId, znode, Znode, xnode, Xnode, ynode, Ynode, colour, Colour, tincount, Tincount);
		//pages->addData(dto);
		listdto->push_back(dto);
	}
	return listdto;
	
	//return pages;
}