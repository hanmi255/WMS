#include "stdafx.h"
#include "CostNameService.h"
#include "../../dao/billing-configuration/CostNameDAO.h"
#include "../../dao/billing-configuration/CostNameMapper.h"

CostListDTO::Wrapper CostNameService::listAll(const CostNameQuery::Wrapper& query)
{
    auto lists = CostListDTO::createShared();
    CostNameDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return lists;
    }

    list<CostNameDO> result = dao.selectAll(query);
    for (CostNameDO sub : result)
    {
        auto dto = CostNameDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, cost_code, CostCode, cost_name, CostName, cost_type_code, CostTypeCode, create_name, CreateName, create_by, CreateBy, create_date, CreateDate, update_name, UpdateName, update_by, UpdateBy, update_date, UpdateDate, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode);

        lists->addData(dto);
    }
    return lists;
}

CostListPageDTO::Wrapper CostNameService::listAllByPage(const CostNameQuery::Wrapper& query)
{
    auto pages = CostListPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;
    CostNameDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    pages->total = count;
	pages->calcPages();
	list<CostNameDO> result = dao.selectWithPage(query);
    for (CostNameDO sub : result)
    {
        auto dto = CostNameDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, cost_code, CostCode, cost_name, CostName, cost_type_code, CostTypeCode, create_name, CreateName, create_by, CreateBy, create_date, CreateDate, update_name, UpdateName, update_by, UpdateBy, update_date, UpdateDate, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode);

        pages->addData(dto);
    }
    return pages;
}

bool CostNameService::saveData(const CostAddDTO::Wrapper& dto,const PayloadDTO& payload)
{
    CostNameDO data; 
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,CostCode, cost_code, CostName, cost_name,CostTypeCode, cost_type_code);
    // 执行数据添加
    CostNameDAO dao;
    return dao.insert(data,payload)==1;
}

bool CostNameService::updateData(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
    CostNameDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CostCode, cost_code, CostName, cost_name, CostTypeCode, cost_type_code, Id, id);
    // 执行数据修改
    CostNameDAO dao;
    return dao.update(data, payload) == 1;
}
