package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 商品下架
 * </p>
 *
 * @author King
 * @since 2025-03-06
 */
@Getter
@Setter
@TableName("wm_to_down_goods")
public class WmToUnpublish implements Serializable {

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
     * 商品编码
     */
    private String goodsId;

    /**
     * 数量
     */
    private String goodsQua;

    /**
     * 完成数量
     */
    private String goodsQuaok;

    /**
     * 原始单据编码
     */
    private String orderId;

    /**
     * 原始单据行项目
     */
    private String orderIdI;

    /**
     * 原始单据类型
     */
    private String orderType;

    /**
     * 单位
     */
    private String goodsUnit;

    /**
     * 生产日期
     */
    private String goodsProData;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 作业类型
     */
    private String actTypeCode;

    /**
     * 库位编码
     */
    private String kuWeiBianMa;

    /**
     * 目标托盘
     */
    private String binIdTo;

    /**
     * 源托盘码
     */
    private String binIdFrom;

    /**
     * 货主
     */
    private String cusCode;

    /**
     * 状态
     */
    private String downSta;

    /**
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    private String goodsName;

    private String imCusCode;

    private String omBeiZhu;


}
