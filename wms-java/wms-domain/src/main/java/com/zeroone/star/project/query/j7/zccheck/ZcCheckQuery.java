package com.zeroone.star.project.query.j7.zccheck;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

/**
 * <p>
 * 描述：装车复刻列表查询对象 and 查询条件对象
 * </p>
 *
 * @author keyuan
 * @since 2025/2/25 下午 8:16
 */
@Getter
@Setter
@ToString
@ApiModel("装车复刻列表查询对象")
public class ZcCheckQuery extends PageQuery {
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;
    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;
    @ApiModelProperty(value = "货主")
    private String cusCode;
    @ApiModelProperty(value = "目标托盘")
    private String binIdTo;
}
