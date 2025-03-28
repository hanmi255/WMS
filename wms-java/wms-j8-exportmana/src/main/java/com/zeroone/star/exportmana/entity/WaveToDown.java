package com.zeroone.star.exportmana.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * VIEW
 * </p>
 *
 * @author wuven
 * @since 2025-03-06
 */
@Getter
@Setter
@TableName("wave_to_down")
public class WaveToDown implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 创建人登录名称
     */
    private String createBy;

    /**
     * 创建人名称
     */
    private String createName;

    /**
     * 货主
     */
    private String cusCode;

    /**
     * 客户名称
     */
    private String cusName;

    private String waveId;

    /**
     * 商品编码
     */
    private String goodsId;

    /**
     * 商品名称
     */
    private String goodsName;

    private String imCusCode;

    /**
     * 仓位
     */
    private String binId;

    /**
     * 托盘
     */
    private String tinId;

    /**
     * 生产日期
     */
    private String proData;

    private Double baseGoodscount;

    private BigDecimal omBeiZhu;

    /**
     * 基本单位
     */
    private String baseUnit;

    private String firstRq;

    private String secondRq;

    private String by1;

    private String by2;

    private String by3;

    private String by4;

    private String by5;

    private String shpTiaoMa;


}
