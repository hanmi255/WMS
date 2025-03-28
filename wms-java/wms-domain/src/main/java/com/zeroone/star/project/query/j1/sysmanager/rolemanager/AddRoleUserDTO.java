package com.zeroone.star.project.query.j1.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/20
 */
@Data
@ApiModel("新增角色用户")
public class AddRoleUserDTO {

    @ApiModelProperty(value = "角色ID列表，以逗号分割",example = "2c9221a47,2c9221a47,2c9221a47,2c9221a47,2c9221a47",required = true)
    private List<String> roleIdList;

    private String userId;
}
