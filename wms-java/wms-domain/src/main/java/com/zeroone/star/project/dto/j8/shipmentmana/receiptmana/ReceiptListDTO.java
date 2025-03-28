package com.zeroone.star.project.dto.j8.shipmentmana.receiptmana;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 回单列表数据传输对象
 */
@Getter
@Setter
@ToString
@ApiModel(value = "查询回单列表DTO")
public class ReceiptListDTO extends ReceiptBaseDTO{
    @ApiModelProperty(value = "主键",example = "2c9efaca91697e980192796e75d04d60")
    private String id;
    @ExcelProperty(value = "创建人名称",index = 1)
    @ApiModelProperty(value = "创建人名称",example = "管理员")
    private String createUser;
    @ExcelProperty(value = "创建日期",index = 2)
    @ApiModelProperty(value = "创建日期",example = "2024-10-11")
    private String createTime;
    @ExcelProperty(value = "货主",index = 3)
    @ApiModelProperty(value = "货主",example = "710500-可口可乐饮料")
    private String cargoOwner;
}
