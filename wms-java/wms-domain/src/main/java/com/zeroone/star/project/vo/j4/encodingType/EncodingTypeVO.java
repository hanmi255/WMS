package com.zeroone.star.project.vo.j4.encodingType;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author qiaozhi
 * @title EncodingType
 * @date 2025/2/21 21:40
 * @description 编码类型vo
 */
@Data
@ApiModel(value = "编码类型Vo")
public class EncodingTypeVO {
    @ApiModelProperty(value = "编码类型代码",example = "11")
    @ExcelProperty(value = "编码类型代码")
    private String snroTypeCode;
    @ApiModelProperty(value = "编码类型名称",example = "编码类型名称")
    @ExcelProperty(value = "编码类型名称")
    private String snroTypeName;
}
