#include "stdafx.h"
#include "GoodsTypeService.h"
#include "../../dao/goodstype/GoodsTypeDAO.h"

uint64_t GoodsTypeService::saveData(const GoodsTypeAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	GoodsTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code, Name, name);
	// 执行数据添加
	GoodsTypeDAO dao;
	return dao.insert(data, payload);
}
