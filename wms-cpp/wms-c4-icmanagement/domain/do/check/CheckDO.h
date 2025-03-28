#pragma once
#ifndef _CHECK_DO_
#define _CHECK_DO_
#include "../DoInclude.h"

/**
 * 盘点数据对象
 */
class CheckDO
{
    // ID
    CC_SYNTHESIZE(string, id, Id);
    // 创建人名称
    CC_SYNTHESIZE(string, create_name, Create_name);
    // 创建人登录名称
    CC_SYNTHESIZE(string, create_by, Create_by);
    // 创建日期
    CC_SYNTHESIZE(string, create_date, Create_date);
    // 更新人名称
    CC_SYNTHESIZE(string, update_name, Update_name);
    // 更新人登录名称
    CC_SYNTHESIZE(string, update_by, Update_by);
    // 更新日期
    CC_SYNTHESIZE(string, update_date, Update_date);
    // 所属部门
    CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
    // 所属公司
    CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
    // 储位
    CC_SYNTHESIZE(string, bin_id, Bin_id);
    // 托盘
    CC_SYNTHESIZE(string, tin_id, Tin_id);
    // 商品编码
    CC_SYNTHESIZE(string, goods_id, Goods_id);
    // 商品名称
    CC_SYNTHESIZE(string, goods_name, Goods_name);
    // 数量
    CC_SYNTHESIZE(string, goods_qua, Goods_qua);
    // 单位
    CC_SYNTHESIZE(string, goods_unit, Goods_unit);
    // 生产日期
    CC_SYNTHESIZE(string, goods_pro_data, Goods_pro_data);
    // 批次
    CC_SYNTHESIZE(string, goods_batch, Goods_batch);
    // 盘点数量
    CC_SYNTHESIZE(string, stt_qua, Stt_qua);
    // 客户名称
    CC_SYNTHESIZE(string, cus_name, Cus_name);
    // 客户
    CC_SYNTHESIZE(string, cus_code, Cus_code);
    // 盘点状态
    CC_SYNTHESIZE(string, stt_sta, Stt_sta);
    // 基本单位
    CC_SYNTHESIZE(string, base_unit, Base_unit);
    // 基本单位数量
    CC_SYNTHESIZE(string, base_goodscount, Base_goodscount);
    //stt_id
    CC_SYNTHESIZE(string, stt_id, Stt_id);
    // 商品统一编码
    CC_SYNTHESIZE(string, goods_code, Goods_code);
    // 盘点类型
    CC_SYNTHESIZE(string, stt_type, Stt_type);
    // 动线
    CC_SYNTHESIZE(string, dong_xian, Dong_xian);

public:
    CheckDO() {
        id = "";
        create_name = "";
        create_by = "";
        create_date = "";
        update_name = "";
        update_by = "";
        update_date = "";
        sys_org_code = "";
        sys_company_code = "";
        bin_id = "";
        tin_id = "";
        goods_id = "";
        goods_name = "";
        goods_qua = "";
        goods_unit = "";
        goods_pro_data = "";
        goods_batch = "";
        stt_qua = "";
        cus_name = "";
        cus_code = "";
        stt_sta = "";
        base_unit = "";
        base_goodscount = "";
        stt_id = "";
        dong_xian = "";
        goods_code = "";
        stt_type = "";
    }
};

// 共享指针类型定义
typedef std::shared_ptr<CheckDO> PtrCheckDO;
#endif // !_CHECK_DO_