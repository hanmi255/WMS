package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @program: wms-java
 * @description: 新增字典分类数据模型
 * @author: 骞骧
 **/
@ToString
@Getter
@Setter
@ApiModel("新增字典类型数据模型")
public class TypeAddDTO{
    // 属性：字典分类、字典名称、字典code
    @ApiModelProperty(value = "字典分类id", example = "品质")
    private Long typeGroupId;
    @ApiModelProperty(value = "字典名称", example = "月台操作")
    private String typeName;
    @ApiModelProperty(value = "字典code", example = "plat_oper")
    private String typeCode;
}
