package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("入库通知单明细展示对象")
public class InNoticeVO {

    @ApiModelProperty(value = "通知单号", example = "RK20250226-0003")
    private String imNoticeId;  // 对应DTO的 imNoticeId (到货通知单号)

    @ApiModelProperty(value = "客户编码", example = "X00001")
    private String cusCode;  // cus_code -> cusCode

    @ApiModelProperty(value = "公司名称", example = "YYY-有限公司")
    private String cusName;  // cus_name -> cusName*

    @ApiModelProperty(value = "通知单状态", example = "待处理")
    private String noticeiSta;  // 对应DTO的 noticeiSta (行项目状态)

    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String goodsCode;  // 对应DTO的 goodsCode (商品编码)

    @ApiModelProperty(value = "商品名称", example = "小蓝管")
    private String goodsName;  // 对应DTO的 goodsName (货物名称)

    @ApiModelProperty(value = "通知单数量", example = "36")
    private Integer goodsCount;  // 对应DTO的 goodsCount (通知单数量)

    @ApiModelProperty(value = "验收数量", example = "36.0")
    private Integer goodsQmCount;  // 对应DTO的 goodsQmCount (收货登记数量)

    @ApiModelProperty(value = "单位", example = "箱")
    private String goodsUnit;  // 对应DTO的 goodsUnit (单位)

    @ApiModelProperty(value = "体积", example = "4500000.0")
    private Double goodsFvol;  // 对应DTO的 goodsFvol (体积)

    @ApiModelProperty(value = "重量", example = "1800.0")
    private Double goodsWeight;  // 对应DTO的 goodsWeight (重量)

    @ApiModelProperty(value = "客户订单号", example = "X00001")
    private String imCusCode;  // im_cus_code -> imCusCode

    @ApiModelProperty(value = "基本单位数量", example = "36.0")
    private Double baseGoodscount;  // 对应DTO的 baseGoodscount (基本单位数量)

    @ApiModelProperty(value = "基本单位", example = "箱")
    private String baseUnit;  // 对应DTO的 baseUnit (基本单位)

    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String goodsPrdData;  // 对应DTO的 goodsPrdData (生产日期)
}
