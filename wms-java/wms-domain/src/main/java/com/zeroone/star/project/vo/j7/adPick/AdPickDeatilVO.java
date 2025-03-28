package com.zeroone.star.project.vo.j7.adPick;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * @Description:
 * @Author: PingShui
 * @Date: 2025/3/11 15:40
 */
@Data
public class AdPickDeatilVO implements Serializable {
    /**
     * 主键
     */
    @ApiModelProperty(value = "主键")
    private String id;
    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;
    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    /**
     * 数量
     */
    @ApiModelProperty(value = "数量")
    private String goodsQua;

    /**
     * 完成数量
     */
    @ApiModelProperty(value = "完成数量")
    private String goodsQuaok;
    /**
     * 单位
     */
    @ApiModelProperty(value = "单位")
    private String goodsUnit;

    /**
     * 基本单位数量
     */
    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;
    /**
     * 基本单位
     */
    @ApiModelProperty(value = "基本单位")
    private String baseUnit;
    /**
     * 原始单据编码
     */
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;
    /**
     * 原始单据类型
     */
    @ApiModelProperty(value = "原始单据类型")
    private String orderType;
    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生产日期")
    private String goodsProData;
    /**
     * 源托盘码
     */
    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;
    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;
    /**
     * 作业类型
     */
    @ApiModelProperty(value = "作业类型")
    private String actTypeCode;
    /**
     * 货主
     */
    @ApiModelProperty(value = "货主")
    private String cusCode;
    /**
     * 目标托盘
     */
    @ApiModelProperty(value = "目标托盘")
    private String binIdTo;
    /**
     * 状态
     */
    @ApiModelProperty(value = "状态")
    private String downSta;



}
