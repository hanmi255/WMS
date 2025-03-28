package com.zeroone.star.project.dto.j5.basezl.goods;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：商品添加DTO
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:32
 */
@Setter
@Getter
@ToString
@ApiModel("商品添加DTO")
public class GoodsAddDTO extends GoodsListDTO{
    @ApiModelProperty(value = "商品品牌", example = "可口可乐")
    private String shpPinPai;
    @ApiModelProperty(value = "SKU", example = "件")
    private String sku;
    @ApiModelProperty(value = "长", example = "10")
    private String chDanPin;
    @ApiModelProperty(value = "宽", example = "10")
    private String kuDanPin;
    @ApiModelProperty(value = "高", example = "10")
    private String gaoDanPin;
    @ApiModelProperty(value = "最小库存量", example = "1")
    private String minStock;
}
