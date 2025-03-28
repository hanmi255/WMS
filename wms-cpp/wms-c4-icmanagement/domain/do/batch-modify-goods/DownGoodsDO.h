#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _DOWNGOODS_DO_
#define _DOWNGOODS_DO_
#include "../DoInclude.h"

/**
 * 批量修改下架货物的数据库实体类，与wm_to_down_goods一一对应
 */
class DownGoodsModifyDO
{
	// 编号  
	CC_SYNTHESIZE(string, id, Id);
	//goods_qua : 数量
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);
	//goods_quaok : 完成数量
	CC_SYNTHESIZE(string, goods_quaok, GoodsQuaok);
	//goods_pro_date : 生产日期
	CC_SYNTHESIZE(string, goods_pro_date, GoodsProDate);
	//ku_wei_bian_ma : 库位编码
	CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa);
	//bin_id_from : 源托盘码
	CC_SYNTHESIZE(string, bin_id_from, BinIdFrom);
	//base_unit : 基本单位
	CC_SYNTHESIZE(string, base_unit, BaseUnit);

public:
	DownGoodsModifyDO(){
		id = "";
		goods_qua = "";
		goods_quaok = "";
		goods_pro_date = "";
		ku_wei_bian_ma = "";
		bin_id_from = "";
		base_unit = "";
	}
};
class DownGoodsDO
{
		// 编号  
		CC_SYNTHESIZE(string, id, Id);
		//create_name: 创建人名称
		CC_SYNTHESIZE(string, create_name, CreateName);
		//create_date : 创建日期
		CC_SYNTHESIZE(string, create_date, CreateDate);
		//create_by : 创建人登录名称
		CC_SYNTHESIZE(string, create_by, CreateBy);
		//update_name : 更新人名称
		CC_SYNTHESIZE(string, update_name, UpdateName);
		//update_by : 更新人登录名称
		CC_SYNTHESIZE(string, update_by, UpdateBy);
		//update_date : 更新日期
		CC_SYNTHESIZE(string, update_date, UpdateDate);
		//sys_org_code : 所属部门
		CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
		//sys_company_code : 所属公司
		CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
		//goods_id : 商品编码
		CC_SYNTHESIZE(string, goods_id, GoodsId);
		//goods_qua : 数量
		CC_SYNTHESIZE(string, goods_qua, GoodsQua);
		//goods_quaok : 完成数量
		CC_SYNTHESIZE(string, goods_quaok, GoodsQuaok);
		//order_id : 原始单据编码
		CC_SYNTHESIZE(string, order_id, OrderId);
		//order_id_i : 原始单据行项目
		CC_SYNTHESIZE(string, order_id_i, OrderIdi);
		//goods_unit : 单位
		CC_SYNTHESIZE(string, goods_unit, GoodsUnit);
		//goods_pro_date : 生产日期
		CC_SYNTHESIZE(string, goods_pro_date, GoodsProDate);
		//goods_batch : 批次
		CC_SYNTHESIZE(string, goods_batch, GoodsBatch);
		//act_type_code : 作业类型
		CC_SYNTHESIZE(string, act_type_code, ActTypeCode);
		//ku_wei_bian_ma : 库位编码
		CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa);
		//bin_id_to : 目标托盘
		CC_SYNTHESIZE(string, bin_id_to, BinIdTo);
		//bin_id_from : 源托盘码
		CC_SYNTHESIZE(string, bin_id_from, BinIdFrom);
		//cus : 货主
		CC_SYNTHESIZE(string, cus, Cus);
		//down_sta : 状态
		CC_SYNTHESIZE(string, down_sta, DownSta);
		//base_unit : 基本单位
		CC_SYNTHESIZE(string, base_unit, BaseUnit);
		//base_goodscount : 基本单位数量
		CC_SYNTHESIZE(string, base_goodscount, BaseGoodscount);
		//goods_name : 商品名称
		CC_SYNTHESIZE(string, goods_name, GoodsName);
		//stt_qua : 盘点数量
		CC_SYNTHESIZE(string, stt_qua, SttQua);

public:
	DownGoodsDO()
		: id("")
		, create_name("")
		, create_by("")
		, create_date("")
		, update_name("")
		, update_by("")
		, update_date("")
		, sys_org_code("")
		, sys_company_code("")
		, bin_id_to("")
		, bin_id_from("")
		, goods_id("")
		, goods_name("")
		, goods_qua("")
		, goods_unit("")
		, goods_pro_date("")
		, goods_batch("")
		, stt_qua("")
		, cus("")
		, down_sta("")
		, base_unit("")
		, base_goodscount("")
		, order_id_i("")
		, order_id("")
		, goods_quaok("")
		,ku_wei_bian_ma("")
		,act_type_code("")
	{
	}
};
typedef std::shared_ptr<DownGoodsModifyDO> PtrDownGoodsModifyDO;
// 给GoodsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<DownGoodsDO> PtrDownGoodsDO;
#endif // !_DOWNGOODS_DO_