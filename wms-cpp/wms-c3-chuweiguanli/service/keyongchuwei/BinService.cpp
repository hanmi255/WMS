#include "stdafx.h"
#include "BinService.h"
#include "dao/keyongchuwei/BinDAO.h"

BinPageDTO::Wrapper BinService::querylist(const BinPageQuery::Wrapper& query) {
	auto pages = BinPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	BinDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	pages->total = count;
	pages->calcPages();
	list<BinDO> res = dao.selectWithPage(query);
	for (auto sub : res) {
		auto dto = BinDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, 
			id, Id,
			bin_store, BinStore,
			ku_wei_shu_xing, KuWeiShuXing,
			ku_wei_bian_ma, KuWeiBianMa, 
			suo_shu_ke_hu, SuoShuKeHu, 
			zui_da_ti_ji, ZuiDaTiJi,
			shang_jia_ci_xu, ShangJiaCiXu, 
			chang, Chang,
			kuan, Kuan,
			gao, Gao,
			zui_da_tuo_pan, ZuiDaTuoPan);
		pages->addData(dto);
	}
	return pages;
}

vector<vector<string>> BinService::querybyids(const vector<string>& ids)
{
	BinDAO dao;
	return dao.selectByIds(ids);
}
