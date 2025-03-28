package com.zeroone.star.project.dto.j5.basezl.goods;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：商品基础DTO
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:31
 */
@Setter
@Getter
@ToString
@ApiModel("商品基础DTO")
public class GoodsBaseDTO {
    @ApiModelProperty(value = "所属货主", example = "X00001-XXXX-KH有限公司")
    private String sysCompanyCode;
    @ApiModelProperty(value = "产品大类", example = "恒温")
    private String categoryId;
    @ApiModelProperty(value = "产品属性", example = "日用")
    private String chpShuXing;
    @ApiModelProperty(value = "价格", example = "11")
    private String price;
    @ApiModelProperty(value = "商品编码", example = "20222")
    private String shpBianMa;
    @ApiModelProperty(value = "商品名称", example = "蔗糖")
    private String shpMingCheng;
    @ApiModelProperty(value = "单位", example = "斤")
    private String shlDanWei;
}
