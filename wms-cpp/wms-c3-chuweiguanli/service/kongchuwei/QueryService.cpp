#include "stdafx.h"
#include "QueryService.h"
#include "../../dao/kongchuwei/QueryDAO.h"

DaoChuKongChuWeiPageDTO::Wrapper QueryService::listAll(const DaoChuKongChuWeiQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DaoChuKongChuWeiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QueryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<BinDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (BinDO sub : result)
	{
		auto dto = DaoChuKongChuWeiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, bin_store, BinStore, ku_wei_shu_xing, KuWeiShuXing, CHP_SHU_XING, CHPShuXing, ku_wei_bian_ma, KuWeiBianMa, suo_shu_ke_hu, SuoShuKeHu, zui_da_ti_ji, ZuiDaTiJi, shang_jia_ci_xu, ShangJiaCiXu, chang, Chang, kuan, Kuan, gao, Gao, zui_da_tuo_pan, ZuiDaTuoPan, ting_yong, TingYong, ku_wei_lei_xing, KuWeiLeiXing);
		pages->addData(dto);
	}
	return pages;
}