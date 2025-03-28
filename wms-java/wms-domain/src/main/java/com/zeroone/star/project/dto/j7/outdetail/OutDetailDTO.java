package com.zeroone.star.project.dto.j7.outdetail;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：出库明细数据输出对象
 * </p>
 *
 * @author chen
 * @since 2025/2/22 12:42
 */

@Getter
@Setter
@ToString
@ApiModel("出库明细数据显示对象")
public class OutDetailDTO {
    @ApiModelProperty(value = "订单id")
    private String id;
    @ApiModelProperty(value = "状态",example = "复核完成")
    private String omSta;
    @ApiModelProperty(value = "出库单号",example = "QT20240325-0001")
    private String omNoticeId;
    @ApiModelProperty(value = "第三方单号",example = "12313")
    private String imCusCode;
    @ApiModelProperty(value = "第三方客户",example = "null")
    private String cusCode;
    @ApiModelProperty(value = "第三方客户名称",example = "可口可乐")
    private String ocusName;
    @ApiModelProperty(value = "备注",example = "备注")
    private String omBeizhu;
    @ApiModelProperty(value = "地址",example = "收获地址")
    private String delvAddr;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    private String goodsId;
    @ApiModelProperty(value = "商品名称",example = "RL001-牛羊肉半成品-箱")
    private String goodsName;
    @ApiModelProperty(value = "出货单数量",example = "100")
    private String baseGoodscount;
    @ApiModelProperty(value = "单位",example = "箱")
    private String goodsUnit;
    @ApiModelProperty(value = "拣货数量",example = "100.0")
    private String sumGoodscount;
}
