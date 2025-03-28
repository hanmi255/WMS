package com.zeroone.star.project.dto.j4.systemParameter;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;


/**
 *系统参数修改
 */
@ToString
@Getter
@Setter
@ApiModel("系统参数修改对象")
public class SPModifyDTO extends SPBaseDTO{
    @NotBlank(message = "id不能为空")
    @ApiModelProperty(value = "系统参数配置id", example = "1")
    private String id;
}
