package com.zeroone.star.project.dto.j4.unitType;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述:修改单位类型DTO
 * </p>
 *
 * @author Dorain
 * @since 2025-02-22
 */
@Getter
@Setter
@ToString
@ApiModel("修改单位类型传输对象")
public class UnitTypeModifyDTO  {

    @ApiModelProperty(value = "ID", required = true,
            example = "45612165642136")
    private String id; //唯一标识
    @ApiModelProperty(value = "单位类型代码",example = "10005")
    private String unitTypeCode;
    @ApiModelProperty(value = "单位类型名称",example = "件")
    private String unitTypeName;
}
