#include "stdafx.h"
#include "OperStepService.h"
#include "domain/do/oper_step/OperStepDO.h"
#include "dao/oper_step/OperStepDAO.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
#include "StringUtil.h"
#include "ApiHelper.h"

bool OperStepService::deleteData(const OperStepDeleteDTO::Wrapper& dto)
{
	OperStepDO dObj;
	OperStepDAO dao;
	// 直接触发隐式转换函数
	std::string std_ids = dto->ids;
	std::vector<std::string> idList = StringUtil::split(std_ids, ",");
	for (auto id : idList) {
        dObj.setId(id);
		if (dao.del(dObj) == 1)
		{
			continue;
		}
		else
			return false;
	}
	return true;
}

bool OperStepService::modifyData(const  OperStepDTO::Wrapper& dto, const PayloadDTO& payload)
{
	OperStepDO dObj;
	OperStepDAO dao;
    dObj.setId(dto->ID);
	dObj.setUpdate_name(payload.getUsername());
	dObj.setUpdate_by(payload.getId());
	dObj.setUpdate_date(SimpleDateTimeFormat::format());
	dObj.setOper_step_code(dto->oper_step_code);
    dObj.setOper_step_name(dto->oper_step_name);
    dObj.setSys_org_code(dto->sys_org_code);
    dObj.setSys_company_code(dto->sys_company_code);
	if (dao.update(dObj))
	{
		return true;
	}
	return false;
}

bool OperStepService::importData(const std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload)
{
	std::list<OperStepDO> iobj;
	SnowFlake sf(1, 1);
	for (int i = 2; i < vec.size(); i++)
	{
		OperStepDO obj;
		obj.setId(std::to_string(sf.nextId()));
		obj.setCreate_name(payload.getUsername());
		obj.setCreate_by(payload.getId());
		obj.setCreate_date(SimpleDateTimeFormat::format());
		obj.setOper_step_code(vec[i][0]);
		obj.setOper_step_name(vec[i][1]);
		obj.setUpdate_name(vec[i][2]);
		obj.setUpdate_by(vec[i][3]);
		obj.setUpdate_date(vec[i][4]);
		obj.setSys_org_code(vec[i][5]);
		obj.setSys_company_code(vec[i][6]);
		iobj.push_back(obj);
	}
	OperStepDAO dao;
	return dao.insertFromExcel(iobj);
}

std::vector<std::vector<std::string>> OperStepService::selectAll()
{
	std::list<OperStepDO> iObj;
	OperStepDAO dao;
	iObj = dao.selectAll();
	std::vector<std::string> title(10, "");
	title[0] = ZH_WORDS_GETTER("business-link.field.create-name");
	title[1] = ZH_WORDS_GETTER("business-link.field.create-by");
	title[2] = ZH_WORDS_GETTER("business-link.field.create-date");
	title[3] = ZH_WORDS_GETTER("business-link.field.oper-step-code");
	title[4] = ZH_WORDS_GETTER("business-link.field.oper-step-name");
	title[5] = ZH_WORDS_GETTER("business-link.field.update-name");
	title[6] = ZH_WORDS_GETTER("business-link.field.update-by");
	title[7] = ZH_WORDS_GETTER("business-link.field.update-date");
	title[8] = ZH_WORDS_GETTER("business-link.field.sys-org-code");
	title[9] = ZH_WORDS_GETTER("business-link.field.sys-company-code");

	std::vector<std::vector<std::string>> vec;
	vec.push_back(title);
	for (const OperStepDO& obj : iObj)
	{
		std::vector<std::string> line;
		line.push_back(obj.getCreate_name());
		line.push_back(obj.getCreate_by());
		line.push_back(obj.getCreate_date());
		line.push_back(obj.getOper_step_code());
		line.push_back(obj.getOper_step_name());
		line.push_back(obj.getUpdate_name());
		line.push_back(obj.getUpdate_by());
		line.push_back(obj.getUpdate_date());
		line.push_back(obj.getSys_org_code());
		line.push_back(obj.getSys_company_code());
		vec.push_back(line);
	}

	return vec;
}

