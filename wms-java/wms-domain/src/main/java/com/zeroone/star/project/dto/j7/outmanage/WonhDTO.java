package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Data
public class WonhDTO {
    //出货通知
    /**
     * 客户/货主编号
     */
    @ApiModelProperty(value = "客户编号", example = "710500")
    private String cusCode;
    /**
     * 出货通知ID
     */
    @ApiModelProperty(value = "出货通知ID", example = "QT20241011-0001")
    private String omNoticeId;
    /**
     * 要求交货时间
     */
    @ApiModelProperty(value = "要求交货时间", example = "2025-02-23 10:11:11")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime delvData;
    /**
     * 订单类型
     */
    @ApiModelProperty(value = "订单类型", example = "出库通知")
    private String orderTypeCode;
    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号", example = "12313")
    private String imCusCode;
    /**
     * 三方客户
     */
    @ApiModelProperty(value = "三方客户", example = "11")
    private String ocusCode;
    /**
     * 三方客户名称
     */
    @ApiModelProperty(value = "客户名称", example = "11")
    private String ocusName;
    /**
     * 收货人
     */
    @ApiModelProperty(value = "收货人", example = "qwewq")
    private String delvMember;
    /**
     * 收货人电话
     */
    @ApiModelProperty(value = "收货人电话", example = "qweq")
    private String delvMobile;
    /**
     * 收货人地址
     */
    @ApiModelProperty(value = "收货人地址", example = "qweqeqwq")
    private String delvAddr;
    /**
     * 承运人
     */
    @ApiModelProperty(value = "运输人", example = "qwq")
    private String reMember;
    /**
     * 承运人车号
     */
    @ApiModelProperty(value = "运单号或车号", example = "11")
    private String reCarno;
    /**
     * 送货方式
     */
    @ApiModelProperty(value = "送货方式", example = "送达")
    private String delvMethod;
    /**
     * 发货月台
     */
    @ApiModelProperty(value = "发货月台", example = "11")
    private String omPlatNo;
    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "你好")
    private String omBeizhu;
    /**
     * 仓库
     */
    @ApiModelProperty(value = "仓库", example = "1")
    private String storeCode;
    /**
     * 附件
     */
    @ApiModelProperty(value = "附件", example = "1.txt")
    private String fuJian;
}
