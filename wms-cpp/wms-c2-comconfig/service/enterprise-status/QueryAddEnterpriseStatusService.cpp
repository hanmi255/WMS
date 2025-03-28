#include "stdafx.h"
#include "../../dao/enterprise-status/EnterpirseStatusDAO.h"
#include "QueryAddEnterpirseStatusService.h"

EnterpriseStatusPageDTO::Wrapper EnterpriseStatusService::listAll(const GetEnterpriseStatusQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = EnterpriseStatusPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	EnterpriseStatusDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CustomerStatusDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CustomerStatusDO sub : result)
	{
		auto dto = EnterpriseStatusDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, code, Code, id, Id, ban, Ban);
		pages->addData(dto);
	}
	return pages;
}

uint64_t EnterpriseStatusService::saveData(const EnterpriseStatusDTO::Wrapper& dto)
{
	// 组装DO数据
	CustomerStatusDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Code, code, Id, id, Ban, ban);
	// 执行数据添加
	EnterpriseStatusDAO dao;
	return dao.insert(data);
}
