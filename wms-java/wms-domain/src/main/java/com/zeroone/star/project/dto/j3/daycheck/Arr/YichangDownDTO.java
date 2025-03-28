package com.zeroone.star.project.dto.j3.daycheck.Arr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/22 12:38
 */
@Data
@ApiModel("出货异常")//wm_to_down_goods商品下架  wm_om_qm_i出库任务  md_goods
public class YichangDownDTO {
    @ApiModelProperty(value = "下架日期")//wm_to_down_goods
    private LocalDateTime create_date;

    @ApiModelProperty(value = "下架人")//wm_to_down_goods
    private String create_name;

    @ApiModelProperty(value = "复核人")//wm_to_down_goods
    private String update_name;

    @ApiModelProperty(value = "储位")//wm_to_down_goods
    private String ku_wei_bian_ma;

    @ApiModelProperty(value = "下架托盘")//wm_om_qm_i
    private String bin_id;

    @ApiModelProperty(value = "下架单号")//wm_to_down_goods
    private String bin_id_to;

    @ApiModelProperty(value = "客户id")//wm_to_down_goods
    private String cus_code;

    @ApiModelProperty(value = "客户名称")//md_cus
    private String zhong_wen_qch;

    @ApiModelProperty(value = "商品编码")//wm_to_down_goods其中的goods_id和md_goods里面的商品编码shp_bian_ma一样
    private String goods_id;

    @ApiModelProperty(value = "商品名称")//md_goods
    private String shp_ming_cheng;

    @ApiModelProperty(value = "生产日期")//wm_to_down_goods
    private String goods_pro_data;

    @ApiModelProperty(value = "单位")//md_goods
    private String base_unit;

    @ApiModelProperty(value = "下架数量")//wm_to_down_goods
    private String goods_qua;

    @ApiModelProperty(value = "复核数量")//wm_to_down_goods
    private String goods_quaok;
}