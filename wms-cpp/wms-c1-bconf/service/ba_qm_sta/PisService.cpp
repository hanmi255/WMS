#include "stdafx.h"
#include "PisService.h"
#include "../../dao/ba_qm_sta/PisDAO.h"

PisPageDTO::Wrapper PisService::listAll(const PisQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PisPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PisDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PisDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PisDO sub : result)
	{
		auto dto = PisDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, code, Code, name, Name);
		pages->addData(dto);
	}
	return pages;
}

std::string PisService::saveData(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload)
{
	// 组装DO数据
	PisDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name);
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// 执行数据添加
	PisDAO dao;
	return dao.insert(data);
}

bool PisService::updateData(const PisDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	PisDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, Code, code);
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// 执行数据修改
	PisDAO dao;
	return dao.update(data) >= 0;
}

//PisDTO::Wrapper PisService::getByCode(const string& code)
//{
//	// 查询数据
//	PisDAO dao;
//	auto res = dao.selectByCode(code);
//
//	// 没有查询到数据
//	 if (!res)
//		return nullptr;
//
//	// 查询到数据转换成DTO
//	auto dto = PisDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, code, Code, sta, Sta);
//	return dto;
//}
//
//
//PisDTO::Wrapper PisService::getBySta(const string& sta)
//{
//	// 查询数据
//	PisDAO dao;
//	auto res = dao.selectBySta(sta);
//
//	// 没有查询到数据
//	if (!res)
//		return nullptr;
//
//	// 查询到数据转换成DTO
//	auto dto = PisDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, code, Code, sta, Sta);
//	return dto;
//}

