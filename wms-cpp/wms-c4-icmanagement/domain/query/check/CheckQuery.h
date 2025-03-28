#pragma once

#ifndef _CHECK_QUERY_
#define _CHECK_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点人查询对象
 */
class CheckQuery : public PageQuery
{
	DTO_INIT(CheckQuery, PageQuery);
    // ID
    DTO_FIELD(String, id);
    // 创建人名称
    DTO_FIELD(String, create_name);
    // 创建人登录名称
    DTO_FIELD(String, create_by);
    // 创建日期
    DTO_FIELD(String, create_date);
    // 更新人名称
    DTO_FIELD(String, update_name);
    // 更新人登录名称
    DTO_FIELD(String, update_by);
    // 更新日期
    DTO_FIELD(String, update_date);
    // 所属部门
    DTO_FIELD(String, sys_org_code);
    // 所属公司
    DTO_FIELD(String, sys_company_code);
    // 储位
    DTO_FIELD(String, bin_id);
    // 托盘
    DTO_FIELD(String, tin_id);
    // 商品编码
    DTO_FIELD(String, goods_id);
    // 商品名称
    DTO_FIELD(String, goods_name);
    // 数量
    DTO_FIELD(String, goods_qua);
    // 单位
    DTO_FIELD(String, goods_unit);
    // 生产日期
    DTO_FIELD(String, goods_pro_data);
    // 批次
    DTO_FIELD(String, goods_batch);
    // 盘点数量
    DTO_FIELD(String, stt_qua);
    // 客户名称
    DTO_FIELD(String, cus_name);
    // 客户
    DTO_FIELD(String, cus_code);
    // 盘点状态
    DTO_FIELD(String, stt_sta);
    // 基本单位
    DTO_FIELD(String, base_unit);
    // 基本单位数量
    DTO_FIELD(String, base_goodscount);
    //stt_id
    DTO_FIELD(String, stt_id);
    // 商品统一编码
    DTO_FIELD(String, goods_code);
    // 盘点类型
    DTO_FIELD(String, stt_type);
    // 动线
    DTO_FIELD(String, dong_xian);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECK_QUERY_