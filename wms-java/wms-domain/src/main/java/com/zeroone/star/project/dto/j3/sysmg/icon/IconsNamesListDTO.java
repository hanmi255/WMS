package com.zeroone.star.project.dto.j3.sysmg.icon;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author Vast
 * @version 1.0
 * @function:图标名称列表数据模型
 */
@SuppressWarnings({"all"})
@ToString
@Getter
@Setter
@ApiModel("图标名称列表数据模型")
public class IconsNamesListDTO {
    @ApiModelProperty(value = "唯一标识", example = "8a8ab0b246dc81120146dc8180460000")
    private String id;
    @ApiModelProperty(value = "图标名称", example = "默认")
    private String name;
    @ApiModelProperty(value = "图标样式", example = "default")
    private String iconclas;//图标类型
}
