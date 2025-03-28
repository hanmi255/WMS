#include "stdafx.h"
#include "BussTypeService.h"
#include "../../dao/busstype/BussTypeDAO.h"
#include "../../../lib-common/include/id/SnowFlake.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"


// 分页查询所有数据
BussTypeListPageDTO::Wrapper BussTypeService::listAll(const BussTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = BussTypeListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	BussTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<BussTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (BussTypeDO sub : result)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// 通过业务类型Name查询数据
BussTypeListPageDTO::Wrapper BussTypeService::getByName(string name)
{
	auto pages = BussTypeListPageDTO::createShared();
	// 查询数据
	BussTypeDAO dao;
	auto res = dao.selectByName(name);
	// 没有查询到数据
	if (res.empty())
		return nullptr;
	// 将DO转换成DTO
	for (BussTypeDO sub : res)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// 通过业务类型Code查询数据
BussTypeListPageDTO::Wrapper BussTypeService::getByCode(string code)
{
	auto pages = BussTypeListPageDTO::createShared();
	// 查询数据
	BussTypeDAO dao;
	auto res = dao.selectByCode(code);
	// 没有查询到数据
	if (res.empty())
		return nullptr;
	// 将DO转换成DTO
	for (BussTypeDO sub : res)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// 通过业务类型Text查询数据
BussTypeListPageDTO::Wrapper BussTypeService::getByText(string text)
{
	auto pages = BussTypeListPageDTO::createShared();
	// 查询数据
	BussTypeDAO dao;
	auto res = dao.selectByText(text);
	// 没有查询到数据
	if (res.empty())
		return nullptr;
	// 将DO转换成DTO
	for (BussTypeDO sub : res)
	{
		auto dto = BussTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buss_type_code, BussTypeCode, buss_type_name, BussTypeName, buss_type_text, BussTypeText);
		pages->addData(dto);
	}
	return pages;
}
// 保存数据
uint64_t BussTypeService::saveData(const BussTypeAddDTO::Wrapper& dto)
{
	// 组装DO数据
	BussTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,BussTypeCode,buss_type_code,BussTypeName,buss_type_name,BussTypeText ,buss_type_text);
	//添加id
	SnowFlake sf(1, 1);
	data.setId(std::to_string(sf.nextId()));
	//添加创建日期
	data.setCreateDate(SimpleDateTimeFormat::format());
	// 执行数据添加
	BussTypeDAO dao;
	return dao.insert(data);
}
// 修改数据
bool BussTypeService::updateData(const BussTypeAddDTO::Wrapper& dto)
{
	// 组装DO数据
	BussTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,BussTypeCode, buss_type_code, BussTypeName, buss_type_name, BussTypeText, buss_type_text);
	// 执行数据修改
	BussTypeDAO dao;
	return dao.update(data) == 1;
}