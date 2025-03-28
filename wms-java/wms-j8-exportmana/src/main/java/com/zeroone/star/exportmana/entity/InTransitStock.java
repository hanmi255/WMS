package com.zeroone.star.exportmana.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @ClassName: InTransitStock
 * @Package: com.zeroone.star.intransitstock.entity
 * @Description: 在途库存
 * @Author: zk
 * @Create: 2025/2/28 - 下午12:36
 */
@Data
@ApiModel(value = "在途库存")
public class InTransitStock {
    @ApiModelProperty(value = "库存类型", example = "在途")
    @ExcelProperty(value = "库存类型", index = 0)
    private String kuctype;
    @ExcelProperty(value = "出货订单", index = 1)
    @ApiModelProperty(value = "出货订单",example = "3rt3ktl3jkt33")
    private String orderId;
    @ExcelProperty(value = "出货日期", index = 2)
    @ApiModelProperty(value = "出货日期", example = "2025-02-26")
    private String createDate;
    @ExcelProperty(value = "客户编码", index = 3)
    @ApiModelProperty(value = "客户编码",example = "KC")
    private String cusCode;
    @ExcelProperty(value = "客户名称", index = 4)
    @ApiModelProperty(value = "客户名称",example = "KC")
    private String zhongWenQch;
    @ExcelProperty(value = "商品编码", index = 5)
    @ApiModelProperty(value = "商品编码", example = "KC")
    private String goodsId;
    @ExcelProperty(value = "商品名称", index = 6)
    @ApiModelProperty(value = "商品名称",example = "KC")
    private String shpMingCheng;
    @ExcelProperty(value = "出货数量", index = 7)
    @ApiModelProperty(value = "出货数量", example = "1")
    private Integer goodsQuaok;
    @ExcelProperty(value = "单位", index = 8)
    @ApiModelProperty(value = "单位", example = "KC")
    private String shlDanWei;
    @ExcelProperty(value = "出货日期", index = 9)
    @ApiModelProperty(value = "生产日期", example = "2025-02-26")
    private String goodsProData;
    @ApiModelProperty(value = "出货储位", example = "1")
    @ExcelProperty(value = "出货储位", index = 10)
    private String kuWeiBianMa;
}
