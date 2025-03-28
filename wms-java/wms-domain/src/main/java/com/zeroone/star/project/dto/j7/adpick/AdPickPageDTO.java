package com.zeroone.star.project.dto.j7.adpick;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * @Description:
 * @Author: PingShui
 * @Date: 2025/3/10 22:09
 */
@Data
public class AdPickPageDTO extends PageDTO implements Serializable {
    /**
     * 主键
     */
    @ApiModelProperty(value = "主键", example = "123e4567-e89b-12d3-a456-426614174000",hidden = true)
    private String id;

    /**
     * 原始单据编码
     */
    @ApiModelProperty(value = "原始单据编码", example = "CK20240925-0002")
    private String orderId;


    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "0000")
    private String goodsId;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称", example = "可口可乐")
    private String goodsName;

    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号", example = "12313")
    private String imCusCode;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "定位备注")
    private String omBeiZhu;


    /**
     * 源托盘码
     */
    @ApiModelProperty(value = "源托盘码", example = "C7777")
    private String binIdFrom;


    /**
     * 货主
     */
    @ApiModelProperty(value = "货主", example = "10")
    private String cusCode;

    /**
     * 目标托盘
     */
    @ApiModelProperty(value = "目标托盘", example = "QT20240925-0001")
    private String binIdTo;

}
