package com.zeroone.star.project.query.j7.outnotice;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
public class OutGoodNoticeQuery extends PageQuery{

    @ApiModelProperty(value = "状态")
    private String omSta;

    @ApiModelProperty(value = "打印状态")
    private String printStatus;

    @ApiModelProperty(value = "出货单号")
    private String omNoticeId;

    @ApiModelProperty(value = "货主编码")
    private String cusCode;

    @ApiModelProperty("客户订单号")
    private String imCusCode;

    @ApiModelProperty("三方客户名称")
    private String ocusName;

    @ApiModelProperty("三方客户编码")
    private String ocusCode;

    @ApiModelProperty("要求交货时间")
    private LocalDateTime delvData;

    @ApiModelProperty("收货人")
    private String delvMember;

    @ApiModelProperty("收货人电话")
    private String delvMobile;

    @ApiModelProperty("承运人")
    private String reMember;

    @ApiModelProperty("承运人车号")
    private String reCarno;
}
