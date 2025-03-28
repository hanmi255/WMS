package com.zeroone.star.project.query.j6.stockln;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：待验收货物查询对象
 *
 * @author Susu
 * @version 1.0.0
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("待验收货物查询对象")
public class ToAcceptQuery extends PageQuery {

    /**
     * 到货通知单
     */
    @ApiModelProperty(value = "到货通知单", example = "IMC123456789", required = true)
    private String imNoticeId;

    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号", example = "CUS000001", required = true)
    private String imCusCode;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "这是一个测试备注")
    private String imBeizhu;

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "G00001", required = true)
    private String goodsCode;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称", example = "测试商品", required = true)
    private String goodsName;

    // 如果需要，可以在这里添加更多的查询条件字段，例如：创建人名称、创建日期等。
}