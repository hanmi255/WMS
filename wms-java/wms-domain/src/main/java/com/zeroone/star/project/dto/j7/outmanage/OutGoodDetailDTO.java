package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import java.io.Serializable;

/**
 * 出货商品明细
 */
@Data
@ApiModel("出货商品明细")
public class OutGoodDetailDTO implements Serializable
{
    @ApiModelProperty("出货商品")
    private String goodsName;
    @ApiModelProperty("出货数量")
    private String baseGoodscount;
    @ApiModelProperty(value = "下架任务是否已经生成？")
    private String planSta;
    @ApiModelProperty("sku")
    private String sku;
}

