package com.zeroone.star.project.dto.j3.sysmg.datadictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * @program: wms-java
 * @description: 字典类型列表显示数据模型
 * @author: 骞骧
 **/
@Getter
@Setter
@ApiModel("字典类型列表显示数据模型")
public class TypeListDTO {
    @ApiModelProperty(value = "字典类型ID", example = "402881885f117b37015f152b5197006e")
    private String id;

    @ApiModelProperty(value = "类型编码", example = "01")
    private String typeCode;

    @ApiModelProperty(value = "类型名称", example = "良品")
    private String typeName;

    @ApiModelProperty(value = "创建时间", example = "2024-06-20 10:00:00")
    private LocalDateTime createDate;
}
