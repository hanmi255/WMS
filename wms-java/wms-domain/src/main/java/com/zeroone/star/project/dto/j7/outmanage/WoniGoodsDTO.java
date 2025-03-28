package com.zeroone.star.project.dto.j7.outmanage;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Getter
@Setter
@EqualsAndHashCode
public class WoniGoodsDTO {
    //出库
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
    @ExcelProperty(value = "商品名称", index = 2)
    private String shpMingCheng;
    /**
     * 生产日期
     */
    @ExcelProperty(value = "生产日期", index = 3)
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDateTime proData;
    /**
     * 品质
     */
    @ExcelProperty(value = "品质", index = 4)
    private String qua;

    /**
     * 箱数
     */
    @ExcelProperty(value = "箱数", index = 5)
    private String goodsQua;

    /**
     * 拆零数
     */
    @ExcelProperty(value = "拆零数", index = 6)
    private String chlShl;

    /**
     * 毛重
     */
    @ExcelProperty(value = "毛重/KG", index = 7)
    private String zhlKgm;

    /**
     * 库存
     */
    @ExcelProperty(value = "库存", index = 8)
    private String goodsNow;
    /**
     * 备注
     */
    @ExcelProperty(value = "备注", index = 9)
    private String beizhu;

}
