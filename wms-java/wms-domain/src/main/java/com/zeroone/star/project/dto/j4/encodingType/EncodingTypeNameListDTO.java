package com.zeroone.star.project.dto.j4.encodingType;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author adi
 * #Description 获取编码类型名称列表DTO
 * #Date: 2025/2/24 08:13
 */
@ToString
@Getter
@Setter
@ApiModel("编码类型名称列表")
public class EncodingTypeNameListDTO {
    @ApiModelProperty(value = "编码类型名称",example = "编码类型名称")
    private String snroTypeName;
}
