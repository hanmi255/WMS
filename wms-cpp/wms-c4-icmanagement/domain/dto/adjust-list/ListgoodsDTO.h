#pragma once
#ifndef _LISTGOODS_DTO_
#define _LISTGOODS_DTO_

/*****************************************************************************
	*  @COPYRIGHT NOTICE
	*  @Copyright (c) 2013, kato1
	*  @All rights reserved
	*  @file	 : ListgoodsController.cpp
	*  @version  : ver 1.0
	*  @author   : kato1
	*  @date     : 2025/2/26 17:04
	*  @brief    : brief
*****************************************************************************/

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)





/**
*基本上架货物数据对象
*/


class BaseListgoodsDTO : public oatpp::DTO
{
	//初始化
	DTO_INIT(BaseListgoodsDTO, oatpp::DTO);

	//唯一id
	API_DTO_FIELD(String, id, "id", true, "0");

};



/**
*修改上架货物数据对象
*/
class ListgoodsadjustDTO : public BaseListgoodsDTO
{
	//初始化
	DTO_INIT(ListgoodsadjustDTO, BaseListgoodsDTO);
	
	// 商品数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"),false,"1");

	// 生产日期
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("lis.field.goodscredata"), false, "xxxx-xx-xx");

	// 托盘码
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"), false, "ATP002");

	// 库位编码
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"), false, "X1-1-01");

	// 基本单位
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"), false, ZH_WORDS_GETTER("lis.field.box"));

};


/**
 * 上架货物列表数据对象
 */
class ListgoodsDTO : public ListgoodsadjustDTO
{
	//初始化
	DTO_INIT(ListgoodsDTO, ListgoodsadjustDTO);

	// 创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("lis.field.credate"), false, "xxxx-xx-xx");

	// 商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"),false, "RL001");

	// 商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("lis.field.goodsname"),false, ZH_WORDS_GETTER("lis.field.meat"));

	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"),false, ZH_WORDS_GETTER("lis.field.box"));


	// 原始单据编码
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"),false, "RK20240320-0003");


	// 货主
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"),false, "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")));
};




/**
 * 上架货物列表基本分页数据对象
 */
class ListgoodsBasePageDTO : public BaseListgoodsDTO
{
	//初始化
	DTO_INIT(ListgoodsBasePageDTO, BaseListgoodsDTO);



	// 创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("lis.field.credate"), false, "xxxx-xx-xx");


	// 商品数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"), false, "1");


	// 库位编码
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"), false, "X1-1-01");


	// 托盘码
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"), false, "ATP002");


	// 基本单位
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"), false, ZH_WORDS_GETTER("lis.field.box"));

	// 商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"), false, "RL001");

	// 商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("lis.field.goodsname"), false, ZH_WORDS_GETTER("lis.field.meat"));

	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"), false, ZH_WORDS_GETTER("lis.field.box"));


	// 原始单据编码
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"), false, "RK20240320-0003");


	// 货主
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"), false, "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")));

	// 基本单位数量
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("lis.field.basegoodscount"), false, "3");
};



/**
 * 上架货物列表分页数据对象
 */
class ListgoodsPageDTO : public PageDTO<ListgoodsBasePageDTO::Wrapper>
{
	//初始化
	DTO_INIT(ListgoodsPageDTO, PageDTO<ListgoodsBasePageDTO::Wrapper>);


};





/**
 * 上架货物详细数据对象(由于详细信息一般都包括列表数据,因此可以继承于列表数据)
 */
class ListgoodsDetailDTO : public BaseListgoodsDTO
{
	//初始化
	DTO_INIT(ListgoodsDetailDTO, ListgoodsDTO);

	// 创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("lis.field.credate"), false, "xxxx-xx-xx");


	// 商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"), false, "RL001");


	// 原始单据编码
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"), false, "RK20240320-0003");


	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"), false, ZH_WORDS_GETTER("lis.field.box"));

	
	// 货主
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"), false, "X00001-XXXX-KH" + (ZH_WORDS_GETTER("lis.field.company")));


	// 商品数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"), false, "1");

	// 生产日期
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("lis.field.goodscredata"), false, "xxxx-xx-xx");


	// 库位编码
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"), false, "X1-1-01");

	// 托盘码
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"), false, "ATP002");


	// 基本单位
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"), false, ZH_WORDS_GETTER("lis.field.box"));


	// 基本单位数量
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("lis.field.basegoodscount"), false, "3");
};





#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTGOODS_DTO_