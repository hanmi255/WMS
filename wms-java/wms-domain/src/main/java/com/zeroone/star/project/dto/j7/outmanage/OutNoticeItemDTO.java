package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.List;

/**
 * 出货通知详情对象
 * @author cuofan
 */

@Data
@ApiModel("出货通知详情对象")
public class OutNoticeItemDTO implements Serializable {
    @ApiModelProperty("货主")
    private String cusCode;
    @ApiModelProperty("要求交货时间")
    private LocalDateTime delvData;
    @ApiModelProperty("订单类型")
    private String orderTypeCode;
    @ApiModelProperty("客户订单号")
    private String imCusCode;
    @ApiModelProperty(value = "三方客户")
    private String ocusCode;
    @ApiModelProperty("三方客户名称")
    private String cusName;
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
    @ApiModelProperty("发货月台")
    private String omPlatNo;
    @ApiModelProperty("备注")
    private String omBeizhu;
    @ApiModelProperty("状态")
    private String omSta;
    @ApiModelProperty("仓库")
    private String scoreCode;
    @ApiModelProperty("附件")
    private String fuJian;
    @ApiModelProperty("出货商品明细")
    private List<OutGoodDetailDTO> outGoodDetailDTOList;
    @ApiModelProperty("运输订单明细")
    private List<TransportOrderDetailDTO> transportOrderDetailDTOList;

}
