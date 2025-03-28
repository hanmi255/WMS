package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @program: wms-java
 * @description: 修改字典分类数据模型
 * @author: Hao
 **/
@ToString
@Getter
@Setter
@ApiModel("修改字典分类数据模型")
public class TypeGroupModifyDTO extends TypeGroupBaseDTO{
    @ApiModelProperty(value = "唯一标识", example = "402881e55af64f07015af68356550004",required = true)
    private String id;
}
