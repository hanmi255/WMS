#pragma once
#ifndef _LISTGOODS_QUERY_
#define _LISTGOODS_QUERY_

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
 * 上架货物分页查询对象
 */
class ListgoodsQuery1 : public PageQuery
{
	//初始化
	DTO_INIT(ListgoodsQuery1, PageQuery);

	//唯一id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("lis.field.id"));
	
	//创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("lis.field.crename"));

	// 创建人登录名称
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("lis.field.creloginame"));

	// 创建日期
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("lis.field.credate"));

	// 更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("lis.field.updname"));

	// 更新人登录名称
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("lis.field.updloginame"));

	//更新日期
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("lis.field.upddate"));

	//所属部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("lis.field.sysorgcode"));

	//所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("lis.field.syscompanycode"));
	
	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("lis.field.goodscode"));

	// 商品数量
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("lis.field.goodsqua"));

	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("lis.field.goodsname"));

	// 原始单据类型
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("lis.field.orgbilltype"));
	
	// 原始单据编码
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("lis.field.orgbillcode"));

	// 原始单据行项目
	API_DTO_FIELD_DEFAULT(String, order_id_i, ZH_WORDS_GETTER("lis.field.orgbillrow"));

	// 上架id
	API_DTO_FIELD_DEFAULT(String, wm_to_up_id, ZH_WORDS_GETTER("lis.field.goodsupid"));
	
	// 单位
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("lis.field.goodsunit"));

	// 批次
	API_DTO_FIELD_DEFAULT(String, goods_batch, ZH_WORDS_GETTER("lis.field.goodsbatch"));

	// 生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("lis.field.goodscredata"));

	// 作业类型
	API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("lis.field. acttypecode"));

	// 库位编码
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("lis.field.kuweicode"));

	// 托盘码
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("lis.field.tuobancode"));

	// 货主
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("lis.field.huozhu"));

	// 基本单位
	API_DTO_FIELD_DEFAULT(String, base_unit, ZH_WORDS_GETTER("lis.field.baseunit"));

	// 基本单位数量
	API_DTO_FIELD_DEFAULT(String, base_goodscount, ZH_WORDS_GETTER("lis.field. basegoodscount"));
};




/**
 * 上架货物分页查询对象(继承用)
 */
class ListgoodsQuery : public PageQuery
{
	//初始化
	DTO_INIT(ListgoodsQuery, PageQuery);

	//唯一id
	API_DTO_FIELD_DEFAULT(Int32, id, ZH_WORDS_GETTER("lis.field.id"));



	// 创建日期
	API_DTO_FIELD_DEFAULT(String, credate, ZH_WORDS_GETTER("lis.field.credate"));



	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goodscode, ZH_WORDS_GETTER("lis.field.goodscode"));



	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goodsname, ZH_WORDS_GETTER("lis.field.goodsname"));

	

	// 原始单据编码
	API_DTO_FIELD_DEFAULT(String, orgbillcode, ZH_WORDS_GETTER("lis.field.orgbillcode"));



	// 单位
	API_DTO_FIELD_DEFAULT(String, goodsunit, ZH_WORDS_GETTER("lis.field.goodsunit"));


	// 货主
	API_DTO_FIELD_DEFAULT(String, huozhu, ZH_WORDS_GETTER("lis.field.huozhu"));
};





/**
 * 导出调整上架数据---有查询条件
 */
class ExportDataQuery : public ListgoodsQuery
{
	DTO_INIT(ExportDataQuery, ListgoodsQuery);
	//创建日期---起始
	API_DTO_FIELD_DEFAULT(String, credate_start, ZH_WORDS_GETTER("lis.field.credate_start"));
	//创建日期---终止
	API_DTO_FIELD_DEFAULT(String, credate_end, ZH_WORDS_GETTER("lis.field.credate_end"));
	// 创建人登录名称
	API_DTO_FIELD_DEFAULT(String, creloginame, ZH_WORDS_GETTER("lis.field.creloginame"));
	// 库位编码
	API_DTO_FIELD_DEFAULT(String, kuweicode, ZH_WORDS_GETTER("lis.field.kuweicode"));
	// 托盘码
	API_DTO_FIELD_DEFAULT(String, tuobancode, ZH_WORDS_GETTER("lis.field.tuobancode"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTGOODS_QUERY_
