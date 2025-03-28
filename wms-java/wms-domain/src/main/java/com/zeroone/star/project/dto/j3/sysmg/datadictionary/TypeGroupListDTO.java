package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @program: wms-java
 * @description: 字典分类列表显示数据模型
 * @author: Hao
 **/
@ToString
@Getter
@Setter
@ApiModel("字典分类列表显示数据模型")
public class TypeGroupListDTO extends TypeGroupBaseDTO{
    @ApiModelProperty(value = "唯一标识",example = "402881e44df713f5014df738349c002f")
    private String id;

    @ApiModelProperty(value = "用于排序的字段", example = "字典名称")
    private String sort;

    @ApiModelProperty(value = "排序顺序", example = "desc")
    private String order;
}
