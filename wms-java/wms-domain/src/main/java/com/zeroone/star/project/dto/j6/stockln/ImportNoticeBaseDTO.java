package com.zeroone.star.project.dto.j6.stockln;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

@ToString
@Getter
@Setter
@ApiModel("进货通知继承数据对象")
public class ImportNoticeBaseDTO {

    @ApiModelProperty(value = "客户编码", example = "001")
    private String cusCode;

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "预计到货时间 ", example = "2024-10-12 11:25:00")
    private LocalDateTime imData;

    @ApiModelProperty(value = "客户订单号", example = "0011")
    private String imCusCode;

    @ApiModelProperty(value = "运输号码", example = "TT666666")
    private String imCarNo;

    @ApiModelProperty(value = "运输公司", example = "顺丰")
    private String imCarDri;

    @ApiModelProperty(value = "供应商编码", example = "G001")
    private String supCode;

    @ApiModelProperty(value = "供应商名称", example = "XXXX-GYS有限公司")
    private String supName;

    @ApiModelProperty(value = "订单类型", example = "09")
    private String orderTypeCode;

    @ApiModelProperty(value = "备注", example = "...")
    private String imBeiZhu;


}
