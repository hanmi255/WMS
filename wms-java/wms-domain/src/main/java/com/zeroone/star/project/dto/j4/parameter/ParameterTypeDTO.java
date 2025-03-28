package com.zeroone.star.project.dto.j4.parameter;

import com.zeroone.star.project.query.j4.parameter.ParameterTypeQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * @author qiaozhi
 * @title ParameterType
 * @date 2025/2/21 21:37
 * @description 参数类型dto
 */
@Getter
@Setter
@ToString
@ApiModel(value = "系统参数类型DTO对象")
public class ParameterTypeDTO extends ParameterTypeQuery {

    @ApiModelProperty(value = "更新人名称",example = "张三")
    private String update_name;
    @ApiModelProperty(value = "更新人登录名称",example = "张三")
    private String update_by;
    @ApiModelProperty(value = "更新时间",example = "2025-02-22 12:00:00")
    private LocalDateTime update_date;

}

