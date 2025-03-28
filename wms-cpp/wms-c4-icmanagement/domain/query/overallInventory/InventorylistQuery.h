#pragma once
#ifndef _INVENTORYLIST_QUERY_
#define _INVENTORYLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class InventorylistQuery : public PageQuery
{
	DTO_INIT(InventorylistQuery, PageQuery);
	// 移动日期
	API_DTO_FIELD_DEFAULT(String, yidongriqi, ZH_WORDS_GETTER("overall.inventorylist.yidongriqi"));
	// 库存类型
	API_DTO_FIELD_DEFAULT(String, cktype, ZH_WORDS_GETTER("overall.inventorylist.cktype"));
	// 储位
	API_DTO_FIELD_DEFAULT(String, chuwei, ZH_WORDS_GETTER("overall.inventorylist.chuwei"));
	// 托盘
	API_DTO_FIELD_DEFAULT(String, tuopan, ZH_WORDS_GETTER("overall.inventorylist.tuopan"));
	// 货主
	API_DTO_FIELD_DEFAULT(String, huozhu, ZH_WORDS_GETTER("overall.inventorylist.huozhu"));
	// 货主名称
	API_DTO_FIELD_DEFAULT(String, huozhumingcheng, ZH_WORDS_GETTER("overall.inventorylist.huozhumingcheng"));
	// 商品编码
	API_DTO_FIELD_DEFAULT(String, shangpinbianma, ZH_WORDS_GETTER("overall.inventorylist.shangpinbianma"));
	// 商品数量
	API_DTO_FIELD_DEFAULT(String, shangpinshuliang, ZH_WORDS_GETTER("overall.inventorylist.shangpinshuliang"));
	// 商品名称
	API_DTO_FIELD_DEFAULT(String, shangpinmincheng, ZH_WORDS_GETTER("overall.inventorylist.shangpinmincheng"));
	// 生产日期
	API_DTO_FIELD_DEFAULT(String, shengchanriqi, ZH_WORDS_GETTER("overall.inventorylist.shengchanriqi"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INVENTORYLIST_QUERY_