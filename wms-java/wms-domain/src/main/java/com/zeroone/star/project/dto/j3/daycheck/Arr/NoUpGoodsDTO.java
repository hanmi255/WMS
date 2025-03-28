package com.zeroone.star.project.dto.j3.daycheck.Arr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


/**
 * @author aaa
 * @version 1.0
 * @description 收货未上架-返回数据
 * @date 2025/2/22 11:40
 */
@Data
@ApiModel("收货未上架-返回数据")//下面的数据和业务参考项目返回数据 看是否存在在wm_tuopan上 wm_in_qm_i验收记录
public class NoUpGoodsDTO {
    @ApiModelProperty(value = "库存状态")
    private String kucunsta;

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

    @ApiModelProperty(value = "数量")//wm_in_qm_i
    private String qm_ok_quat;

    @ApiModelProperty(value = "商品单位")//md_goods
    private String shl_dan_wei;

    @ApiModelProperty(value = "生产日期")//wm_in_qm_i
    private String pro_data;

    @ApiModelProperty(value = "收货日期")//wm_in_qm_i
    private LocalDateTime create_date;

    @ApiModelProperty(value = "保质期")//md_goods
    private String bzhi_qi;
}
