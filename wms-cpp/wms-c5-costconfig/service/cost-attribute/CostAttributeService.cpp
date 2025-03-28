/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 11:34:24

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
#include "CostAttributeService.h"
#include "../../domain/do/cost-attribute/CostAttributeDO.h"
#include "../../dao/cost-attribute/CostAttributeDAO.h"
#include "SimpleDateTimeFormat.h"
#include "../../dao/cost-attribute/CostAttributeDAO.h"
#include "FastDfsClient.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

// 录入用户属性
string CostAttributeService::insert(const CostSxAddDTO::Wrapper& dto)
{
	// 组装DO数据
    CostSxDO data;
    // 生成时间
    string now = SimpleDateTimeFormat::format();
    dto->update_date = now;
    dto->create_date = now;

	ZO_STAR_DOMAIN_DTO_TO_DO(
        data, dto,
        Code, code,
        Name, name,
        CreateName, create_name,
        CreateBy, create_by,
        CreateDate, create_date,
        UpdateName, update_name,
        UpdateBy, update_by,
        UpdateDate, update_date,
        SysOrgCode, sys_org_code,
        SysCompanyCode, sys_company_code);
	// 执行数据插入
	CostAttributeDao dao;
	return dao.insert(data);
}

// 更新用户相关属性
bool CostAttributeService::update(const CostSxModifyDTO::Wrapper& dto)
{
    // 组装DO数据
    CostSxDO data;
    // 生成时间
    string now = SimpleDateTimeFormat::format();
    dto->update_date = now;
    ZO_STAR_DOMAIN_DTO_TO_DO(
        data, dto,
        Id,id,
        Code, code,
        Name, name,
        UpdateName, update_name,
        UpdateBy, update_by,
        UpdateDate, update_date,
        SysOrgCode, sys_org_code,
        SysCompanyCode, sys_company_code);
    // 执行数据更新
    CostAttributeDao dao;
    return dao.update(data);
}

// 查询客户属性名称
CostSxNameListPageDTO::Wrapper CostAttributeService::listName(const CostSxQuery::Wrapper& query) {
    // 构建返回对象
    auto pages = CostSxNameListPageDTO::createShared();

    // 查询数据总条数
    CostAttributeDao dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    list<CostSxDO> result = dao.selectNameWithPage(query);
    // 将DO转换成DTO
    for (CostSxDO sub : result)
    {
        auto dto = CostSxNameListDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name);
        pages->addData(dto);
    }
    return pages;

}

// 查询客户属性
CostSxPageDTO::Wrapper CostAttributeService::listAll(const CostSxQuery::Wrapper& query) {
    // 构建返回对象
    auto pages = CostSxPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    CostAttributeDao dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<CostSxDO> result = dao.selectAllWithPage(query);
    // 将DO转换成DTO
    for (CostSxDO sub : result)
    {
        auto dto = CostSxDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
            id, Id,                   // 编号
            name, Name,               // 客户属性名称
            code, Code,               // 客户属性编码
            create_name, CreateName,  // 创建人名称
            create_by, CreateBy,      // 创建人登录名称
            create_date, CreateDate,  // 创建日期
            update_name, UpdateName,  // 更新人名称
            update_by, UpdateBy,      // 更新人登录名称
            update_date, UpdateDate,  // 更新日期
            sys_org_code, SysOrgCode, // 所属部门
            sys_company_code, SysCompanyCode // 所属公司
        );
        pages->addData(dto);
    }
    return pages;

}
// 删除客户计费属性
bool CostAttributeService::DeleteCostAttribute(const string& id) {
    CostAttributeDAO dao;
    return dao.deleteCostAttribute(id) == 1;
}

// 导入客户计费属性
uint64_t CostAttributeService::ImportCostAttribute(const ImportCostAttributeDTO::Wrapper& dto) {

    CostAttributeDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Id, id,
        CreateName, create_name,
        CreateBy, create_by,
        CreateDate, create_date,
        UpdateName, update_name,
        UpdateBy, update_by,
        UpdateDate, update_date,
        SysOrgCode, sys_org_code,
        SysCompanyCode, sys_company_code,
        KeHuShuXingCode, kehushuxing_code,
        KeHuShuXingName, kehushuxing_name
    );

    CostAttributeDAO dao;
    return dao.importCostAttribute(data);

}

// 导出客户计费属性
list<CostAttributeDO> CostAttributeService::ExportCostAttribute() {
    // 从数据库拿所有客户计费属性数据
    CostAttributeDAO dao;
    list<CostAttributeDO> data = dao.exportCostAttribute();
    /*for (auto& item : data) {
        std::cout << item.getId();
    }*/
    return data;
}