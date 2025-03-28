package com.zeroone.star.j5.basezl.entity.provider;


import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

@Data
public class ProviderExcel {

        @ExcelProperty(value = "中文全称", index = 0)
        private String zhongWenQch;
        @ExcelProperty(value = "供应商编码", index = 1)
        private String gysBianMa;
        @ExcelProperty(value = "企业属性", index = 2)
        private String xingYeFenLei;
        @ExcelProperty(value = "地址", index = 3)
        private String diZhi;
        @ExcelProperty(value = "主联系人", index = 4)
        private String zhuLianXiRen;
        @ExcelProperty(value = "电话", index = 5)
        private String dianHua;
        @ExcelProperty(value = "手机",index = 6)
        private String shouJi;
        @ExcelProperty(value = "Email地址", index = 7)
        private String emaildiZhi;
        @ExcelProperty(value = "备注", index = 8)
        private String beiZhu;



}
