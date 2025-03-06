#include "stdafx.h"
#include "TuopanService.h"
#include "../../dao/tuopandingyi/TuopanDAO.h"
#include "../../Macros.h"


TuopanPageDTO::Wrapper TuopanService::listAll(const TuopanQuery::Wrapper& query)
{
	//构建返回对象
	auto pages = TuopanPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//查询数据总条数
	TuopanDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) 
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TuopanDO> result = dao.selectWithPage(query);

	//将DO转换成DTO
	for (TuopanDO sub : result)
	{
		auto dto = TuopanDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, tin_id, TinId,tin_sort, TinSort, bin_id, BinId, tin_status, TinStatus, bpm_status, BpmStatus, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode);
		pages->addData(dto);
	}
	return pages;
}

bool TuopanService::updateData(const TuopanDTO::Wrapper& dto)
{
	// 组装DO数据
	TuopanDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Id,id,TinId,tin_id,TinSort,tin_sort,BinId,bin_id,TinStatus,tin_status,BpmStatus,bpm_status, SysOrgCode,sys_org_code, SysCompanyCode,sys_company_code );
	// 执行数据修改
	TuopanDAO dao;
	return dao.update(data) == 1;
}

bool TuopanService::removeData(oatpp::List<oatpp::String>& idlist)
{
	TuopanDAO dao;
	bool flag = true;

	//遍历idlist执行批量删除操作
	for (auto id : *idlist) 
	{
		flag &= dao.deleteById(id);
	}
	return  flag;
}
