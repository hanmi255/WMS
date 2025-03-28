#include "stdafx.h"
#include "AreaInfoService.h"
#include "domain/do/areainfo/AreaInfoDO.h"
#include "dao/areainfo/AreaInfoDAO.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
#include "ApiHelper.h"
#include "tree/TreeUtil.h"
#include "TreeAreaNameMapper.h"

bool AreaInfoService::deleteData(const string& id)
{
	AreaInfoDAO dao;
	if (dao.delet(id) == 1)
	{
		return true;
	}
	return false;
}

bool AreaInfoService::modifyData(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload)
{
	AreaInfoUpdDO uObj;
	uObj.setId(dto->id);
	uObj.setUpdate_name(payload.getUsername());
	uObj.setUpdate_by(payload.getRealname());
	uObj.setSys_org_code(payload.getOrgcode());
	uObj.setSys_company_code(payload.getCompanycode());
	uObj.setUpdate_date(SimpleDateTimeFormat::format());
	uObj.setCity_code(dto->city_code);
	uObj.setCity_name(dto->city_name);
	uObj.setCity_serc(dto->city_serc);
	uObj.setCity_type_code(dto->city_type_name);
	uObj.setBarea_code(dto->barea_name);
	uObj.setDarea_code(dto->area_name);
	uObj.setCity_del(dto->city_del);
	std::cout << "do: " << uObj.getId() << std::endl;
	AreaInfoDAO dao;
	if (dao.update(uObj))
	{
		return true;
	}
	return false;
}

#define GET(val) obj.get##val()
bool AreaInfoService::upload(const std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload)
{
	std::list<AreaInfoAddDO> iobj;
	SnowFlake sf(1, 1);
	std::string name = payload.getUsername();
	std::string by = payload.getRealname();
	std::string date = SimpleDateTimeFormat::format();
	std::string org = payload.getOrgcode();
	std::string company = payload.getCompanycode();
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i][0] == "" || vec[i][1] == "") continue;
		AreaInfoAddDO obj;
		obj.setId(std::to_string(sf.nextId()));
		obj.setCreate_name(name);
		obj.setCreate_by(by);
		obj.setSys_org_code(org);
		obj.setSys_company_code(company);
		obj.setCreate_date(date);
		obj.setCity_code(vec[i][0]);
		obj.setCity_name(vec[i][1]);
		obj.setCity_serc(vec[i][2]);
		obj.setCity_type_code(vec[i][3]);
		obj.setBarea_code(vec[i][4]);
		obj.setDarea_code(vec[i][5]);
		obj.setCity_del(vec[i][6]);
		obj.setUpdate_by(by);
		obj.setUpdate_name(name);
		obj.setUpdate_date(date);
		iobj.push_back(obj);
	}
	AreaInfoDAO dao;
	return dao.insertUplExl(iobj);
}
#undef GET

std::vector<std::vector<std::string>> AreaInfoService::selectAll()
{
	std::list<AreaInfoDO> iObj;
	int size = iObj.size();
	AreaInfoDAO dao;
	iObj = dao.select();
	std::vector<std::string> title(7, "");
	title[0] = ZH_WORDS_GETTER("AreaInfo.city_code");
	title[1] = ZH_WORDS_GETTER("AreaInfo.city_name");
	title[2] = ZH_WORDS_GETTER("AreaInfo.city_serc");
	title[3] = ZH_WORDS_GETTER("AreaInfo.city_type_name");
	title[4] = ZH_WORDS_GETTER("AreaInfo.barea_name");
	title[5] = ZH_WORDS_GETTER("AreaInfo.area_name");
	title[6] = ZH_WORDS_GETTER("AreaInfo.city_del");
	
	std::vector<std::vector<std::string>> vec;
	vec.push_back(title);
	for (const AreaInfoDO& obj : iObj)
	{
		std::vector<std::string> line;
		line.push_back(obj.getCity_code());
		line.push_back(obj.getCity_name());
		line.push_back(obj.getCity_serc());
		line.push_back(obj.getCity_type_name());
		line.push_back(obj.getBarea_name());
		line.push_back(obj.getDarea_name());
		line.push_back(obj.getCity_del());
		vec.push_back(line);
	}

	return vec;
}

list<shared_ptr<TreeNode>> AreaInfoService::nameTree()
{
	AreaInfoDAO dao;
	std::list<AreaNameTreeDO> obj = dao.selectName();
	auto dto = AreaNameTreeDTO::createShared();

	int index = 1;
	for (AreaNameTreeDO& node : obj)
	{
		node.setCid(std::to_string(index));
		node.setParentId("");
		index++;
	}
	for (AreaNameTreeDO& node : obj)
	{
		if (node.getCity_code() == "") continue;
		for (AreaNameTreeDO& pnode : obj)
		{
			if (pnode.getCity_code() == "" && node.getCity_code() == pnode.getId())
			{
				node.setParentId(pnode.getCid());
				break;
			}
		}
	}

	return TreeUtil::listToTree<AreaNameTreeDO>(obj, TreeAreaNameMapper());;
}

bool AreaInfoService::addData(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload)
{
	AreaInfoAddDO uObj;
	SnowFlake sf(0, 0);
	uObj.setId(std::to_string(sf.nextId()));
	uObj.setCreate_name(payload.getUsername());
	uObj.setCreate_by(payload.getRealname());
	uObj.setSys_org_code(payload.getOrgcode());
	uObj.setSys_company_code(payload.getCompanycode());
	uObj.setCreate_date(SimpleDateTimeFormat::format());
	uObj.setUpdate_name(uObj.getCreate_name());
	uObj.setUpdate_by(uObj.getCreate_by());
	uObj.setUpdate_date(uObj.getCreate_date());
	uObj.setCity_code(dto->city_code);
	uObj.setCity_name(dto->city_name);
	uObj.setCity_serc(dto->city_serc);
	uObj.setCity_type_code(dto->city_type_name);
	uObj.setBarea_code(dto->barea_name);
	uObj.setDarea_code(dto->area_name);
	uObj.setCity_del(dto->city_del);
	AreaInfoDAO dao;
	if (dao.add(uObj))
	{
		return true;
	}
	return false;
}

AreaInfoPageDTO::Wrapper AreaInfoService::List(const AreaInfoQuery::Wrapper& query)
{
	auto pages = AreaInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	AreaInfoDAO dao;
	auto list = dao.selectList(query);
	pages->total = list.size();
	if (pages->total <= 0)
	{
		return pages;
	}
	pages->calcPages();

	for (auto sub : list)
	{
		auto dto = AreaInfoDTO::createShared();
		dto->id = sub.getId();
		dto->area_name = sub.getDarea_name();
		dto->barea_name = sub.getBarea_name();
		dto->city_code = sub.getCity_code();
		dto->city_del = sub.getCity_del();
		dto->city_name = sub.getCity_name();
		dto->city_serc = sub.getCity_serc();
		dto->city_type_name = sub.getCity_type_name();
		pages->addData(dto);
	}
	return pages;
}