#pragma once
#ifndef _PRODUCT_SERVICE_
#define _PRODUCT_SERVICE_
#include <list>
#include"../../domain/dto/goodcategory/ProductDTO.h"
#include"../../domain/vo/goodcategory/ProductVO.h"

/**
 *	商品类目录入、商品类目修改、商品类目删除的Service层
 */
class ProductService
{
public:

	// 新增商品类目
	uint64_t saveCategory(const ProductListDTO::Wrapper& dto);
	// 修改商品类目
	bool updateCategory(const ProductListDTO::Wrapper& dto);
	// 删除商品类目
	bool removeCategory(const std::string& id);
};

#endif // !_PRODUCT_SERVICE_