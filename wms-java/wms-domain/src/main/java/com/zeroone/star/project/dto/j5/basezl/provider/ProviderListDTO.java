package com.zeroone.star.project.dto.j5.basezl.provider;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：供应商列表显示数据对象
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:30
 */
@ToString
@Getter
@Setter
@ApiModel("供应商列表显示数据对象")
public class ProviderListDTO extends ProviderBaseDTO{
    @ApiModelProperty(value = "供应商ID", example = "1")
    private String id;
}
