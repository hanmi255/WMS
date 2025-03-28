package com.zeroone.star.project.vo.j1.sysmanager.rolemanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/19
 */
@Data
@ApiModel("属于该角色的用户信息")
public class RoleUserVO {

    /**
     * 用户ID
     */
    @ApiModelProperty(value = "用户ID",example = "2c9221a4717bb44c01717d01c6ff0540")
    private String id;

    /**
     * 用户账号
     */
    @ApiModelProperty(value = "用户账号",example = "admin")
    private String username;

    /**
     * 用户名称
     */
    @ApiModelProperty(value = "用户名称",example = "管理员")
    private String realname;

    /**
     * 有效状态
     */
    @ApiModelProperty(value = "有效状态",example = "1（表示激活状态）")
    private Integer status;
}
