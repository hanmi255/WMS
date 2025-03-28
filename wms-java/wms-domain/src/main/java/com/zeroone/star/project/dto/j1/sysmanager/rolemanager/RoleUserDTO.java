package com.zeroone.star.project.dto.j1.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/19
 */
@Data
@ApiModel("添加角色用户")
public class RoleUserDTO {

    /**
     * 用户ID
     */
    @NotBlank(message = "用户ID必须提供")
    @ApiModelProperty(value = "用户ID",example = "2c9221a4717bb44c01717d01c6ff0540",required = true)
    private String userId;

    /**
     * 角色ID
     */
    @NotBlank(message = "角色ID必须提供")
    @ApiModelProperty(value = "角色ID",example = "2c9221a4717bb44c09817d01b6ff0540",required = true)
    private String roleId;

}
