package com.zeroone.star.project.query.j7.outbound;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：出库通知项查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author lenyan
 * @since 2025-02-21
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("出库通知项查询对象")
public class WmOmNoticeIQuery extends PageQuery {

    private static final long serialVersionUID = 1L;

    /**
     * 出库单号
     */
    @ApiModelProperty(value = "出库单号")
    private String omNoticeId;

    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号")
    private String cusOrderId;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称")
    private String goodsText;

    /**
     * SKU
     */
    @ApiModelProperty(value = "SKU")
    private String sku;

    /**
     * 托盘
     */
    @ApiModelProperty(value = "托盘")
    private String binId;
}
