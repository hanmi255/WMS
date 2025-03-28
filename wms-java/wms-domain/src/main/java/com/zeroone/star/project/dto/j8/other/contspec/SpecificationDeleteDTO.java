package com.zeroone.star.project.dto.j8.other.contspec;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：箱规删除数据模型
 * </p>
 * <p>地址：01星球总部</p>
 * @author xban
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("箱规删除数据模型")
public class SpecificationDeleteDTO {

    @NotBlank(message = "主键不能为空")
    @ApiModelProperty(value = "主键",example = "8a7ba3345da000e0015da000e06e0000")
    private String id;
}
