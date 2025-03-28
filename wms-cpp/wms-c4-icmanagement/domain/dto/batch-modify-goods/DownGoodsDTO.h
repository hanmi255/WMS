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

#ifndef _DOWNGOODS_DTO_
#define _DOWNGOODS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//基本数据对象
class DownGoodsBaseDTO : public oatpp::DTO
{
	DTO_INIT(DownGoodsBaseDTO, DTO);
	//唯一标识
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("goods.field.id"), false, "1");
};

//批量修改的DTO
class DownGoodsModifyDTO : public DownGoodsBaseDTO
{

	DTO_INIT(DownGoodsModifyDTO, DownGoodsBaseDTO);

	//goods_qua : 数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("goods.field.goods_qua"), false, "80");

	//goods_quaok : 完成数量(复核数量)
	API_DTO_FIELD(String, goods_quaok, ZH_WORDS_GETTER("goods.field.goods_quaok"), false, "80");

	//base_unit : 基本单位
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("goods.field.base_unit"), false, "null");

	//goods_pro_date : 生产日期
	API_DTO_FIELD(String, goods_pro_date, ZH_WORDS_GETTER("goods.field.goods_pro_date"), false, "2099-12-31");
	
	//bin_id_from : 源托盘码
	API_DTO_FIELD(String, bin_id_from, ZH_WORDS_GETTER("goods.field.bin_id_from"), false, "X1-1-03");
	
	//ku_wei_bian_ma : 库位编码
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("goods.field.ku_wei_bian_ma"), false, "123");

	////update_name : 更新人名称
	//API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("goods.field.update_name"), false, "admin");

	////update_by : 更新人登录名称
	//API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("goods.field.update_by"), false, "admin");

	////update_date : 更新日期
	//API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("goods.field.update_date"), false, "2024-09-09");
};


class DownGoodsDTO : public DownGoodsBaseDTO 
{

	DTO_INIT(DownGoodsDTO, DownGoodsBaseDTO);
	//create_name: 创建人名称
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("goods.field.create_name"), false, "admin");

	//create_date : 创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("goods.field.create_date"), false, "2024-09-09");

	//create_by : 创建人登录名称
	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("goods.field.create_by"), false, "admin");

	//update_name : 更新人名称
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("goods.field.update_name"), false, "admin");

	//update_by : 更新人登录名称
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("goods.field.update_by"), false, "admin");

	//update_date : 更新日期
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("goods.field.update_date"), false, "2024-09-09");

	//sys_org_code : 所属部门
	API_DTO_FIELD(String, sys_org_code, ZH_WORDS_GETTER("goods.field.sys_org_code"), false, "A05");

	//sys_company_code : 所属公司
	API_DTO_FIELD(String, sys_company_code, ZH_WORDS_GETTER("goods.field.sys_company_code"), false, "A05");

	//goods_id : 商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("goods.field.goods_id"), false, "20222");

	//goods_qua : 数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("goods.field.goods_qua"), false, "80");

	//goods_quaok : 完成数量(复核数量)
	API_DTO_FIELD(String, goods_quaok, ZH_WORDS_GETTER("goods.field.goods_quaok"), false, "80");

	//order_id : 原始单据编码
	API_DTO_FIELD(String, order_id, ZH_WORDS_GETTER("goods.field.order_id"), false, "80");

	//order_id_i : 原始单据行项目
	API_DTO_FIELD(String, order_id_i, ZH_WORDS_GETTER("goods.field.order_id_i"), false, "80");

	//goods_unit : 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("goods.field.goods_unit"), false, "**");

	//goods_pro_date : 生产日期
	API_DTO_FIELD(String, goods_pro_date, ZH_WORDS_GETTER("goods.field.goods_pro_date"), false, "2099-12-31");

	//goods_batch : 批次
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("goods.field.goods_batch"), false, "2");

	//act_type_code : 作业类型
	API_DTO_FIELD(String, act_type_code, ZH_WORDS_GETTER("goods.field.act_type_code"), false, "NULL");

	//ku_wei_bian_ma : 库位编码
	API_DTO_FIELD(String, ku_wei_bian_ma, ZH_WORDS_GETTER("goods.field.ku_wei_bian_ma"), false, "123");

	//bin_id_to : 目标托盘
	API_DTO_FIELD(String, bin_id_to, ZH_WORDS_GETTER("goods.field.bin_id_to"), false, "X1-1-03");

	//bin_id_from : 源托盘码
	API_DTO_FIELD(String, bin_id_from, ZH_WORDS_GETTER("goods.field.bin_id_from"), false, "X1-1-03");

	//cus : 货主
	API_DTO_FIELD(String, cus, ZH_WORDS_GETTER("goods.field.cus"), false, "X1-1-03");

	//down_sta : 状态
	API_DTO_FIELD(String, down_sta, ZH_WORDS_GETTER("goods.field.down_sta"), false, "X1-1-03");

	//base_unit : 基本单位
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("goods.field.base_unit"), false, "null");

	//base_goodscount : 基本单位数量
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("goods.field.base_goodscount"), false, "null");

};
//用来进行批量修改下架货物数据的DTO和DO之间的转换
class DownGoodsBatchDTO : public oatpp::DTO {
	DTO_INIT(DownGoodsBatchDTO, DTO)
		DTO_FIELD(Vector<DownGoodsModifyDTO::Wrapper>, dtoList);  ///< 批量修改的数据列表
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_DOWNGOODS_DTO_