#include "stdafx.h"
#include "RemovalAdjustService.h"
//#include "../../dao/sample/SampleDAO.h"
#include "../../dao/removal-adjustment/RemovalAdjustDAO.h"


RemovalPageDTO::Wrapper RemovalService::listAll(const RemovalQuery::Wrapper& query)
{
	//具体如何实现分页查询的服务
	// 构建返回对象
	auto pages = RemovalPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RemovalDAO dao;
	//这个DAO是和数据库交互的对象
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;//查询了有多少条数据
	pages->calcPages();//算出有多少页
	list<RemovalDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO 说明这一部分是响应
	//这一部分是让页面的具体信息，把DO放进去
	for (RemovalDO sub : result)
	{
		auto dto = RemovalListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub, id, Id,order_id,Order_id,goods_id,Goods_id,goods_name,Goods_name);
		pages->addData(dto);
	
	}
	//把页面信息返回给Controller
	return pages;
}
RemovalDetailDTO::Wrapper RemovalService::getById(const oatpp::String& id)
{
	oatpp::String oatStr = id;
	std::string stdStr(oatStr->c_str());
	RemovalDAO dao;
	auto res = dao.selectById(stdStr);
	auto dto = RemovalDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto,res,id,Id,order_id,Order_id,goods_id,Goods_id,goods_name,Goods_name,goods_qua, Goods_qua);

	return dto;
}
RemovalDetailPageDTO::Wrapper RemovalService::getdetail(const RemovalQuery::Wrapper& query)
{
	auto pages = RemovalDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	RemovalDAO dao;
	//这个DAO是和数据库交互的对象
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	pages->total = count;//查询了有多少条数据
	pages->calcPages();//算出有多少页
	list<RemovalDO> result = dao.selectdetail(query);
	for (RemovalDO sub : result)
	{
		auto dto = RemovalDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, order_id, Order_id, goods_id, Goods_id, goods_name, Goods_name, goods_qua, Goods_qua);
		pages->addData(dto);

	}
	//把页面信息返回给Controller
	return pages;
}
bool RemovalService::updateData(const RemovalListDTO::Wrapper & dto)
{
	// 组装DO数据
	RemovalDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Id,id,Order_id,order_id,Goods_id,goods_id,Goods_name,goods_name);
	// 执行数据修改
	RemovalDAO dao;
	return dao.update(data) == 1;
}