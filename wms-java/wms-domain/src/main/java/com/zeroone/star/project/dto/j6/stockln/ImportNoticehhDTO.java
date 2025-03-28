package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * han
 * 分页条件查询通知单DTO
 */
@Data
@ApiModel("传输数据对象")
public class ImportNoticehhDTO {

    @ApiModelProperty(value = "每页条数", example = "10")
    private Integer pageSize;

    @ApiModelProperty(value = "页码", example = "1")
    private Integer pageCode;

    @ApiModelProperty(value = "起始时间", example = "2019-10-01T12:00:00.000")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "终止时间", example = "2019-10-01T12:00:00.000")
    private LocalDateTime endTime;

    @ApiModelProperty(value = "客户订单号", example = "123456")
    private String custumerOrderCode;

    @ApiModelProperty(value = "车号", example = "123456")
    private String carCode;

    @ApiModelProperty(value = "司机", example = "123456")
    private String driverName;

    @ApiModelProperty(value = "司机电话", example = "123456")
    private String driverPhoneNumber;

    @ApiModelProperty(value = "订单类型", example = "1")
    private String orderType;

    @ApiModelProperty(value = "月台", example = "123456")
    private String yuetai;

    @ApiModelProperty(value = "单据状态", example = "1")
    private String OrderStatus;

    @ApiModelProperty(value = "通知单号", example = "123456")
    private String NoticeCode;

    @ApiModelProperty(value = "货主", example = "123456")
    private String company;

    @ApiModelProperty(value = "运输号码", example = "123456")
    private String yshm;

    @ApiModelProperty(value = "运输公司", example = "xxx")
    private String ysgs;

    @ApiModelProperty(value = "供应商编号", example = "123456")
    private String supposerCode;

    @ApiModelProperty(value = "供应商名称", example = "xxx")
    private String supposerName;
}
