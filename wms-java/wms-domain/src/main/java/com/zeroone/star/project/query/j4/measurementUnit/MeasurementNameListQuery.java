package com.zeroone.star.project.query.j4.measurementUnit;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author adi
 *Description 获取单位名称的条件
 * #Date: 2025/2/23 21:44
 */
@ToString
@Getter
@Setter
@ApiModel("获取单位名称列表")
public class MeasurementNameListQuery {
    @ApiModelProperty(value = "单位名称",example = "个")
    private String unitZhName;
}
