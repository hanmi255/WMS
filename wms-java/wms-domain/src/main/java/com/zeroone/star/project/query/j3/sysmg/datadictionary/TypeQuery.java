package com.zeroone.star.project.query.j3.sysmg.datadictionary;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * @program: wms-java
 * @description: 字典类型查询对象
 * @author: 骞骧
 **/
@ToString
@Getter
@Setter
@ApiModel("字典类型查询对象")
public class TypeQuery extends PageQuery {
    @ApiModelProperty(value = "字典类型名称", example = "小时")
    private String typeName;

    @ApiModelProperty(value = "字典类型编码", example = "hour")
    private String typeCode;

    @NotBlank(message = "字典分类ID不能为空")
    @ApiModelProperty(value = "字典分类ID", required = true, example = "402881885f117b37015f152afeb4006c")
    private String typegroupid;
}
