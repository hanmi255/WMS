#include "stdafx.h"
#include "EducationService.h"
#include "dao/EduDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

EduPageDTO::Wrapper EduService::listAll(const EduQuery::Wrapper& query)
{
	auto pages = EduPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	EduDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<EducationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (EducationDO sub : result)
	{
		auto dto = EduDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, educode, EduCode, eduname, EduName);
		pages->addData(dto);
	}
	return pages;
}

std::vector<std::vector<std::string>> EduService::listAll()
{
	EduDAO dao;
	auto obj = dao.select();
	std::vector<std::string> head(2, "");
	head[0] = ZH_WORDS_GETTER("education.field.educode");
	head[1] = ZH_WORDS_GETTER("education.field.eduname");
	std::vector<std::vector<std::string>> data;
	data.push_back(head);
	for (auto sub : obj)
	{
		std::vector<std::string> line(2, "");
		line[0] = sub.getEduCode();
		line[1] = sub.getEduName();
		data.push_back(line);
	}
	return data;
}

uint64_t EduService::saveData(const EduAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	EducationDO data;
	SnowFlake sf(1, 0);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, EduCode, educode, EduName, eduname);
	data.setId(std::to_string(sf.nextId()));
	data.setSys_org_code(payload.getOrgcode());
	data.setSys_company_code(payload.getCompanycode());
	data.setCreate_name(payload.getUsername());
	data.setCreate_by(payload.getRealname());
	data.setCreate_date(SimpleDateTimeFormat::format());
	data.setUpdate_name(data.getCreate_name());
	data.setUpdate_by(data.getCreate_by());
	data.setUpdate_date(data.getCreate_date());
	// 执行数据添加
	EduDAO dao;
	return dao.insert(data);
}

void EduService::saveData(std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload)
{
	std::list<EducationDO> data;
	SnowFlake sf(0, 1);
	for (auto sub : vec)
	{
		if (sub[0] == "" || sub[1] == "") continue;
		EducationDO obj;
		obj.setId(std::to_string(sf.nextId()));
		obj.setCreate_name(payload.getUsername());
		obj.setCreate_by(payload.getRealname());
		obj.setCreate_date(SimpleDateTimeFormat::format());
		obj.setUpdate_by(obj.getCreate_by());
		obj.setUpdate_date(obj.getCreate_date());
		obj.setUpdate_name(obj.getCreate_name());
		obj.setSys_company_code(payload.getCompanycode());
		obj.setSys_org_code(payload.getOrgcode());
		obj.setEduCode(sub[0]);
		obj.setEduName(sub[1]);
		data.push_back(obj);
	}
	EduDAO dao;
	dao.insert(data);
}