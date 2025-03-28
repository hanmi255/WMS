/*
 Copyright Zero One Star. All rights reserved.

 @Author: whx
 @Date: 2025/3/5 14:23:49

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
#include "../../dao/cost-detail-ahead/CostDetailAheadDAO.h"
#include <SimpleDateTimeFormat.h>
#include "id/UuidFacade.h"
#include "FastDfsClient.h"

CostDetailListPageDTO::Wrapper CostDetailService::listAll(const CostDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CostDetailListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CostDetailAheadDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DayCostDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DayCostDO sub : result)
	{
		auto dto = CostDetailBaseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, 
			id, Id, 
			create_name, CreateName,
			create_by, CreateBy,
			create_date,CreateDate,
			update_name,UpdateName,
			update_date,UpdateDate, 
			update_by, UpdateBy, 
			sys_org_code, SysOrgCode, 
			sys_company_code, SysCompanyCode, 
			cus_code, CusCode, 
			cus_name, CusName, 
			cost_code, CostCode, 
			cost_name, CostName,
			cost_date, CostDate, 
			day_cost_yj, DayCostYj, 
			day_cost_bhs, DayCostBhs, 
			day_cost_se, DayCostSe, 
			day_cost_hsj, DayCostHsj,
			cost_ori, CostOri, 
			beizhu, BeiZhu, 
			cost_sta, CostSta, 
			cost_sl, CostSl, 
			cost_unit, CostUnit, 
			cost_js, CostJs);
		pages->addData(dto);
	}
	return pages;
}



CostDetailBaseDTO::Wrapper CostDetailService::getById(uint64_t id)
{
	// 查询数据
	CostDetailAheadDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = CostDetailBaseDTO::createShared();
	//ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, create_name, CreateName, create_date, CreateDate, update_name, UpdateName, update_date, UpdateDate, cus_code, CusCode, cost_date, CostDate);

	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, create_name, CreateName, create_by, CreateBy, create_date, CreateDate, update_name, UpdateName, update_date, UpdateDate, update_by, UpdateBy, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode,
		cus_code, CusCode, cus_name, CusName, cost_code, CostCode, cost_name, CostName, cost_date, CostDate, day_cost_yj, DayCostYj, day_cost_bhs, DayCostBhs, day_cost_se, DayCostSe, day_cost_hsj, DayCostHsj,
		cost_ori, CostOri, beizhu, BeiZhu, cost_sta, CostSta, cost_sl, CostSl, cost_unit, CostUnit, cost_js, CostJs);
	return dto;
}


uint64_t CostDetailService::saveData(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	DayCostDO data;

	// 生成时间
	string now = SimpleDateTimeFormat::format();

	//调用uuid算法生成id
	UuidFacade uuid(1);
	string Id;
	for (auto ch : uuid.genUuid())
	{
		if (ch != '-')
			Id += ch;
	}
	//data.setId(id);

	//从负载读取信息
	data.setId(Id);
	data.setCreateName(payload.getUsername());
	data.setCreateBy(payload.getRealname());
	data.setCreateDate(now);
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());

	//将dto数据转移到do,未赋值的do部分数据在上面赋值
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CusCode, cus_code,  CostCode, cost_code,  CostDate, cost_date, DayCostYj, day_cost_yj, DayCostBhs, day_cost_bhs, DayCostSe, day_cost_se, DayCostHsj, day_cost_hsj,
		CostOri, cost_ori, BeiZhu, beizhu, CostSta, cost_sta, CostSl, cost_sl, CostUnit, cost_unit);
	// 执行数据添加
	CostDetailAheadDAO dao;
	return dao.insert(data);
}

bool CostDetailService::updateData(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	DayCostDO data;

	// 生成时间
	string now = SimpleDateTimeFormat::format();

	//从负载读取信息
	data.setUpdateName(payload.getUsername());
	data.setUpdateBy(payload.getRealname());
	data.setUpdateDate(now);

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,CusCode, cus_code, CostCode, cost_code, CostDate, cost_date, DayCostYj, day_cost_yj, DayCostBhs, day_cost_bhs, DayCostSe, day_cost_se, DayCostHsj, day_cost_hsj,
		CostOri, cost_ori, BeiZhu, beizhu, CostSta, cost_sta, CostSl, cost_sl, CostUnit, cost_unit);

	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,UpdateName, update_name, UpdateDate, update_date, UpdateBy, update_by,
	//	CusCode, cus_code,  CostCode, cost_code, CostDate, cost_date, DayCostYj, day_cost_yj, DayCostBhs, day_cost_bhs, DayCostSe, day_cost_se, DayCostHsj, day_cost_hsj,
	//	CostOri, cost_ori, BeiZhu, beizhu, CostSta, cost_sta, CostSl, cost_sl, CostUnit, cost_unit);
	// 执行数据修改
	CostDetailAheadDAO dao;
	return dao.update(data) == 1;
}

bool CostDetailService::removeData(const string& id)
{
	CostDetailAheadDAO dao;
	return dao.deleteById(id) == 1;
}

bool CostDetailService::removeBatchData(const vector<string>& ids)
{
	CostDetailAheadDAO dao;
	SqlSession* session = dao.getSqlSession();

	try {
		session->beginTransaction(); // 开启事务

		for (const auto& id : ids) {
			int affectedRows = dao.deleteById(id);
			if (affectedRows != 1) { // 预期每行删除影响1条记录
				session->rollbackTransaction(); // 任意失败则回滚
				return false;
			}
		}

		session->commitTransaction(); // 全部成功则提交
		return true;
	}
	catch (const exception& e) {
		session->rollbackTransaction();
		cerr << "[SERVICE ERROR] " << e.what() << endl;
		return false;
	}
}
