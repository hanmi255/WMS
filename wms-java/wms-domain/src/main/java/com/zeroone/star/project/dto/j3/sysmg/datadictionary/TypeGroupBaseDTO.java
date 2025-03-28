package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @program: wms-java
 * @description: 字典分类继承数据模型
 * @author: Hao
 **/
@ToString
@Getter
@Setter
@ApiModel("字典分类继承数据模型")
public class TypeGroupBaseDTO {
    @ApiModelProperty(value = "字典名称", example = "送货方式")
    private String typegroupName;

    @ApiModelProperty(value = "字典Code", example = "tms_thfs")
    private String typegroupCode;
}