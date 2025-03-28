package com.zeroone.star.project.query.j7.downgoods;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：出库任务下架查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author King
 * @since 2025-02-25
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("出库任务下架查询对象")
public class UnpublishQuery extends PageQuery {

    private static final long serialVersionUID = 1L;

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码")
    private String goodsId;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称")
    private String goodsName;

    /**
     * 原始单据编码
     */
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;

    /**
     * 原始单据行项目
     */
    @ApiModelProperty(value = "原始单据行项目")
    private String orderIdI;

    /**
     * 批次
     */
    @ApiModelProperty(value = "批次")
    private String goodsBatch;

    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;

    /**
     * 目标托盘
     */
    @ApiModelProperty(value = "目标托盘")
    private String binIdTo;

    /**
     * 源托盘码
     */
    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;

    /**
     * 货主
     */
    @ApiModelProperty(value = "货主")
    private String cusCode;

    /**
     * 状态
     */
    @ApiModelProperty(value = "状态")
    private String downSta;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
}