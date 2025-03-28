package com.zeroone.star.project.dto.j7.adpick;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;
import java.util.Date;

@Getter
@Setter
public class OutDetailExcelDTO {

    @ExcelProperty("主键")
    private String id;

    @ExcelProperty("原始单据编码")
    private String originalDocumentCode;

    @ExcelProperty("原始单据类型")
    private String orderIdType;

    @ExcelProperty("商品编码")
    private String productCode;

    @ExcelProperty("备注")
    private String remark;

    @ExcelProperty("数量")
    private Integer quantity;

    @ExcelProperty("复核数量")
    private Integer verifiedQuantity;

    @ExcelProperty("基本单位")
    private Double basicUnit;

    @ExcelProperty("单位")
    private Double unit;

    @ExcelProperty("源托盘码")
    private String sourcePalletCode;

    @ExcelProperty("目标托盘")
    private String aimTuoPan;

    @ExcelProperty("库位编码")
    private String storageLocationCode;

    @ExcelProperty("货主")
    private String cargoOwner;

    @ExcelProperty("生产日期")
    private LocalDateTime productTime;

    @ExcelProperty("创建日期")
    private Date createTime;

    @ExcelProperty("状态")
    private String status;

    @ExcelProperty("作业类型")
    private String workType;
}