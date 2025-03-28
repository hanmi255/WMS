#include "stdafx.h"
#include "OrderTypeService.h"
#include "../../dao/order_type/OrderTypeDAO.h"

//#include "../../lib-common/include/id/SnowFlake.h"

#include "../../lib-common/include/id/UuidFacade.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"

// 查询订单类型名称列表
OrderTypeNamePageDTO::Wrapper OrderTypeService::listName(const PageQuery::Wrapper& query)
{
	auto pages = OrderTypeNamePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrderTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		 return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrderTypeNameDO> result = dao.selectNameList();
	for (OrderTypeNameDO sub : result)
	{
		auto dto = OrderTypeNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, order_type_name, OrderTypeName);
		pages->addData(dto);
	}
	return pages;
}

// 分页查询所有数据
OrderTypePageDTO::Wrapper OrderTypeService::listAll(const OrderTypeQuery::Wrapper& query)
{
	auto pages = OrderTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrderTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();

	list<OrderTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OrderTypeDO sub : result)
	{
		auto dto = OrderTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, order_type_code, OrderTypeCode, order_type_name, OrderTypeName);
		pages->addData(dto);
	}
	return pages;
}
// 保存数据
uint64_t OrderTypeService::saveData(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	OrderTypeAddDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OrderTypeCode, order_type_code, OrderTypeName, order_type_name);
	// 添加id
	//SnowFlake sf(1, 1);
	//data.setId(std::to_string(sf.nextId()));
	//UuidFacade uuidGenerator {};
	//data.setId(uuidGenerator.genUuid());
	data.setId(UuidFacade().genUuid());

	data.setCreateDate(SimpleDateTimeFormat::format());

	// 创建人名称/创建人登录名称/所属部门/所属公司
	data.setCreateName(payload.getUsername());
	data.setCreateBy(payload.getRealname());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());

	OrderTypeDAO dao;
	return dao.insert(data);
}