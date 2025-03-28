package com.zeroone.star.project.query.j4.measurementUnit;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author neko
 * #Description：计量单位查询对象
 * #Date: 2025/2/23 14:40
 */
@ToString
@Getter
@Setter
@ApiModel("计量单位查询对象")
public class MeasurementUnitQuery {
    @ApiModelProperty(value = "单位代码",example = "1")
    private String unitCode;
    @ApiModelProperty(value = "单位名称",example = "面")
    private String unitZhName;
    @ApiModelProperty(value = "英文名称",example = "face")
    private String unitEnName;
}
