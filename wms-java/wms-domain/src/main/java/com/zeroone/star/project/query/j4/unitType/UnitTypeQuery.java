package com.zeroone.star.project.query.j4.unitType;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author qiaozhi
 * @title UnitType
 * @date 2025/2/21 21:38
 * @description 单位类型query
 */
@Getter
@Setter
@ToString
@ApiModel("单位类型查询对象")
public class UnitTypeQuery {

    @ApiModelProperty(value = "单位类型代码（模糊查询）", example = "10005")
    private String unitTypeCode;  // 模糊查询
    @ApiModelProperty(value = "单位类型名称（模糊查询）", example = "千克")
    private String unitTypeName;  // 模糊查询

}
