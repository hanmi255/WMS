#pragma once

#ifndef _CHECK_DTO_
#define _CHECK_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点基础数据，要解释的基本数据
 */
class CheckBaseDTO : public oatpp::DTO
{
	DTO_INIT(CheckBaseDTO, DTO);
	//ID
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("mql.rest.id"), false, "2c9efaca91697e98019227d531751cc2");

	//创建人名称
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("mql.creat.create_name"), false, ZH_WORDS_GETTER("inv.manager"));

	//创建人登录名称
	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("mql.creat.create_by"), false, ZH_WORDS_GETTER("admin"));

	//创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("mql.creat.create_date"), false, "2099-12-31");

	//更新人名称
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("mql.update.update_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//更新人登录名称
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("mql.update.update_by"), false, "admin");
	//更新日期
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("mql.update.update_date"), false, "2099-12-31");
	//所属部门
	API_DTO_FIELD(String, sys_org_code, ZH_WORDS_GETTER("mql.sys.sys_org_code"), false, "A05");
	//所属公司
    API_DTO_FIELD(String, sys_company_code, ZH_WORDS_GETTER("mql.sys.sys_company_code"), false, "A05");
	// 储位
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");
	//托盘
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");
	//商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");
	//商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));
	//数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");
	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));
	//生产日期
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");
	// 批次
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("mql.goods.goods_batch"), false, "2099-12-31");
	//盘点数量
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");
	//客户名称
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("mql.cus.cus_name"), false, "XXXX-KH有限公司");
	//客户
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "X00001");
	//盘点状态
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
	//基本单位
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("mql.base.base_unit"), false, "0");
	//基本单位数量
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("mql.base.base_goodscount"), false, "0");
	//stt_id
	API_DTO_FIELD(String, stt_id, "stt_id", false, "2024-10-15 20:38");
	//商品统一编码
	API_DTO_FIELD(String, goods_code, ZH_WORDS_GETTER("mql.goods.goods_code"), false, "0");
	//盘点类型
	API_DTO_FIELD(String, stt_type, ZH_WORDS_GETTER("mql.stt.stt_type"), false, "01");
	//动线
	API_DTO_FIELD(String, dong_xian, ZH_WORDS_GETTER("mql.rest.dong_xian"), false, "0");


};
/**
 * 盘点列表新增数据对象
 */
class CheckAddDTO : public CheckBaseDTO
{
	DTO_INIT(CheckAddDTO, CheckBaseDTO);
	// 储位
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");
	//托盘
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");
	//商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");
	//商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));
	//数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");
	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));
	//生产日期
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");
	// 批次
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("mql.goods.goods_batch"), false, "2099-12-31");
	//盘点数量
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");
	//货主名称
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("mql.cus.cus_name"), false, "JCGAMING");
	//货主
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");
	//盘点状态
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
	//创建人名称
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("mql.creat.create_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("mql.creat.create_date"), false, "2099-12-31");
	//更新人名称
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("mql.update.update_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//更新人登录名称
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("mql.update.update_by"), false, "admin");
	//更新日期
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("mql.update.update_date"), false, "2099-12-31");
};

/**
 * 盘点人详细数据列表
 */
class CheckDtailDTO : public CheckAddDTO
{
	DTO_INIT(CheckDtailDTO, CheckAddDTO);
	///ID
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("mql.rest.id"), false, "1");
	// 储位
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");
	//托盘
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");
	//商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");
	//商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));
	//数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");
	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));
	//生产日期
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");
	// 批次
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("mql.goods.goods_batch"), false, "2099-12-31");
	//盘点数量
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");
	//货主名称
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("mql.cus.cus_name"), false, "JCGAMING");
	//货主
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");
	//盘点状态
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
	//创建人名称
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("mql.creat.create_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("mql.creat.create_date"), false, "2099-12-31");
	//更新人名称
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("mql.update.update_name"), false, ZH_WORDS_GETTER("inv.manager"));
	//更新人登录名称
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("mql.update.update_by"), false, "admin");
	//更新日期
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("mql.update.update_date"), false, "2099-12-31");
};
///**
// * 盘点人的唯一标识
// */
//class CheckListDTO : public oatpp::DTO
//{
//	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("inv.inventorystatus"));
//}
/**
 * 盘点人列表分页对象
 */
class CheckPageDTO : public PageDTO<CheckBaseDTO::Wrapper>
{
	DTO_INIT(CheckPageDTO, PageDTO<CheckBaseDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECK_DTO_#pragma once
