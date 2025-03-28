package com.zeroone.star.project.query.j4.parameter;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author qiaozhi
 * @title ParameterType
 * @date 2025/2/21 21:37
 * @description 参数类型query
 */
@ToString
@Getter
@Setter
@ApiModel("参数类型查询对象")
public class ParameterTypeQuery extends PageQuery {

    @ApiModelProperty(value = "系统参数类型编号",example = "001")
    private String id;
    @ApiModelProperty(value = "系统参数类型代码",example = "TEST001")
    private String syspTypeCode;
    @ApiModelProperty(value = "系统参数类型名称",example = "测试参数类型")
    private String syspTypeName;

}
