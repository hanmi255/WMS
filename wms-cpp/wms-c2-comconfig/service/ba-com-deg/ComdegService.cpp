 #include "stdafx.h"
#include "ComdegService.h"
#include "../lib-common/include/id/UuidFacade.h"
#include "dao/comdegfig/ComdegfigDAO.h"
#include <SimpleDateTimeFormat.h>

ComdegPageDTO::Wrapper ComdegService::listAll(const ComdegQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ComdegPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ComdegfigDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ComdegfigDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ComdegfigDO sub : result)
	{
		auto dto = ComdegListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, degname, DegName, degcode, DegCode, degdel, DegDel,id,Id);
		pages->addData(dto);
	}
	return pages;
}

uint64_t ComdegService::saveData(const ComdegAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建生成器
	UuidFacade uf(1);
	std::string formattedTime = SimpleDateTimeFormat::format();;
	// 组装DO数据
	ComdegfigDO data;
	data.setId(uf.genUuid());
	data.setCreateName(payload.getRealname());
	data.setCreateBy(payload.getUsername());
	data.setCreateDate(formattedTime);
	data.setCompanyCode(payload.getCompanycode());
	data.setOrgCode(payload.getOrgcode());
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,DegName, degname, DegCode, degcode, DegDel, degdel);
	// 执行数据添加
	ComdegfigDAO dao;
	return dao.insert(data);
}