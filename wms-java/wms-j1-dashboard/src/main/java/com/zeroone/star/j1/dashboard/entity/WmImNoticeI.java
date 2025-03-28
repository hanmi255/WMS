package com.zeroone.star.j1.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 预约进货行项目表
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
@Getter
@Setter
@TableName("wm_im_notice_i")
public class WmImNoticeI implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 创建人名称
     */
    private String createName;

    /**
     * 创建人登录名称
     */
    private String createBy;

    /**
     * 创建日期
     */
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    private String updateName;

    /**
     * 更新人登录名称
     */
    private String updateBy;

    /**
     * 更新日期
     */
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    private String sysOrgCode;

    /**
     * 所属公司
     */
    private String sysCompanyCode;

    /**
     * 到货通知单号
     */
    private String imNoticeId;

    /**
     * 到货通知项目
     */
    private String imNoticeItem;

    /**
     * 商品编码
     */
    private String goodsCode;

    /**
     * 数量
     */
    private String goodsCount;

    /**
     * 生产日期
     */
    private LocalDateTime goodsPrdData;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 库位整理(N-待收货)
     */
    private String binPre;

    /**
     * 体积
     */
    private String goodsFvol;

    /**
     * 重量
     */
    private String goodsWeight;

    /**
     * 计划库位
     */
    private String binPlan;

    /**
     * 单位
     */
    private String goodsUnit;

    /**
     * 未清数量
     */
    private String goodsWqmCount;

    /**
     * 收货登记数量
     */
    private String goodsQmCount;

    /**
     * 行项目状态
     */
    private String noticeiSta;

    /**
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    /**
     * 基本单位收货数量
     */
    private String baseQmcount;

    private String goodsName;

    private String otherId;

    private String imCusCode;

    private String imBeizhu;

    private String barcode;

    /**
     * 规格
     */
    private String shpGuiGe;

    private String bzhiQi;

    /**
     * 产品属性
     */
    private String chpShuXing;

    private String tinId;


}
