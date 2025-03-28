package com.zeroone.star.project.query.j6.stockln;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@ToString
@Getter
@Setter
@ApiModel("进货通知单查询对象")
public class ImportNoticeQuery extends PageQuery {

    @ApiModelProperty(value = "进货通知单号", example = "YK20241015-0001")
    private String noticeId;

    @ApiModelProperty(value = "客户编码", example = "21303")
    private String cusCode;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "预计到货时间在指定时间范围内的起始时间", example = "2024-10-12 11:25:00")
    private LocalDateTime imDataBegin;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "预计到货时间在指定时间范围内的结束时间", example = "2024-12-17 11:25:00")
    private LocalDateTime imDataEnd;

    @ApiModelProperty(value = "客户订单号", example = "0011")
    private String imCusCode;

    @ApiModelProperty(value = "供应商编码", example = "G001")
    private String supCode;

    @ApiModelProperty(value = "供应商名称", example = "大江大河有限公司")
    private String supName;

    @ApiModelProperty(value = "订单类型", example = "02")
    private String orderTypeCode;

    @ApiModelProperty(value = "单据状态", example = "计划中")
    private String imSta;

    @ApiModelProperty(value = "运输公司", example = "顺丰")
    private String imCarDri;

    @ApiModelProperty(value = "运输号码", example = "14435674566")
    private String imCarNo;
}
