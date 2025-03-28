package com.zeroone.star.project.vo.j1.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：下架数量显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yunyu
 * @version 1.0.0
 */
@ApiModel("货物下架数量显示对象")
@Getter
@Setter
@ToString
public class GoodsToDownVO {

    @ApiModelProperty(value = "商品数量", example = "200")
    private String totalGoodsQua;

    @ApiModelProperty(value = "商品名称", example = "牛肉半成品")
    private String goodsName;

    @ApiModelProperty(value = "商品单位", example = "箱")
    private String goodsUnit;

}
