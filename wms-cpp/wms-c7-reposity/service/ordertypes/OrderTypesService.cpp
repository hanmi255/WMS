/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "OrderTypesService.h"
#include "../../dao/ordertypes/OrderTypesDAO.h"

bool OrderTypesService::updateData(const ModifyOrderTypeDTO::Wrapper& dto)
{
	// 组装DO数据
	OrderTypesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, order_type_code, Name, order_type_name);
	// 执行数据修改
	OrderTypesDAO dao;
	return dao.update(data) == 1;
}

bool OrderTypesService::removeData(string id)
{
	OrderTypesDAO dao;
	return dao.deleteById(id) == 1;
}
