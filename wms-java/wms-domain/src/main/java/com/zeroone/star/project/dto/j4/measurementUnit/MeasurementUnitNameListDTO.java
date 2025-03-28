package com.zeroone.star.project.dto.j4.measurementUnit;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author adi
 * #Description 获取计量单位名称列表DTO
 * #Date: 2025/2/23 22:27
 */
@ToString
@Getter
@Setter
@ApiModel("计量单位名称列表")
public class MeasurementUnitNameListDTO {

    @ApiModelProperty(value = "单位名称",example = "个")
    private String unit_zh_name;


}

