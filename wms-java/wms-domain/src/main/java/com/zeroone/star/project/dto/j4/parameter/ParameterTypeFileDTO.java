package com.zeroone.star.project.dto.j4.parameter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author qiaozhi
 * @title ParameterType
 * @date 2025/2/21 21:37
 * @description 参数类型dto
 */
@Getter
@Setter
@ToString
@ApiModel(value = "系统参数类型导出/导入DTO对象")
public class ParameterTypeFileDTO {

    @ApiModelProperty(value = "系统参数类型代码",example = "TEST001")
    private String syspTypeCode;
    @ApiModelProperty(value = "系统参数类型名称",example = "测试参数类型")
    private String syspTypeName;

}

