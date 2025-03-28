package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @BelongsProject: 10wms
 * @BelongsPackage: com.zeroone.star.project.j7.dto
 * @Author: ayuan
 * @CreateTime: 2025-02-22
 * @Description:
 */
@ApiModel("出货通知")
@Data
public class OutGoodsNoticeFormDTO {
    @ApiModelProperty("出货通知单号")
    private String id;
    @ApiModelProperty("货主")
    private String cueCode;
    @ApiModelProperty("要求交货时间")
    private String delvData;
    @ApiModelProperty("订单类型")
    private String orderTypeCode;
    @ApiModelProperty("客户订单号")
    private String imCusCode;
    @ApiModelProperty("客户")
    private String ocusName;
    @ApiModelProperty("收货人")
    private String delvMember;
    @ApiModelProperty("收货人电话")
    private String delvMobile;
    @ApiModelProperty("收货人地址")
    private String delvAddr;
    @ApiModelProperty("运输人")
    private String reMember;
    @ApiModelProperty("运单号 or 车号")
    private String reCarno;
    @ApiModelProperty("送货方式")
    private String delvMethod;
    @ApiModelProperty("发货月台")
    private String omPlatNo;
    @ApiModelProperty("备注")
    private String omBeizhu;
    @ApiModelProperty("仓库")
    private String storeCode;
    @ApiModelProperty("附件")
    private String fuJian;
    @ApiModelProperty("出货商品明细")
    private List<OutGoodsDetailDTO> outGoodsDetailDTOList;
}
