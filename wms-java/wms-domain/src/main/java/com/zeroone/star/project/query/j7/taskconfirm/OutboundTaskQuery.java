package com.zeroone.star.project.query.j7.taskconfirm;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import java.util.Date;

/**
 * <p>
 * 描述：出库任务列表查询对象 and 查询条件对象
 * </p>
 *
 * @author keyuan
 * @since 2025/2/25 7:47
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("出库任务列表查询对象")
public class OutboundTaskQuery extends PageQuery {
    @ApiModelProperty(value = "出货通知单")
    private String omNoticeId;
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
    @ApiModelProperty(value = "托盘")
    private String tinId;
    @ApiModelProperty(value = "仓位")
    private String binId;
    @ApiModelProperty(value = "货主")
    private String cusCode;
    @ApiModelProperty(value = "任务接收人")
    private String assignTo;
    @ApiModelProperty(value = "波次")
    private String waveId;
}
