package com.zeroone.star.project.dto.j7.adpick;
import com.alibaba.excel.annotation.ExcelIgnoreUnannotated;
import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
/**
 * 导出出库任务列表
 *
 * @author Lin
 * @since 2025/3/16
 */
@ApiModel("导出出库任务列表")
@Getter
@Setter
@ExcelIgnoreUnannotated
public class AdPickExportDTO {
    @ExcelProperty(value = "创建人名称", index = 0)
    private String createBy;
    @ExcelProperty(value = "商品编码", index = 1)
    private String goodsId;
    @ExcelProperty(value = "商品名称", index = 2)
    private String goodsName;
    @ExcelProperty(value = "数量", index = 3)
    private String goodsQua;
    @ExcelProperty(value = "完成数量", index = 4)
    private String goodsQuaok;
    @ExcelProperty(value = "原始单据编码", index = 5)
    private String orderId;
    @ExcelProperty(value = "原始单据行项目", index = 6)
    private String orderIdI;
    @ExcelProperty(value = "原始单据类型", index = 7)
    private String orderType;
    @ExcelProperty(value = "单位", index = 8)
    private String goodsUnit;
    @ExcelProperty(value = "生产日期", index = 9)
    private String goodsProData;
    @ExcelProperty(value = "作业类型", index = 10)
    private String actTypeCode;
    @ExcelProperty(value = "库位编码", index = 11)
    private String kuWeiBianMa;
    @ExcelProperty(value = "目标托盘", index = 12)
    private String binIdTo;
    @ExcelProperty(value = "源托盘码", index = 13)
    private String binIdFrom;
    @ExcelProperty(value = "货主", index = 14)
    private String cusCode;
    @ExcelProperty(value = "状态", index = 15)
    private String downSta;
    @ExcelProperty(value = "基本单位", index = 16)
    private String baseUnit;
    @ExcelProperty(value = "基本单位数量", index = 17)
    private String baseGoodscount;
    @ExcelProperty(value = "客户订单号", index = 18)
    private String imCusCode;
    @ExcelProperty(value = "备注", index = 19)
    private String omBeiZhu;
}