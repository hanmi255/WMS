package com.zeroone.star.project.dto.j1.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：角色删除数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 小康
 * @version 1.0.0
 */

@Getter
@Setter
@ToString
@ApiModel("角色删除数据模型")
public class RoleDeleteDTO {
    @ApiModelProperty(value = "角色ID",example = "2c9221a4717bb44c01717ce20ca00411")
    private String id;
}
