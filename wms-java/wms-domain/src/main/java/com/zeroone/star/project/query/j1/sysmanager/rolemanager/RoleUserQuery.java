package com.zeroone.star.project.query.j1.sysmanager.rolemanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/19
 */
@Data
@ApiModel("获取角色用户列表")
public class RoleUserQuery extends PageQuery {

    /**
     * 角色ID
     */
    @ApiModelProperty(value = "角色ID", example = "2c9221a4717bb44c01717ce20ca00411",required = true)
    private String id;

    /**
     * 用户账号
     */
    @ApiModelProperty(value = "用户账号（表单条件）",example = "admin")
    private String username;

    /**
     * 角色名称
     */
    @ApiModelProperty(value = "用户名称（表单条件）",example = "管理员")
    private String realname;

}
