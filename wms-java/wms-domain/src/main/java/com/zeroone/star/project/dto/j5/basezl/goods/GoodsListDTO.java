package com.zeroone.star.project.dto.j5.basezl.goods;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：商品列表展示DTO
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:30
 */
@Setter
@Getter
@ToString
@ApiModel("商品列表展示DTO")
public class GoodsListDTO extends GoodsBaseDTO{
    @ApiModelProperty(value = "英文名称", example = "sucrose")
    private String ywMingCheng;
    @ApiModelProperty(value = "日文名称", example = "スクロース")
    private String rwMingCheng;
    @ApiModelProperty(value = "客户商品编码", example = "123456789")
    private String shpBianMakh;
    @ApiModelProperty(value = "商品规格", example = "支")
    private String shpGuiGe;
    @ApiModelProperty(value = "商品类目", example = "2")
    private String categoryCode;
    @ApiModelProperty(value = "拆零控制", example = "否")
    private String chlKongZhi;
    @ApiModelProperty(value = "码盘单层数", example = "5")
    private String mpDanCeng;
    @ApiModelProperty(value = "码盘层高", example = "6")
    private String mpCengGao;
    @ApiModelProperty(value = "计费商品类", example = "计费吨")
    private String jfShpLei;
    @ApiModelProperty(value = "商品条码", example = "AD001")
    private String shpTiaoMa;
    @ApiModelProperty(value = "保质期", example = "360")
    private String bzhiQi;
    @ApiModelProperty(value = "允收天数", example = "240")
    private String acceptanceDays;
    @ApiModelProperty(value = "拆零单位", example = "箱")
    private String jshDanWei;
    @ApiModelProperty(value = "体积", example = "125000")
    private String tiJiCm;
    @ApiModelProperty(value = "重量", example = "50")
    private String zhlKg;
    @ApiModelProperty(value = "拆零数量", example = "50")
    private String chlShl;
}
