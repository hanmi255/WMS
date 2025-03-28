package com.zeroone.star.project.dto.j4.encodingType;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotEmpty;

/**
 * @author lostAngel
 * @title EncodingType
 * @date 2025/2/21 21:40
 * @description 编码类型dto
 */
@Getter
@Setter
@ToString
@ApiModel("编码类型列表继承数据模型，编码类型列表修改数据对象，编码类型列表录入数据对象")
public class EncodingTypeBaseDTO {

    @NotEmpty(message = "对象不能为空")
    @ApiModelProperty(value = "编码类型代码", example = "编码类型代码")
    private String snroTypeCode;

    @NotEmpty(message = "对象不能为空")
    @ApiModelProperty(value = "编码类型名称", example = "编码类型名称")
    private String snroTypeName;
}
