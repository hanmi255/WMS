package com.zeroone.star.project.dto.j1.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：角色列表显示数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "角色列表显示数据模型")
public class RoleListDTO extends RoleManagementBaseDTO {
    @ApiModelProperty(value = "角色名称", example = "财务")
    private String rolename;
}
