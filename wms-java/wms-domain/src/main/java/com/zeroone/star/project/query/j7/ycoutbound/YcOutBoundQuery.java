package com.zeroone.star.project.query.j7.ycoutbound;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

/**
 * <p>
 * 描述：异常出库通知明细列表的查询对象 and 查询条件对象
 * </p>
 *
 * @author keyuan
 * @since 2025/2/25 下午 8:51
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("异常出库通知明细列表查询对象")
public class YcOutBoundQuery extends PageQuery {
    @ApiModelProperty(value = "通知单号")
    private String omNoticeId;
    @ApiModelProperty(value = "第三方单号")
    private String imCusCode;
    @ApiModelProperty(value = "第三方客户")
    private String ocusCode;
    @ApiModelProperty(value = "第三方客户名称")
    private String ocusName;
    @ApiModelProperty(value = "备注")
    private String omBeizhu;
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
}
