package com.zeroone.star.project.dto.j5.basezl.provider;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：可以修改供应商信息传输数据模型
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:32
 */
@ToString
@Getter
@Setter
@ApiModel("供应商修改信息数据模型")
public class ProviderModifyDTO extends ProviderBaseDTO{
    @ApiModelProperty(value = "供应商ID", example = "1")
    private String id;
}
