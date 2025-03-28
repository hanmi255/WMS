#include "stdafx.h"
#include "CostTypeService.h"
#include "../../dao/CostType/CostTypeDAO.h"

CostListPageDTO::Wrapper CostTypeService::listAll(const CostTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CostListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CostTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CostTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CostTypeDO sub : result)
	{
		auto dto = CostListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, cost_code, Cost_code, cost_name, Cost_name, cost_type, Cost_type, create_name, Create_name, create_date, Create_date, update_name, Update_name, update_date, Update_date);
		pages->addData(dto);
	}
	return pages;
}

CostListDTO::Wrapper CostTypeService::getById(uint64_t id)
{
	// 查询数据
	CostTypeDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = CostListDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, cost_code, Cost_code, cost_name, Cost_name, cost_type, Cost_type, create_name, Create_name, create_date, Create_date, update_name, Update_name, update_date, Update_date);
	return dto;
}

uint64_t CostTypeService::saveData(const GetCostDTO::Wrapper& dto)
{
	// 组装DO数据
	CostTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Cost_code, cost_code, Cost_name, cost_name, Cost_type, cost_type, Create_name, create_name, Create_date, create_date);
	// 执行数据添加
	CostTypeDAO dao;
	return dao.insert(data);
}

// 包含payload信息填充（fangtang新增
uint64_t CostTypeService::saveData(const GetCostDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	CostTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Cost_code, cost_code, Cost_name, cost_name, Cost_type, cost_type);

	// 生成create_date
	std::time_t now = std::time(nullptr);
	std::tm tm_now = *std::localtime(&now);
	std::stringstream ssCreateTime;
	ssCreateTime << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S ");
	//创建时间
	data.setCreate_date(ssCreateTime.str());

	// 创建人名称
	data.setCreate_by(payload.getUsername());

	// 创建人昵称realname
	data.setCreate_name(payload.getRealname());

	// 所属公司、部门
	data.setSysCompanyCode(payload.getCompanycode());
	data.setSysOrgCode(payload.getOrgcode());

	// 执行数据添加
	CostTypeDAO dao;


	return dao.insert(data);
}

bool CostTypeService::updateData(const ModifyCostDTO::Wrapper& dto)
{
	// 组装DO数据
	CostTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Cost_code, cost_code, Cost_name, cost_name, Cost_type, cost_type, Update_name, update_name, Update_date, update_date);
	// 执行数据修改
	CostTypeDAO dao;
	return dao.update(data) == 1;
}
bool CostTypeService::removeData(uint64_t id)
{
	CostTypeDAO dao;
	return dao.deleteById(id) == 1;
}

