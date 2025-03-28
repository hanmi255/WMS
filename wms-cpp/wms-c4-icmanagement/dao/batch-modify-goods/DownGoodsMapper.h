#pragma once
#ifndef _DOWNGOODS_MAPPER_
#define _DOWNGOODS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/batch-modify-goods/DownGoodsDO.h"
/**
 * 示例表字段匹配映射
 */
class DownGoodsMapper : public Mapper<DownGoodsDO>
{
public:
	//ResultSet通常是用来获取数据库的每个字段
	DownGoodsDO mapper(ResultSet* resultSet) const override
	{
		DownGoodsDO data;
		//用data这个类将数据库的每一个字段给包裹起来
		data.setId(resultSet->getString(1));					// 编号  
		data.setCreateName(resultSet->getString(2));            // 创建人名称  
		data.setCreateBy(resultSet->getString(3));				// 创建人登录名称  
		data.setCreateDate(resultSet->getString(4));			// 创建日期  
		data.setUpdateName(resultSet->getString(5));			// 更新人名称  
		data.setUpdateBy(resultSet->getString(6));				// 更新人登录名称  
		data.setUpdateDate(resultSet->getString(7));			// 更新日期  
		data.setSysOrgCode(resultSet->getString(8));			// 所属部门  
		data.setSysCompanyCode(resultSet->getString(9));		// 所属公司  
		data.setGoodsId(resultSet->getString(10));				// 商品编码  
		data.setGoodsQua(resultSet->getString(11));				// 数量  
		data.setGoodsQuaok(resultSet->getString(12));           // 完成数量 
		data.setOrderId(resultSet->getString(13));				// 原始单据编码
		data.setOrderIdi(resultSet->getString(14));				// 原始单据行项目  
		data.setGoodsUnit(resultSet->getString(15));			// 单位  
		data.setGoodsProDate(resultSet->getString(16));			// 生产日期  
		data.setGoodsBatch(resultSet->getString(17));			// 批次  
		data.setActTypeCode(resultSet->getString(18));			// 作业类型
		data.setBinIdTo(resultSet->getString(19));				// 目标托盘
		data.setBinIdFrom(resultSet->getString(20));            // 源托盘码  
		data.setCus(resultSet->getString(21));					// 货主 
		data.setDownSta(resultSet->getString(22));				// 状态 
		data.setBaseUnit(resultSet->getString(23));				// 基本单位  
		data.setBaseGoodscount(resultSet->getString(24));		// 基本单位数量  
		data.setGoodsName(resultSet->getString(25));			// 商品名称 
		return data;
	}
};

/**
 * 库存表字段匹配映射-创建智能指针对象
 */
class PtrGoodsMapper : public Mapper<PtrDownGoodsDO>
{
public:
	PtrDownGoodsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DownGoodsDO>();
		data->setId(resultSet->getString(1));					// 编号  
		data->setCreateName(resultSet->getString(2));           // 创建人名称  
		data->setCreateBy(resultSet->getString(3));				// 创建人登录名称  
		data->setCreateDate(resultSet->getString(4));			// 创建日期  
		data->setUpdateName(resultSet->getString(5));			// 更新人名称  
		data->setUpdateBy(resultSet->getString(6));				// 更新人登录名称  
		data->setUpdateDate(resultSet->getString(7));			// 更新日期  
		data->setSysOrgCode(resultSet->getString(8));			// 所属部门  
		data->setSysCompanyCode(resultSet->getString(9));		// 所属公司  
		data->setGoodsId(resultSet->getString(10));				// 商品编码  
		data->setGoodsQua(resultSet->getString(11));			// 数量  
		data->setGoodsQuaok(resultSet->getString(12));          // 完成数量 
		data->setOrderId(resultSet->getString(13));				// 原始单据编码
		data->setOrderIdi(resultSet->getString(14));			// 原始单据行项目  
		data->setGoodsUnit(resultSet->getString(15));			// 单位  
		data->setGoodsProDate(resultSet->getString(16));		// 生产日期  
		data->setGoodsBatch(resultSet->getString(17));			// 批次  
		data->setActTypeCode(resultSet->getString(18));			// 作业类型
		data->setBinIdTo(resultSet->getString(19));				// 目标托盘
		data->setBinIdFrom(resultSet->getString(20));           // 源托盘码  
		data->setCus(resultSet->getString(21));					// 货主 
		data->setDownSta(resultSet->getString(22));				// 状态 
		data->setBaseUnit(resultSet->getString(23));			// 基本单位  
		data->setBaseGoodscount(resultSet->getString(24));		// 基本单位数量  
		data->setGoodsName(resultSet->getString(25));			// 商品名称 
		return data;
	}
};


#endif // !_DOWNGOODS_MAPPER_