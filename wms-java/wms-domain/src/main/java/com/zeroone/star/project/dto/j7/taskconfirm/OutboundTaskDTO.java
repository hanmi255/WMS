package com.zeroone.star.project.dto.j7.taskconfirm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：获取出库任务列表DTO
 * </p>
 *
 * @author keyuan
 * @since 2025/2/28
 */
@ApiModel("出库任务列表")
@Data
public class OutboundTaskDTO {
    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;
    @ApiModelProperty(value = "更新人名称")
    private String updateName;
    @ApiModelProperty(value = "更新日期")
    private LocalDateTime updateDate;
    @ApiModelProperty(value = "出货通知单")
    private String omNoticeId;
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;
    @ApiModelProperty(value = "第一个备注")
    private String omBeiZhu;
    @ApiModelProperty(value = "数量")
    private String qmOkQuat;
    @ApiModelProperty(value = "单位")
    private String goodsUnit;
    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;
    @ApiModelProperty(value = "基本单位")
    private String baseUnit;
    @ApiModelProperty(value = "第二个备注")
    private String itemText;
    @ApiModelProperty(value = "生产日期")
    private String proData;
    @ApiModelProperty(value = "托盘")
    private String tinId;
    @ApiModelProperty(value = "仓位")
    private String binId;
    @ApiModelProperty(value = "下架状态")
    private String binSta;
    @ApiModelProperty(value = "货主")
    private String cusCode;
    @ApiModelProperty(value = "任务接收人")
    private String assignTo;
    @ApiModelProperty(value = "波次")
    private String waveId;
}
