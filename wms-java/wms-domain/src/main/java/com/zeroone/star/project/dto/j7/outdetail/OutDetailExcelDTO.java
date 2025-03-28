package com.zeroone.star.project.dto.j7.outdetail;


import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author chen
 * @since 2025/3/4 16:22
 */

@Data
public class OutDetailExcelDTO {
    @ExcelProperty(value = "订单id",index = 0)
    private String id;
    @ExcelProperty(value = "状态",index = 1)
    private String omSta;
    @ExcelProperty(value = "出库单号",index = 2)
    private String omNoticeId;
    @ExcelProperty(value = "第三方单号",index = 3)
    private String imCusCode;
    @ExcelProperty(value = "第三方客户",index = 4)
    private String cusCode;
    @ExcelProperty(value = "第三方客户名称",index = 5)
    private String ocusName;
    @ExcelProperty(value = "备注",index = 6)
    private String omBeizhu;
    @ExcelProperty(value = "地址",index = 7)
    private String delvAddr;
    @ExcelProperty(value = "商品编码",index = 8)
    private String goodsId;
    @ExcelProperty(value = "商品名称",index = 9)
    private String goodsName;
    @ExcelProperty(value = "出货单数量",index = 10)
    private String baseGoodscount;
    @ExcelProperty(value = "单位",index = 11)
    private String goodsUnit;
    @ExcelProperty(value = "拣货数量",index = 12)
    private String sumGoodscount;
}
