#pragma once
#ifndef _PRODUCT_DAO_
#define _PRODUCT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/goodcategory/ProductDO.h"


/**
 * 示例表数据库操作实现
 */
class ProductDAO : public BaseDAO
{
public:
	
	// 新增商品类目
	uint64_t save(const ProductDO& iObj);
	// 修改商品类目
	int update(const ProductDO& uObj);
	// 删除商品类目
	int remove(std::string id);
};
#endif // !_PRODUCT_DAO_