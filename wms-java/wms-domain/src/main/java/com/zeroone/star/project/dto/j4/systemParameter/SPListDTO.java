package com.zeroone.star.project.dto.j4.systemParameter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;


/**
 * 系统参数列表显示对象
 */
@ToString
@Getter
@Setter
@ApiModel("系统参数列表显示对象")
public class SPListDTO extends SPBaseDTO{
    @ApiModelProperty(value = "系统参数配置id", example = "1")
    private String id;
}
