#include "ExpirationDateEarlyWarningService.h"

#include "stdafx.h"
#include "dao/expiration-date-early-warning/ExpirationDateEarlyWarningDAO.h"


ExpirationDateEarlyWarningPageVO::Wrapper ExpirationDateEarlyWarningService::listAll(const ExpirationDateEarlyWarningQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ExpirationDateEarlyWarningPageVO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ExpirationDateEarlyWarningDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<StockYJDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (StockYJDO sub : result)
	{
		auto dto = ExpirationDateEarlyWarningVO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, productcode, Goods_Id, customerproductcode, Shp_Bian_Makh, productname, Shp_Ming_Cheng, customercode, Cus_Code, productiondate, Goods_Pro_Data, expirationdate, Dqr, theremainingratio, GuoQiBiLi, inventorytype, KuCType, basicquantity, Base_GoodsCount, basicunit, Base_Unit, bzhi_qi, Bzhi_Qi, res_date, Res_Date, customername,Cus_Name);
		pages->addData(dto);
	}
	return pages;
}
