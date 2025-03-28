/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/4 14:30

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CostDetailService.h"
#include "../../dao/cost-detail/CostDetailDAO.h"
#include "id/UuidFacade.h"

bool CostDetailService::charge(const oatpp::String& id)
{
	//因为是根据id直接修改数据的属性,故直接调用dao层修改即可
	CostDetailDAO dao;
	return dao.charge(id) == 1;//1为正常返回值
}
bool CostDetailService::discharge(const oatpp::String& id)
{
	//因为是根据id直接修改数据的属性,故直接调用dao层修改即可
	CostDetailDAO dao;
	return dao.discharge(id) == 1;//1为正常返回值
}
uint64_t CostDetailService::addData(const CostExportDTO* dto)
{
	// 组装DO数据
	DayCostDO data;
	//调用uuid算法生成id
	UuidFacade uuid(1);
	string id;
	for (auto ch : uuid.genUuid())
	{
		if (ch != '-')
			id += ch;
	}
	data.setId(id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateName,creator, CreateDate,createdate, UpdateName, updater, UpdateDate, updatedate, CusCode,client, CusName,clientname, CostCode,cost);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CusName, costname, CostDate, costdate, DayCostYj, oldprice, DayCostBhs, notax, DayCostSe, tax, DayCostHsj, taxprice, CostOri, source, BeiZhu, remark, CostSta, state, CostJs, status, CostSl, count, CostUnit, unit);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateBy, create_by, SysOrgCode, org_code, SysCompanyCode, company_code);//负载里包含的信息
	//数据添加
	CostDetailDAO dao;
	return dao.insert(data);
}

vector<vector<string>> CostDetailService::exportAll(const oatpp::List<oatpp::String>& ids)
{
	CostDetailDAO dao;
	list<DayCostDO> DOlists;
	if (ids->size() > 0)
	{
		//按每个id查询返回结果
		for (auto id = ids->begin(); id != ids->end(); ++id)
		{
			DOlists.push_back(dao.selectById(*id));
		}
	}
	else
	{
		DOlists = dao.exportAll(ids);
	}
	
	//将DO列表解析成vector<vector<string>>
	vector<vector<string>> ret;
	for (auto line : DOlists)
	{
		vector<string> col;
		col.push_back(line.getCreateName());
		col.push_back(line.getCreateDate());
		col.push_back(line.getUpdateName());
		col.push_back(line.getUpdateDate());
		col.push_back(line.getCusCode());
		col.push_back(line.getCusName());
		col.push_back(line.getCostCode());
		col.push_back(line.getCostName());
		col.push_back(line.getCostDate());
		col.push_back(line.getDayCostYj());
		col.push_back(line.getDayCostBhs());
		col.push_back(line.getDayCostSe());
		col.push_back(line.getDayCostHsj());
		col.push_back(line.getCostOri());
		col.push_back(line.getBeiZhu());
		col.push_back(line.getCostSta());
		col.push_back(line.getCostJs());
		col.push_back(line.getCostSl());
		col.push_back(line.getCostUnit());
		ret.push_back(col);
	}
	return ret;
}