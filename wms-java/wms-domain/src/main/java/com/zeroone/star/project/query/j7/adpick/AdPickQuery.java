package com.zeroone.star.project.query.j7.adpick;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
  *@author keyuan
  * @since 2025 3.16
 */
@Data
@ApiModel("按单拣货查询对象")
public class AdPickQuery {
    @ApiModelProperty(value = "创建时间")
    private Date createDate;
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    @ApiModelProperty(value = "客户订单号")
    private String customerOrderId;
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
    @ApiModelProperty(value = "数量")
    private String goodsQua;
    @ApiModelProperty(value = "复核数量")
    private String goodsQuaok;
    @ApiModelProperty(value = "基本单位")
    private String baseUnit;
    @ApiModelProperty(value = "单位")
    private double unit;
    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;
    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;
    @ApiModelProperty(value = "货主")
    private String cusCode;

}
