package com.zeroone.star.project.query.j1.sysmanager.rolemanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 获取用户列表（查询不属于该角色的用户）查询条件
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/19
 */
@Data
@ApiModel("获取用户列表（查询不属于该角色的用户）（不给出用户账号和用户名称时，默认查询全部）")
public class UserQuery extends PageQuery{

    /**
     * 角色id
     */
    @NotBlank(message = "角色id不能为空")
    @ApiModelProperty(value = "角色id",example = "2c9221a4717bb44c01717ce20ca00411",required = true)
    private String roleId;

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


}
