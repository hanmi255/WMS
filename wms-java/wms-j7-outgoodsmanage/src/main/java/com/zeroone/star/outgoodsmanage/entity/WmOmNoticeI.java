package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 出库通知项
 * </p>
 *
 * @author 做了错饭
 * @since 2025-02-21
 */
@Getter
@Setter
@TableName("wm_om_notice_i")
public class WmOmNoticeI implements Serializable {

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
     * 出货通知ID
     */
    private String omNoticeId;

    /**
     * 出货商品
     */
    private String goodsId;

    /**
     * 出货数量
     */
    private String goodsQua;

    /**
     * 出货单位
     */
    private String goodsUnit;

    /**
     * 生产日期
     */
    private LocalDateTime goodsProData;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 出货仓位
     */
    private String binOm;

    /**
     * 已出货数量
     */
    private String goodsQuaok;

    /**
     * 预约出货时间
     */
    private String delvData;

    /**
     * 客户
     */
    private String cusCode;

    /**
     * 客户名称
     */
    private String cusName;

    /**
     * 商品名称
     */
    private String goodsText;

    /**
     * 波次号
     */
    private String waveId;

    /**
     * 状态
     */
    private String omSta;

    /**
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    /**
     * 下架计划生成
     */
    private String planSta;

    private String goodsName;

    private String otherId;

    private String binId;

    private String imCusCode;

    private String omBeiZhu;

    private String bzhiQi;

    private String chpShuXing;

    private String barcode;

    private String sku;

}
