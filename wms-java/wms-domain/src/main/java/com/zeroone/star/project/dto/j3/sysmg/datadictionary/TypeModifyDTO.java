package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @program: wms-java
 * @description: 修改字典类型数据模型
 * @author: 骞骧
 **/
@Getter
@Setter
@ToString
@ApiModel("修改字典类型数据模型")
public class TypeModifyDTO extends TypeBaseDTO{
    @ApiModelProperty(value = "字典类型ID", required = true, example = "402881885f117b37015f152b5197006e")
    private String id;
}
