#include "stdafx.h"
#include "DareaInfoService.h"
#include "domain/do/regioninfo/DareaInfoDO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

DareaInfoPageDTO::Wrapper DareaInfoService::listAll(const DareaInfoQuery::Wrapper& query)
{
	auto pages = DareaInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	DareaInfoDAO dao;
	list<DareaInfoDO> result = dao.select(query);
	for (DareaInfoDO sub : result)
	{
		auto dto = DareaInfoDTO::createShared();
		dto->id = sub.getId();
		dto->area_code = sub.getArea_code();
		dto->area_name = sub.getArea_name();
		pages->addData(dto);
	}

	return pages;
}

string DareaInfoService::AddOne(const DareaInfoAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	DareaInfoAddDO iObj;
	SnowFlake flake(0,0);
	iObj.setId(std::to_string(flake.nextId()));
	iObj.setCreate_name(payload.getUsername());
	iObj.setCreate_by(payload.getRealname());
	iObj.setCreate_date(SimpleDateTimeFormat::format());
	iObj.setSys_company_code(payload.getCompanycode());
	iObj.setSys_org_code(payload.getOrgcode());
	iObj.setUpdate_date(iObj.getCreate_date());
	iObj.setUpdate_by(iObj.getCreate_by());
	iObj.setUpdate_name(iObj.getCreate_name());
	iObj.setArea_code(dto->area_code);
	iObj.setArea_name(dto->area_name);
	DareaInfoDAO dao;
	string id = "";
	if (dao.insert(iObj))
	{
		id = iObj.getId();
	} 
	return id;
}

bool DareaInfoService::Update(const DareaInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	DareaInfoUpdDO uObj;
	uObj.setId(dto->id);
	uObj.setArea_code(dto->area_code);
	uObj.setArea_name(dto->area_name);
	uObj.setUpdate_by(payload.getRealname());
	uObj.setUpdate_date(SimpleDateTimeFormat::format());
	uObj.setUpdate_name(payload.getUsername());
	DareaInfoDAO dao;
	return dao.update(uObj);
}

bool DareaInfoService::Delete(const string& id)
{
	DareaInfoDAO dao;
	return dao.delet(id);
}

std::vector<std::vector<std::string>> DareaInfoService::Export()
{
	DareaInfoDAO dao;
	auto obj = dao.select();
	std::vector<std::vector<std::string>> vec;
	std::vector<std::string> head(2, "");
	head[0] = ZH_WORDS_GETTER("DareaInfo.area_code");
	head[1] = ZH_WORDS_GETTER("DareaInfo.area_name");
	vec.push_back(head);
	for (auto line : obj)
	{
		std::string code = line.getArea_code();
		std::string name = line.getArea_name();
		if (code == "" || name == "") continue;
		std::vector<std::string> v;
		v.push_back(code);
		v.push_back(name);
		vec.push_back(v);
	}
	return vec;
}

void DareaInfoService::Import(std::vector<std::vector<std::string>> vec, const PayloadDTO& payload)
{
	list<DareaInfoAddDO> Obj;
	SnowFlake flake(0, 0);
	for (auto data : vec)
	{
		if (data[0] == "" || data[1] == "") continue;
		DareaInfoAddDO iObj;
		iObj.setId(std::to_string(flake.nextId()));
		iObj.setCreate_name(payload.getUsername());
		iObj.setCreate_by(payload.getRealname());
		iObj.setCreate_date(SimpleDateTimeFormat::format());
		iObj.setSys_company_code(payload.getCompanycode());
		iObj.setSys_org_code(payload.getOrgcode());
		iObj.setUpdate_date(iObj.getCreate_date());
		iObj.setUpdate_by(iObj.getCreate_by());
		iObj.setUpdate_name(iObj.getCreate_name());
		iObj.setArea_code(data[0]);
		iObj.setArea_name(data[1]);
		Obj.push_back(iObj);
	}
	DareaInfoDAO dao;
	dao.insert(Obj);
}