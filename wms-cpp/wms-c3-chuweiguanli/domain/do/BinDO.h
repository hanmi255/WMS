#pragma once
#ifndef _BINDO_
#define _BINDO_
#include "domain/GlobalInclude.h"

class BinDO {
    CC_SYNTHESIZE(string, id, Id); // 唯一标识 主键
    CC_SYNTHESIZE(string, create_name, CreateName); // 创建人名称
    CC_SYNTHESIZE(string, create_by, CreateBy); // 创建人登录名称
    CC_SYNTHESIZE(string, create_date, CreateDate); // 创建日期
    CC_SYNTHESIZE(string, update_name, UpdateName); // 更新人名称
    CC_SYNTHESIZE(string, update_by, UpdateBy); // 更新人登录名称
    CC_SYNTHESIZE(string, update_date, UpdateDate); // 更新日期
    CC_SYNTHESIZE(string, sys_org_code, SysOrgCode); // 所属部门
    CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode); // 所属公司
    CC_SYNTHESIZE(string, ku_wei_ming_cheng, KuWeiMingCheng); // 库位名称
    CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa); // 库位编码
    CC_SYNTHESIZE(string, ku_wei_tiao_ma, KuWeiTiaoMa); // 库位条码
    CC_SYNTHESIZE(string, ku_wei_lei_xing, KuWeiLeiXing); // 库位类型
    CC_SYNTHESIZE(string, ku_wei_shu_xing, KuWeiShuXing); // 库位属性
    CC_SYNTHESIZE(string, shang_jia_ci_xu, ShangJiaCiXu); // 上架次序
    CC_SYNTHESIZE(string, qu_huo_ci_xu, QuHuoCiXu); // 取货次序
    CC_SYNTHESIZE(string, suo_shu_ke_hu, SuoShuKeHu); // 所属客户
    CC_SYNTHESIZE(string, ti_ji_dan_wei, TiJiDanWei); // 体积单位
    CC_SYNTHESIZE(string, zhong_liang_dan_wei, ZhongLiangDanWei); // 重量单位
    CC_SYNTHESIZE(string, mian_ji_dan_wei, MianJiDanWei); // 面积单位
    CC_SYNTHESIZE(string, zui_da_ti_ji, ZuiDaTiJi); // 最大体积
    CC_SYNTHESIZE(string, zui_da_zhong_liang, ZuiDaZhongLiang); // 最大重量
    CC_SYNTHESIZE(string, zui_da_mian_ji, ZuiDaMianJi); // 最大面积
    CC_SYNTHESIZE(string, zui_da_tuo_pan, ZuiDaTuoPan); // 最大托盘
    CC_SYNTHESIZE(string, chang, Chang); // 长度
    CC_SYNTHESIZE(string, kuan, Kuan); // 宽度
    CC_SYNTHESIZE(string, gao, Gao); // 高度
    CC_SYNTHESIZE(string, ting_yong, TingYong); // 停用
    CC_SYNTHESIZE(string, ming_xi, MingXi); // 明细
    CC_SYNTHESIZE(string, bin_store, BinStore); // 仓库
    CC_SYNTHESIZE(string, CHP_SHU_XING, CHPShuXing); // 产品属性
    CC_SYNTHESIZE(string, ming_xi1, MingXi1); // 备注1
    CC_SYNTHESIZE(string, ming_xi2, MingXi2); // 备注2
    CC_SYNTHESIZE(string, ming_xi3, MingXi3); // 动线
    CC_SYNTHESIZE(string, LORA_bqid, LORABqid); // LORA标签ID
    CC_SYNTHESIZE(string, xnode, XNode); // X坐标
    CC_SYNTHESIZE(string, ynode, YNode); // Y坐标
    CC_SYNTHESIZE(string, znode, ZNode); // Z坐标


public:

    BinDO() :
        id(""), create_name(""), create_by(""), create_date(""), update_name(""), update_by(""), update_date(""),
        sys_org_code(""), sys_company_code(""), ku_wei_ming_cheng(""), ku_wei_bian_ma(""), ku_wei_tiao_ma(""),
        ku_wei_lei_xing(""), ku_wei_shu_xing(""), shang_jia_ci_xu(""), qu_huo_ci_xu(""), suo_shu_ke_hu(""),
        ti_ji_dan_wei(""), zhong_liang_dan_wei(""), mian_ji_dan_wei(""), zui_da_ti_ji(""), zui_da_zhong_liang(""),
        zui_da_mian_ji(""), zui_da_tuo_pan(""), chang(""), kuan(""), gao(""), ting_yong(""), ming_xi(""),
        bin_store(""), CHP_SHU_XING(""), ming_xi1(""), ming_xi2(""), ming_xi3(""), LORA_bqid(""), xnode(""), ynode(""), znode("") {
    }
};



#endif // !_BINDO_