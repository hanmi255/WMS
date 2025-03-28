package com.zeroone.star.project.query.j3.daycheck.Arr;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/22 13:49
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("收货未上架")
public class NoUpGoodsQuery extends PageQuery {
    @ApiModelProperty(value = "储位")//wm_tuopan
    private String bin_id;

    @ApiModelProperty(value = "托盘")//wm_tuopan
    private String tin_id;

    @ApiModelProperty(value = "客户编码")//wm_in_qm_i
    private String cus_code;

    @ApiModelProperty(value = "客户名称")//md_cus!!!!
    private String zhong_wen_qch;

    @ApiModelProperty(value = "商品编码")//wm_in_qm_i其中的goods_id和md_goods里面的商品编码shp_bian_ma一样
    private String goods_id;

    @ApiModelProperty(value = "商品名称")//md_goods
    private String shp_ming_cheng;
}
