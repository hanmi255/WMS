#include "stdafx.h"
#include "QualityService.h"
#include "dao/quality/QualityDAO.h"

QualityPageDTO::Wrapper QualityService::getData(const QualityQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = QualityPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QualityDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<QualityDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (QualityDO sub : result)
	{
		auto dto = QualityListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, qm_qa_name, Name, qm_qa_code, Code);
		pages->addData(dto);
	}
	return pages;
}

bool QualityService::InsertData(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	QualityDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, qm_qa_name, Code, qm_qa_code);
	// 组装修改数据
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// 执行数据修改
	QualityDAO dao;
	return dao.insert(data);
}

QualityDetailDTO::Wrapper QualityService::getByCode(const string& code)
{
	QualityDAO dao;
	// 查询符合条件的记录
	list<QualityDO> result = dao.selectByCode(code);

	// 如果没有找到结果，返回空对象
	if (result.empty()) {
		return QualityDetailDTO::createShared(); // 返回一个空的DTO
	}

	auto dto = QualityDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), qm_qa_name, Name, qm_qa_code, Code);

	return dto;
}

QualityDetailDTO::Wrapper QualityService::getByName(const string& name)
{
	QualityDAO dao;
	// 查询符合条件的记录
	list<QualityDO> result = dao.selectByName(name);

	// 如果没有找到结果，返回空对象
	if (result.empty()) {
		return QualityDetailDTO::createShared(); // 返回一个空的DTO
	}

	auto dto = QualityDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), qm_qa_name, Name, qm_qa_code, Code);

	return dto;
}

bool QualityService::updateData(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	QualityDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, qm_qa_name, Code, qm_qa_code, Id, id);
	// 组装修改数据
	data.setUpdate_Name(payload.getUsername());
	data.setUpdate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	// 执行数据修改
	QualityDAO dao;
	return dao.update(data) == 1;
}
