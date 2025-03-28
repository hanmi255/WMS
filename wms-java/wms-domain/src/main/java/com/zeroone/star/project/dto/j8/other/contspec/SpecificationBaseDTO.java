package com.zeroone.star.project.dto.j8.other.contspec;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：箱规基本信息数据模型
 * </p>
 * <p>地址：01星球总部</p>
 * @author xban
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("箱规基本信息数据模型")
public class SpecificationBaseDTO {
    @NotBlank(message = "箱规代码不能为空")
    @ExcelProperty(value = "箱规代码",index = 5)
    @ApiModelProperty(value = "箱规代码",example = "40")
    private String contSpecId;

    @NotBlank(message = "箱规名称不能为空")
    @ExcelProperty(value = "箱规名称",index = 6)
    @ApiModelProperty(value = "箱规名称",example = "40")
    private String contSpecName;
}
