package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("展示出货通知单列表对象")
public class OutNoticeListDTO {
    @ApiModelProperty(value = "状态")
    private String omSta;
    @ApiModelProperty(value = "打印状态")
    private String printStatus;
    @ApiModelProperty(value = "制单人")
    private String createName;
    @ApiModelProperty(value = "拣货人")
    private String jhUser;
    @ApiModelProperty(value = "复核人")
    private String fhUser;
    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;
    @ApiModelProperty(value = "出货单号")
    private String omNoticeId;
    @ApiModelProperty(value = "货主编码")
    private String cusCode;
    @ApiModelProperty("客户订单号")
    private String imCusCode;
    @ApiModelProperty("备注")
    private String omBeizhu;
    @ApiModelProperty("三方客户编码")
    private String ocusCode;
    @ApiModelProperty("三方客户名称")
    private String ocusName;
    @ApiModelProperty("要求交货时间")
    private LocalDateTime delvData;
    @ApiModelProperty("收货人")
    private String delvMember;
    @ApiModelProperty("收货人电话")
    private String delvMobile;
    @ApiModelProperty("收货人地址")
    private String delvAddr;
    @ApiModelProperty("承运人")
    private String reMember;
    @ApiModelProperty("承运人车号")
    private String reCarno;
}
