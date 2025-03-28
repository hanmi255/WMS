#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/2/22 14:33

*/
#ifndef _GOODS_DIFF_POST_DTO_
#define _GOODS_DIFF_POST_DTO_
#include "../../GlobalInclude.h"
#include "../../query/costconfig/GoodsDiffPostQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点企业等级列表数据对象
 */
class GoodsDiffPostListDTO : public oatpp::DTO
{
	DTO_INIT(GoodsDiffPostListDTO, oatpp::DTO);

	// id
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("diff-post.goods.field.id"), false,"2c9efaca91697e98019227d531751cc2");

	// 储位
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("diff-post.goods.field.bin_id"), false,"X1-1-03");

	// 托盘
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("diff-post.goods.field.tin_id"), false,"2222");

	// 商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("diff-post.goods.field.goods_id"), false,"20222");

	// 商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("diff-post.goods.field.goods_name"), false,"zhe tang");

	// 数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("diff-post.goods.field.goods_qua"), false,"80");

	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("diff-post.goods.field.goods_unit"), false,"**");

	// 生产日期
	API_DTO_FIELD(String, goods_pro_date, ZH_WORDS_GETTER("diff-post.goods.field.goods_pro_date"), false,"2099-12-31");

	// 批次
	API_DTO_FIELD(String, goods_batch, ZH_WORDS_GETTER("diff-post.goods.field.goods_batch"), false,"2099-12-31");

	// 盘点数量
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("diff-post.goods.field.stt_qua"), false,"**");
	
	// 货主名称--客户名称？
	API_DTO_FIELD(String, cus_name, ZH_WORDS_GETTER("diff-post.goods.field.cus_name"), false,"XXXX-KH");

	// 货主--客户？
	API_DTO_FIELD(String, cus, ZH_WORDS_GETTER("diff-post.goods.field.cus"), false,"X00001");

	// 盘点状态
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("diff-post.goods.field.stt_sta"), false,"***");

	// 创建人名称
	API_DTO_FIELD(String, create_name, ZH_WORDS_GETTER("diff-post.goods.field.create_name"), false,"guan-li-yuan");

	// 创建日期
	API_DTO_FIELD(String, create_date, ZH_WORDS_GETTER("diff-post.goods.field.create_date"), false,"2024-09-25 14:18:56");

	// 更新人名称
	API_DTO_FIELD(String, update_name, ZH_WORDS_GETTER("diff-post.goods.field.update_name"), false,"guan-li-yuan");

	// 更新人登录名称
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("diff-post.goods.field.update_by"), false,"admin");

	// 更新日期
	API_DTO_FIELD(String, update_date, ZH_WORDS_GETTER("diff-post.goods.field.update_date"), false,"2024-09-27 17:37:07");

};

/**
 * 盘点企业等级详细数据对象
 */
class GoodsDiffPostDetailDTO : public GoodsDiffPostListDTO
{
	DTO_INIT(GoodsDiffPostDetailDTO, GoodsDiffPostListDTO);

	// 储位
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("diff-post.goods.field.bin_id"));

	// 托盘
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("diff-post.goods.field.tin_id"));

	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("diff-post.goods.field.goods_id"));

	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("diff-post.goods.field.goods_name"));

	// 数量
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("diff-post.goods.field.goods_qua"));

	// 单位
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("diff-post.goods.field.goods_unit"));

	// 生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_date, ZH_WORDS_GETTER("diff-post.goods.field.goods_pro_date"));

	// 批次
	API_DTO_FIELD_DEFAULT(String, goods_batch, ZH_WORDS_GETTER("diff-post.goods.field.goods_batch"));

	// 盘点数量
	API_DTO_FIELD_DEFAULT(String, stt_qua, ZH_WORDS_GETTER("diff-post.goods.field.stt_qua"));
	
	// 货主--客户？
	API_DTO_FIELD_DEFAULT(String, cus, ZH_WORDS_GETTER("diff-post.goods.field.cus"));
	
	// 货主名称--客户名称？
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("diff-post.goods.field.cus_name"));

	// 盘点状态
	API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("diff-post.goods.field.stt_sta"));

	// 盘点类型
	API_DTO_FIELD_DEFAULT(String, stt_type, ZH_WORDS_GETTER("diff-post.goods.field.stt_type"));
};

/**
 * 定义一个盘点企业等级传输对象
 */
class GoodsDiffPostDTO : public GoodsDiffPostListDTO
{
	DTO_INIT(GoodsDiffPostDTO, GoodsDiffPostListDTO);

	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("diff-post.goods.field.create_by"),false,"admin")
	API_DTO_FIELD(String, sys_org_code, ZH_WORDS_GETTER("diff-post.goods.field.sys_org_code"), false,"A05")
	API_DTO_FIELD(String, sys_company_code, ZH_WORDS_GETTER("diff-post.goods.field.sys_company_code"),false,"A05")
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("diff-post.goods.field.cus_code"), false,"X00001")
	API_DTO_FIELD(String, base_unit, ZH_WORDS_GETTER("diff-post.goods.field.base_unit"), false,"null")
	API_DTO_FIELD(String, base_goodscount, ZH_WORDS_GETTER("diff-post.goods.field.base_goodscount"), false,"null")
	API_DTO_FIELD(String, stt_id, ZH_WORDS_GETTER("diff-post.goods.field.stt_id"), false,"2024-09-25 14:18")
	API_DTO_FIELD(String, goods_code, ZH_WORDS_GETTER("diff-post.goods.field.goods_code"), false,"null")
	API_DTO_FIELD(String, stt_type, ZH_WORDS_GETTER("diff-post.goods.field.stt_type"), false,"01")
	API_DTO_FIELD(String, dong_xian, ZH_WORDS_GETTER("diff-post.goods.field.dong_xian"), false,"null")
};

/**
 * 定义一个盘点企业等级分页传输对象
 */
class GoodsDiffPostPageDTO : public PageDTO<GoodsDiffPostDTO::Wrapper>
{
	DTO_INIT(GoodsDiffPostPageDTO, PageDTO<GoodsDiffPostDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_GOODS_DIFF_POST_DTO_