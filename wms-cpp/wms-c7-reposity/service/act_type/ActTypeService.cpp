#include "stdafx.h"
#include "ActTypeService.h"
#include "../../dao/act_type/ActTypeDAO.h"
//#include "../../lib-common/include/id/SnowFlake.h"
#include "../../lib-common/include/id/UuidFacade.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"

ActTypePageDTO::Wrapper ActTypeService::listAll(const ActTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ActTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	ActTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ActTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ActTypeDO sub : result)
    {
       auto dto = ActTypeDTO::createShared();
	   ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, act_type_code, ActTypeCode, act_type_name, ActTypeName, oper_step_code, OperStepCode);
	   //ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, act_type_code, ActTypeCode, act_type_name, ActTypeName, oper_step_code, OperStepCode);
	   pages->addData(dto);
    }
	return pages;
}

uint64_t ActTypeService::saveData(const ActTypeBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	ActTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ActTypeCode, act_type_code, ActTypeName, act_type_name, OperStepCode, oper_step_code);
	// 添加id
	//SnowFlake sf(1, 1);
	//data.setId(std::to_string(sf.nextId()));
	UuidFacade uuidGenerator {};
	data.setId(uuidGenerator.genUuid());

	data.setCreateDate(SimpleDateTimeFormat::format());

	// 创建人名称/创建人登录名称/所属部门/所属公司
	data.setCreateName(payload.getUsername());
	data.setCreateBy(payload.getRealname());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());

	// 执行数据添加
	ActTypeDAO dao;
	return dao.insert(data);
}

