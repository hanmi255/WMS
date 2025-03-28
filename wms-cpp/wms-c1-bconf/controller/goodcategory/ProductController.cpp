#include "stdafx.h"
#include "ProductController.h"
#include"../../service/goodcategory/ProductService.h"
StringJsonVO::Wrapper ProductController::execAddProduct(const ProductListDTO::Wrapper& dto) {
	auto product = StringJsonVO::createShared();
	// 定义返回数据对象
	
	// 参数校验
	// 非空校验
	
	if (!dto->categorylevel || !dto->categoryname || !dto->categorynum)
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}
	
	// 有效值校验

	if (dto->categorynum ->empty() || !dto->categorylevel || dto->categoryname->empty())
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}

	// 定义一个Service
	ProductService service;
	// 执行数据新增
	uint64_t id = service.saveCategory(dto);
	if (id > 0) {
		product->success(String(std::to_string(id)));
	}
	else
	{
		product->fail(String(std::to_string(id)));
	}
	//响应结果
	return product;
	
}
StringJsonVO::Wrapper ProductController::execModifyProduct(const ProductListDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto product = StringJsonVO::createShared();
	// 参数校验
	
	if (!dto->categoryname->empty() || dto->categorynum->empty())
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}
	
	// 定义一个Service
	ProductService service;
	// 执行数据修改
	
	if (service.updateCategory(dto)) {
		product->success(dto->categoryname);
	}
	
	else
	{
		product->fail(dto->categoryname);
	}
	
	// 响应结果
	return product;
	
}
StringJsonVO::Wrapper ProductController::execRemoveProduct(const String& id) {
	// 定义返回数据对象
	auto product = StringJsonVO::createShared();
	// 参数校验
	if (id.getValue("").empty())
	{
		product->init(String(""), RS_PARAMS_INVALID);
		return product;
	}
	
	// 定义一个Service
	ProductService service;
	// 执行数据删除
	if (service.removeCategory(id.getValue(""))) {		//这里有个move函数重载错误，但不知道怎么改
		product->success(id);
	}
	else
	{
		product->fail(id);
	}
	
	// 响应结果
	return product;
	
}