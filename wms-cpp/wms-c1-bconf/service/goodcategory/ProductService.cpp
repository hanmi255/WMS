#include "stdafx.h"
#include "ProductService.h"
#include "../../dao/goodcatgory/ProductDAO.h"
#include"../../domain/do/goodcategory/ProductDO.h"
#include"../../domain/dto/goodcategory/ProductDTO.h"

uint64_t ProductService::saveCategory(const ProductListDTO::Wrapper& dto)
{
	
	// 组装DO数据
	ProductDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,PID,pid,Categoryname, categoryname, Categorylevel, categorylevel, Categorynum, categorynum,Topnode,topnode);
	// 执行新增商品类目
	ProductDAO dao;
	return dao.save(data);
}

bool ProductService::updateCategory(const ProductListDTO::Wrapper& dto)
{
	// 组装DO数据
	ProductDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PID, pid, Categoryname, categoryname, Categorylevel, categorylevel, Categorynum, categorynum, Topnode, topnode);
	// 执行修改商品类目
	ProductDAO dao;
	return dao.update(data) == 1;
}

bool ProductService::removeCategory(const std::string& id)
{
	//执行删除商品类目
	ProductDAO dao;
	return dao.remove(id) == 1;
}
