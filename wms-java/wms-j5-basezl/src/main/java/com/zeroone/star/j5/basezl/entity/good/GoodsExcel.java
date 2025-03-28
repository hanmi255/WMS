package com.zeroone.star.j5.basezl.entity.good;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

/**
 * EasyExcel商品类
 */
@Data
public class GoodsExcel {
    @ExcelProperty(value = "供应商编码",index = 0)
    private String sysCompanyCode;
    @ExcelProperty(value = "供应商名称",index = 1)
    private String productType;
    @ExcelProperty(value = "配送点",index = 2)
    private String peisongdian;
    @ExcelProperty(value = "商品名称",index = 3)
    private String shpMingCheng;
    @ExcelProperty(value = "英文名称",index = 4)
    private String ywMingCheng;
    @ExcelProperty(value = "日文名称",index = 5)
    private String rwMingCheng;
    @ExcelProperty(value = "商品编码",index = 6)
    private String shpBianMa;
    @ExcelProperty(value = "客户商品编码",index = 7)
    private String shpBianMakh;
    @ExcelProperty(value = "商品规格",index = 8)
    private String shpGuiGe;
    @ExcelProperty(value = "产品属性",index = 9)
    private String chpShuXing;
    @ExcelProperty(value = "产品大类",index = 10)
    private String categoryId;
    @ExcelProperty(value = "拆零控制",index = 11)
    private String chlKongZhi;
    @ExcelProperty(value = "码盘单层数量",index = 12)
    private String mpDanCeng;
    @ExcelProperty(value = "码盘层高",index = 13)
    private String mpCengGao;
    @ExcelProperty(value = "计费商品类",index = 14)
    private String jfShpLei;
    @ExcelProperty(value = "商品条码",index = 15)
    private String shpTiaoMa;
    @ExcelProperty(value = "品牌",index = 16)
    private String shpPinPai;
    @ExcelProperty(value = "保质期",index = 17)
    private String bzhiQi;
    @ExcelProperty(value = "单位",index = 18)
    private String shlDanWei;
    @ExcelProperty(value = "拆零单位",index = 19)
    private String jshDanWei;
    @ExcelProperty(value = "体积",index = 20)
    private String tiJiCm;
    @ExcelProperty(value = "重量",index = 21)
    private String zhlKg;
    @ExcelProperty(value = "允收天数",index = 22)
    private String acceptanceDays;
    @ExcelProperty(value = "拆零数量",index = 23)
    private String chlShl;
    @ExcelProperty(value = "价格",index = 24)
    private String price;
    @ExcelProperty(value = "长",index = 25)
    private String chDanPin;
    @ExcelProperty(value = "宽",index = 26)
    private String kuDanPin;
    @ExcelProperty(value = "高",index = 27)
    private String gaoDanPin;
    @ExcelProperty(value = "sku",index = 28)
    private String sku;
    @ExcelProperty(value = "类目编码",index = 29)
    private String categoryCode;
}
