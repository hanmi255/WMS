package com.zeroone.star.project.query.j4.systemParameter;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 描述：系统参数查询对象
 */

@ToString
@Getter
@Setter
@ApiModel("系统参数查询")
public class SPPageQuery extends PageQuery {

    @ApiModelProperty(value = "系统参数配置显示过滤选项", example = "组织")
    private String systemParamType;

    @ApiModelProperty(value = "关键字", example = "测试")
    private String keyword;
}