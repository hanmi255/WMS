package com.zeroone.star.project.vo.j8.shipmentmana.intransitstock;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @ClassName: InTransitStockVO
 * @Package: com.zeroone.star.project.vo.j8.shipmentmana.intransitstock
 * @Description:
 * @Author: zk
 * @Create: 2025/2/26 - 上午11:14
 */
@Data
@ApiModel("在途库存VO")
public class InTransitStockVO {
    @ApiModelProperty(value = "库存类型", example = "在途")
    private String kuctype;
    @ApiModelProperty(value = "出货订单",example = "3rt3ktl3jkt33")
    private String orderId;
    @ApiModelProperty(value = "出货日期", example = "2025-02-26")
    private String createDate;
    @ApiModelProperty(value = "客户编码",example = "KC")
    private String cusCode;
    @ApiModelProperty(value = "客户名称",example = "KC")
    private String zhongWenQch;
    @ApiModelProperty(value = "商品编码", example = "KC")
    private String goodsId;
    @ApiModelProperty(value = "商品名称",example = "KC")
    private String shpMingCheng;
    @ApiModelProperty(value = "出货数量", example = "1")
    private Integer goodsQuaok;
    @ApiModelProperty(value = "单位", example = "KC")
    private String shlDanWei;
    @ApiModelProperty(value = "生产日期", example = "2025-02-26")
    private String goodsProData;
    @ApiModelProperty(value = "出货储位", example = "1")
    private String kuWeiBianMa;
}
