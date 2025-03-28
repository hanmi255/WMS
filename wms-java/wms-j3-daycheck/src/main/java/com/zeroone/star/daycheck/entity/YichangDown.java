package com.zeroone.star.daycheck.entity;


import com.alibaba.excel.annotation.ExcelProperty;
import com.zeroone.star.daycheck.config.LocalDateTimeExcel;
import io.swagger.annotations.ApiModelProperty;
import javafx.util.converter.LocalDateStringConverter;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/24 08:59
 */
@Data
public class YichangDown {
    @ApiModelProperty(value = "下架日期")//wm_to_down_goods
    @ExcelProperty(value = "下架日期", index = 0, converter = LocalDateTimeExcel.class)
    private LocalDateTime create_date;

    @ApiModelProperty(value = "下架人")//wm_to_down_goods
    @ExcelProperty(value = "下架人", index = 1)
    private String create_name;

    @ApiModelProperty(value = "复核人")//wm_to_down_goods
    @ExcelProperty(value = "复核人", index = 2)
    private String update_name;

    @ApiModelProperty(value = "储位")//wm_to_down_goods
    @ExcelProperty(value = "储位", index = 3)
    private String ku_wei_bian_ma;

    @ApiModelProperty(value = "下架托盘")//wm_to_down_goods
    @ExcelProperty(value = "下架托盘", index = 4)
    private String bin_id_from;

    @ApiModelProperty(value = "下架单号")//wm_to_down_goods
    @ExcelProperty(value = "下架单号", index = 5)
    private String bin_id_to;

    @ApiModelProperty(value = "客户id")//wm_to_down_goods
    @ExcelProperty(value = "客户id", index = 6)
    private String cus_code;

    @ApiModelProperty(value = "客户所属公司")//wm_to_down_goods里面的 查md_cus
    @ExcelProperty(value = "客户所属公司id", index = 7)
    private String sys_company_code;
    @ExcelProperty(value = "客户所属公司", index = 8)
    private String zhong_wen_qch;

    @ApiModelProperty(value = "商品编码")//wm_to_down_goods其中的goods_id和md_goods里面的商品编码shp_bian_ma一样
    @ExcelProperty(value = "商品编码", index = 9)
    private String goods_id;

    @ApiModelProperty(value = "商品名称")//md_goods---查出来了
    @ExcelProperty(value = "商品名称", index = 10)
    private String shp_ming_cheng;

    @ApiModelProperty(value = "生产日期")//wm_to_down_goods
    @ExcelProperty(value = "生产日期", index = 11)
    private String goods_pro_data;

    @ApiModelProperty(value = "单位")//wm_to_down_goods
    @ExcelProperty(value = "单位", index = 12)
    private String base_unit;

    @ApiModelProperty(value = "下架数量")//wm_to_down_goods
    @ExcelProperty(value = "下架数量", index = 13)
    private String goods_qua;

    @ApiModelProperty(value = "复核数量")//wm_to_down_goods
    @ExcelProperty(value = "复核数量", index = 14)
    private String goods_quaok;
}
