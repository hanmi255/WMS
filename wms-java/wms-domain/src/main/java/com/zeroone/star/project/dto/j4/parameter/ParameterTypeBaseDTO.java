package com.zeroone.star.project.dto.j4.parameter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author neko
 * #Description：参数类型基础数据对象
 * #Date: 2025/2/23 12:20
 */
@ToString
@Getter
@Setter
@ApiModel("参数类型基础数据对象")
public class ParameterTypeBaseDTO {
    @ApiModelProperty(value = "系统参数类型名称",example = "测试参数类型")
    private String syspTypeName;
}
