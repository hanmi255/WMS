package com.zeroone.star.project.query.j8.other.contspec;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotNull;

/**
 * <p>
 * 描述：箱规查询数据模型
 * </p>
 * <p>地址：01星球总部</p>
 * @author xban
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("箱规查询数据模型")
public class SpecificationQuery extends PageQuery {

    @ApiModelProperty(value = "箱规代码",example = "40")
    private String specificationId;

    @ApiModelProperty(value = "箱规名称",example = "40")
    private String  specificationName;
}
