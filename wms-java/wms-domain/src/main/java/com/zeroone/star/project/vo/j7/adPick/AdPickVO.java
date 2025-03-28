package com.zeroone.star.project.vo.j7.adPick;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * @Description:
 * @Author: PingShui
 * @Date: 2025/3/11 8:52
 */
@Data
public class AdPickVO implements Serializable {
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
     * 原始单据编码
     */
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;
    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;
    /**
     * 备注
     */
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
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
     * 基本单位数量
     */
    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;
    /**
     * 基本单位  箱
     */
    @ApiModelProperty(value = "基本单位  箱")
    private String baseUnit;
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
     * 货主id
     */
    @ApiModelProperty(value = "货主id")
    private String cusCode;
    /**
     * 货主姓名
     */
    @ApiModelProperty(value = "货主姓名")
    private String cusName;;

}
