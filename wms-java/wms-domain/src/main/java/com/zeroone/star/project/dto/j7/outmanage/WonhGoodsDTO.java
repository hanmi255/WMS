package com.zeroone.star.project.dto.j7.outmanage;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Getter
@Setter
@EqualsAndHashCode
public class WonhGoodsDTO {
    //出货通知
    /**
     * 序号
     */
    @ExcelProperty(value = "序号", index = 0)
    private String id;
    /**
     * 出货商品
     */
    @ExcelProperty(value = "商品编码", index = 1)
    private String goodsId;
    /**
     * 出货商品名称
     */
    @ExcelProperty(value = "商品描述", index = 2)
    private String goodsName;

    /**
     * 出货数量
     */
    @ExcelProperty(value = "数量", index = 3)
    private String goodsQua;

    /**
     * 出货单位
     */
    @ExcelProperty(value = "单位", index = 4)
    private String goodsUnit;

    /**
     * 生产日期
     */
    @ExcelProperty(value = "生产日期", index = 5)
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDateTime goodsProData;

    /**
     * 实收数量
     */
    @ExcelProperty(value = "实收数量", index = 6)
    private String num;

    /**
     * 空
     */
    @ExcelProperty(value = " ", index = 7)
    private String kong;

    /**
     * 条码
     */
    @ExcelProperty(value = "条码", index = 8)
    private String barcode;

}
