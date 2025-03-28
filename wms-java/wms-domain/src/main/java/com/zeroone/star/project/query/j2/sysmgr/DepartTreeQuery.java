package com.zeroone.star.project.query.j2.sysmgr;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：组织列表查询参数
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author TWTW
 * @version 1.0.0
 */

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("组织列表查询参数")
public class DepartTreeQuery {
    @ApiModelProperty(value = "父部门ID", example = "40289fe393dddaa90193de2cb61a0004")
    private String parentDepartId;
}
