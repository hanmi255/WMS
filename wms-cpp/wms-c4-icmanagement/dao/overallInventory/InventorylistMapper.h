#pragma once
#ifndef _INVENTORY_LIST_MAPER_
#define _INVENTORY_LIST_MAPER_
#include "Mapper.h"
#include "../../domain/do/overallInventory/InventorylistDo.h"
/**
 * 库存表字段匹配映射
 */
class InventorylistMapper : public Mapper<InventorylistDo>
{
public:
	InventorylistDo mapper(ResultSet* resultSet) const override
	{
		InventorylistDo data;
		data.setId(resultSet->getString(1));                   // 编号  
		data.setCreateName(resultSet->getString(2));            // 创建人名称  
		data.setCreateBy(resultSet->getString(3));             // 创建人登录名称  
		data.setCreateDate(resultSet->getString(4));          // 创建日期  
		data.setUpdateName(resultSet->getString(5));           // 更新人名称  
		data.setUpdateBy(resultSet->getString(6));            // 更新人登录名称  
		data.setUpdateDate(resultSet->getString(7));          // 更新日期  
		data.setSysOrgCode(resultSet->getString(8));          // 所属部门  
		data.setSysCompanyCode(resultSet->getString(9));      // 所属公司  
		data.setBinId(resultSet->getString(10));               // 库位编码  
		data.setTinId(resultSet->getString(11));               // 托盘编码  
		data.setGoodsId(resultSet->getString(12));            // 商品编码  
		data.setGoodsName(resultSet->getString(13));           // 商品名称  
		data.setGoodsQua(resultSet->getString(14));           // 数量  
		data.setGoodsUnit(resultSet->getString(15));           // 单位  
		data.setGoodsProDate(resultSet->getString(16));        // 生产日期  
		data.setGoodsBatch(resultSet->getString(17));         // 批次  
		data.setSttQua(resultSet->getString(18));             // 盘点数量  
		data.setCusName(resultSet->getString(19));            // 客户名称  
		data.setCusCode(resultSet->getString(20));            // 客户  
		data.setSttSta(resultSet->getString(21));             // 盘点状态  
		data.setBaseUnit(resultSet->getString(22));            // 基本单位  
		data.setBaseGoodscount(resultSet->getString(23));      // 基本单位数量  
		data.setSttId(resultSet->getString(24));             // stt_id  
		data.setGoodsCode(resultSet->getString(25));          // 商品统一编码  
		data.setSttType(resultSet->getString(26));            // 盘点类型  
		data.setDongXian(resultSet->getString(27));           // 动线
		return data;
	}
};
/**
 * 库存表字段匹配映射-创建智能指针对象
 */
class PtrSampleMapper : public Mapper<PtrInventorylistDo>
{
public:
	PtrInventorylistDo mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<InventorylistDo>();
		data->setId(resultSet->getString(1));                   // 编号  
		data->setCreateName(resultSet->getString(2));            // 创建人名称  
		data->setCreateBy(resultSet->getString(3));             // 创建人登录名称  
		data->setCreateDate(resultSet->getString(4));          // 创建日期  
		data->setUpdateName(resultSet->getString(5));           // 更新人名称  
		data->setUpdateBy(resultSet->getString(6));            // 更新人登录名称  
		data->setUpdateDate(resultSet->getString(7));          // 更新日期  
		data->setSysOrgCode(resultSet->getString(8));          // 所属部门  
		data->setSysCompanyCode(resultSet->getString(9));      // 所属公司  
		data->setBinId(resultSet->getString(10));               // 库位编码  
		data->setTinId(resultSet->getString(11));               // 托盘编码  
		data->setGoodsId(resultSet->getString(12));            // 商品编码  
		data->setGoodsName(resultSet->getString(13));           // 商品名称  
		data->setGoodsQua(resultSet->getString(14));           // 数量  
		data->setGoodsUnit(resultSet->getString(15));           // 单位  
		data->setGoodsProDate(resultSet->getString(16));        // 生产日期  
		data->setGoodsBatch(resultSet->getString(17));         // 批次  
		data->setSttQua(resultSet->getString(18));             // 盘点数量  
		data->setCusName(resultSet->getString(19));            // 客户名称  
		data->setCusCode(resultSet->getString(20));            // 客户  
		data->setSttSta(resultSet->getString(21));             // 盘点状态  
		data->setBaseUnit(resultSet->getString(22));            // 基本单位  
		data->setBaseGoodscount(resultSet->getString(23));      // 基本单位数量  
		data->setSttId(resultSet->getString(24));             // stt_id  
		data->setGoodsCode(resultSet->getString(25));          // 商品统一编码  
		data->setSttType(resultSet->getString(26));            // 盘点类型  
		data->setDongXian(resultSet->getString(27));           // 动线
		return data;
	}
};
#endif // !_GOODS_MANAGE_MAPPER_