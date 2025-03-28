package com.zeroone.star.project.dto.j4.parameter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author neko
 * #Description：参数类型列表显示数据对象
 * #Date: 2025/2/23 12:28
 */
@ToString
@Getter
@Setter
@ApiModel("参数类型列表显示数据对象")
public class ParameterTypeListDTO extends ParameterTypeBaseDTO{
    @ApiModelProperty(value = "参数类型ID",example = "1")
    private String id;
    @ApiModelProperty(value = "系统参数类型代码",example = "TEST001")
    private String syspTypeCode;
}
