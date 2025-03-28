#include "StuCodeService.h"
#include "stdafx.h"
#include "StuCodeService.h"

StuCodePageDTO::Wrapper StuCodeService::listAll(const StuCodeQuery::Wrapper& query)
{
	StuCodeDAO dao;
	auto pages = StuCodePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	uint64_t count = dao.countCode(query);
	if (count <= 0)
	{
		return pages;
	}
	//std::cout << count << "---------------" << endl;

	pages->total = count;
	pages->calcPages();

	list<StuCodeDO> result = dao.selectStuCodeWithPage(query);
	
	for (StuCodeDO sub : result)
	{
		auto dto = StuCodeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, code, Code,id,Id);
		pages->addData(dto);
	}

	return pages;
}

uint64_t StuCodeService::updateStuCode(const StuCodeDTO::Wrapper& dto, const PayloadDTO& auth)
{
	StuCodeDAO dao;
	auto res = dao.updateStuCode(dto, auth);
	return res;
}

uint64_t StuCodeService::setStuCode(const StuCodeDTO::Wrapper& dto, const PayloadDTO& auth)
{
	StuCodeDAO dao;
	auto res = dao.insertStuCode(dto, auth);
	return res;
}

uint64_t StuCodeService::setDelCode(const StuCodeDelDTO::Wrapper& dto)
{
	StuCodeDAO dao;
	auto res = dao.deleteSexCode(dto);
	return res;
}

uint64_t StuCodeService::importStuCode()
{
	return 0;
}
