package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @program: wms-java
 * @description: 字典类型名称数据模型
 * @author: 骞骧
 **/
@Data
@ApiModel("字典类型继承数据模型")
public class TypeBaseDTO {
    @ApiModelProperty(value = "类型名称", required = true, example = "良品")
    private String typeName;

    @ApiModelProperty(value = "类型编码", required = true, example = "01")
    private String typeCode;

    @ApiModelProperty(value = "字典分类ID", required = true, example = "297e201047e95ee30147e9ba56ce0009")
    @JsonProperty("typegroupid")  // 明确JSON字段映射
    private String typeGroupId;
}
