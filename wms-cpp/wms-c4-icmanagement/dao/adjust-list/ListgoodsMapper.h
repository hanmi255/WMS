#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _LIST_GOODS_MAPPER_
#define _LIST_GOODS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/adjust-list/wm_to_up_goodsDO.h"

/**
 * 库存表字段匹配映射
 */
class ListGoodsMapper : public Mapper<Wm_To_Up_GoodsDO>
{
public:
	Wm_To_Up_GoodsDO mapper(ResultSet* resultSet) const override
	{
		Wm_To_Up_GoodsDO data;
		data.setId(resultSet->getString(1));                   // 编号  
		data.setCreateName(resultSet->getString(2));           // 创建人名称  
		data.setCreateBy(resultSet->getString(3));            // 创建人登录名称  
		data.setCreateDate(resultSet->getString(4));           // 创建日期  // 修复：添加缺失的create_date字段  
		data.setUpdateName(resultSet->getString(5));            // 更新人名称  
		data.setUpdateBy(resultSet->getString(6));             // 更新人登录名称  
		data.setUpdateDate(resultSet->getString(7));           // 更新日期  
		data.setSysOrgCode(resultSet->getString(8));           // 所属部门  
		data.setSysCompanyCode(resultSet->getString(9));       // 所属公司  
		data.setGoodsId(resultSet->getString(10));             // 商品编码  
		data.setGoodsQua(resultSet->getString(11));           // 数量  
		data.setOrderTypeCode(resultSet->getString(12));       // 原始单据类型  
		data.setOrderId(resultSet->getString(13));             // 原始单据编码  
		data.setOrderIdI(resultSet->getString(14));            // 原始单据行项目  
		data.setWmToUpId(resultSet->getString(15));           // 上架ID  
		data.setGoodsUnit(resultSet->getString(16));          // 单位  
		data.setGoodsBatch(resultSet->getString(17));         // 批次  
		data.setGoodsProData(resultSet->getString(18));       // 生产日期  
		data.setActTypeCode(resultSet->getString(19));         // 作业类型  
		data.setKuWeiBianMa(resultSet->getString(20));        // 库位编码  
		data.setBinId(resultSet->getString(21));             // 托盘码  
		data.setCusCode(resultSet->getString(22));            // 货主  
		data.setBaseUnit(resultSet->getString(23));            // 基本单位  
		data.setBaseGoodscount(resultSet->getString(24));      // 基本单位数量  
		data.setGoodsName(resultSet->getString(25));           // 商品名称  // 修复：商品名称字段索引调整为25  
		return data;
	}
};

/**
 * 库存表字段匹配映射-创建智能指针对象
 */
class PtrSampleMapper : public Mapper<PtrWm_To_Up_GoodsDO>
{
public:
	PtrWm_To_Up_GoodsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<Wm_To_Up_GoodsDO>();
		data->setId(resultSet->getString(1));                   // 编号  
		data->setCreateName(resultSet->getString(2));           // 创建人名称  
		data->setCreateBy(resultSet->getString(3));            // 创建人登录名称  
		data->setCreateDate(resultSet->getString(4));           // 创建日期  // 修复：添加缺失的create_date字段  
		data->setUpdateName(resultSet->getString(5));            // 更新人名称  
		data->setUpdateBy(resultSet->getString(6));             // 更新人登录名称  
		data->setUpdateDate(resultSet->getString(7));           // 更新日期  
		data->setSysOrgCode(resultSet->getString(8));           // 所属部门  
		data->setSysCompanyCode(resultSet->getString(9));       // 所属公司  
		data->setGoodsId(resultSet->getString(10));             // 商品编码  
		data->setGoodsQua(resultSet->getString(11));           // 数量  
		data->setOrderTypeCode(resultSet->getString(12));       // 原始单据类型  
		data->setOrderId(resultSet->getString(13));             // 原始单据编码  
		data->setOrderIdI(resultSet->getString(14));            // 原始单据行项目  
		data->setWmToUpId(resultSet->getString(15));           // 上架ID  
		data->setGoodsUnit(resultSet->getString(16));          // 单位  
		data->setGoodsBatch(resultSet->getString(17));         // 批次  
		data->setGoodsProData(resultSet->getString(18));       // 生产日期  
		data->setActTypeCode(resultSet->getString(19));         // 作业类型  
		data->setKuWeiBianMa(resultSet->getString(20));        // 库位编码  
		data->setBinId(resultSet->getString(21));             // 托盘码  
		data->setCusCode(resultSet->getString(22));            // 货主  
		data->setBaseUnit(resultSet->getString(23));            // 基本单位  
		data->setBaseGoodscount(resultSet->getString(24));      // 基本单位数量  
		data->setGoodsName(resultSet->getString(25));           // 商品名称  // 修复：商品名称字段索引调整为25  
		return data;
	}
};

#endif // !_LIST_GOODS_MAPPER_