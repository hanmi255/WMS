#include "stdafx.h"
#include "BaActTypeService.h"
#include "../../dao/ba_act_type/BaActTypeDAO.h"
#include <string>
#include "../../domain/do/ba_act_type/BaActTypeDO.h"
#include "../../../lib-common/include/id/SnowFlake.h"

SnowFlake sf(1, 1);


// UUID
std::string generateUuid() {
    
    return std::to_string(sf.nextId());
}

BaActTypeListPageDTO::Wrapper BaActTypeService::listAll(const BaActTypeQuery::Wrapper& query)
{
    auto pages = BaActTypeListPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    BaActTypeDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    pages->total = count;
    pages->calcPages();
    std::list<BaActTypeDO> result = dao.selectWithPage(query);
    for (const auto& sub : result)
    {
        auto dto = BaActTypeDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id,
            act_type_code, ActTypeCode,
            act_type_name, ActTypeName,
            oper_step_code, OperStepCode);
        pages->addData(dto);
    }
    return pages;
}

BaActTypeDTO::Wrapper BaActTypeService::getById(uint64_t _id)
{
    BaActTypeDAO dao;
    // 假设数据库中 id 为字符串，所以将数字转换为字符串
    auto res = dao.selectById(std::to_string(_id));
    if (!res)
        return nullptr;

    auto dto = BaActTypeDTO::createShared();
    ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id,
        act_type_code, ActTypeCode,
        act_type_name, ActTypeName,
        oper_step_code, OperStepCode);
    return dto;
}


uint64_t BaActTypeService::saveData(const BaActTypeAddDTO::Wrapper& dto)
{
    BaActTypeDO data;
    // 前端没有传 id，后端生成新的 id
    data.setId(generateUuid());
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        ActTypeCode, act_type_code,
        ActTypeName, act_type_name,
        OperStepCode, oper_step_code);


    BaActTypeDAO dao;
    return dao.insert(data);
}

uint64_t BaActTypeService::saveData_noid(const std::vector<std::vector<std::string>>& dto)
{
    BaActTypeDAO dao;

    BaActTypeDO data;
    bool flag = true;
    for (auto it = dto.begin() + 1; it != dto.end(); it++) {
        data.setId((*it)[0]),
        data.setCreateName((*it)[1]),
        data.setCreateBy((*it)[2]),
        data.setCreateDate((*it)[3]),
        data.setUpdateName((*it)[4]),
        data.setUpdateBy((*it)[5]),
        data.setUpdateDate((*it)[6]),
        data.setSysOrgCode((*it)[7]),
        data.setSysCompanyCode((*it)[8]),
        data.setActTypeCode((*it)[9]),
        data.setActTypeName((*it)[10]),
        data.setOperStepCode((*it)[11]);

   
        if (dao.insert_noid(data)) {
            flag = false;
        }
    }
    return flag;
}


bool BaActTypeService::updateData(const BaActTypeDTO::Wrapper& dto)
{
    BaActTypeDAO dao;

    BaActTypeDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        ActTypeCode, act_type_code,
        ActTypeName, act_type_name,
        OperStepCode, oper_step_code,
        Id,id
        
    );

    return dao.update(data) == 1;
}

bool BaActTypeService::removeData(const std::string _id)
{
    //uint64_t id = stoi(_id);
    BaActTypeDAO dao;
    // 将数字 id 转换为字符串后删除
    return dao.deleteById(_id) == 1;
}




std::list<BaActTypeDO> BaActTypeService::listAll() {
    BaActTypeDAO dao;
    return dao.listAllDO();
}
