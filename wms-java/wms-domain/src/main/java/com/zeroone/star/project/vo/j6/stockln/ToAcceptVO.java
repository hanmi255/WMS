package com.zeroone.star.project.vo.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：待验收货物展示对象
 *
 * @author Susu
 * @version 1.0.0
 */
@Data
@ApiModel("待验收货物展示对象")
public class ToAcceptVO {
    /**
     * 创建人名称
     */
    @ApiModelProperty(value = "创建人名称", example = "张三", required = true)
    private String createName;

    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期", example = "2024-01-01 12:00:00", required = true)
    private LocalDateTime createDate;

    /**
     * 到货通知单
     */
    @ApiModelProperty(value = "到货通知单", example = "IMC123456789", required = true)
    private String imNoticeId;

    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号", example = "CUS000001", required = true)
    private String imCusCode;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "这是一个测试备注")
    private String imBeizhu;

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "G00001", required = true)
    private String goodsCode;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称", example = "测试商品", required = true)
    private String goodsName;

    /**
     * 预约数量
     */
    @ApiModelProperty(value = "预约数量", example = "100", required = true)
    private Integer goodsCount;

    /**
     * 已登记数量
     */
    @ApiModelProperty(value = "已登记数量", example = "50", required = true)
    private Integer goodsQmCount;

    /**
     * 未收货数量
     */
    @ApiModelProperty(value = "未收货数量", example = "50", required = true)
    private Integer goodsWqmCount;

    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生产日期", example = "2024-01-01", required = true)
    private String goodsPrdData;

    /**
     * 批次
     */
    @ApiModelProperty(value = "批次", example = "BATCH001", required = true)
    private String goodsBatch;

    /**
     * 储位
     */
    @ApiModelProperty(value = "储位", example = "BIN001", required = true)
    private String binPlan;

    /**
     * 托盘
     */
    @ApiModelProperty(value = "托盘", example = "TIN001", required = true)
    private String tinId;

    /**
     * 单位
     */
    @ApiModelProperty(value = "单位", example = "箱", required = true)
    private String goodsUnit;
}