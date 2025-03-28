package com.zeroone.star.project.query.j3.sysmg.icon;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author Vast
 * @version 1.0
 * @function:图标列表查询对象
 */
@SuppressWarnings({"all"})
@ToString
@Getter
@Setter
@ApiModel("图标列表分页查询对象")
public class IconsQuery extends PageQuery {
    @ApiModelProperty(value = "图标名称", example = "默认")
    private String name;
}
