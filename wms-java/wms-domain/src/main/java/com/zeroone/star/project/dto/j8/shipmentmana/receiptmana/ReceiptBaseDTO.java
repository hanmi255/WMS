package com.zeroone.star.project.dto.j8.shipmentmana.receiptmana;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * 回单基础数据传输对象
 */
@Getter
@Setter
@ToString
@ApiModel(value = "回单基础DTO")
public class ReceiptBaseDTO{
    @NotBlank(message = "订单编号不能为空")
    @ExcelProperty(value = "订单编号",index = 4)
    @ApiModelProperty(value = "订单编号",example = "CK20241011-0002")
    private String receiptId;

    @NotBlank(message = "订单时间不能为空")
    @ExcelProperty(value = "订单编号",index = 5)
    @ApiModelProperty(value = "订单时间",example = "2024-10-11T10:35:23")
    private String hdTime;

    @ExcelProperty(value = "订单备注",index = 6)
    @ApiModelProperty(value = "订单备注",example = "完成")
    private String comment;
}
