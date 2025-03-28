package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;

/**
 * <p>
 * 描述：用户管理继承数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "用户管理继承数据模型")
public class UserManagementBaseDTO implements Serializable {



    @ApiModelProperty(value = "用户账号", example = "admin",required = true)
    protected String username;

    @ApiModelProperty(value = "用户姓名", example = "张三")
    private String realname;



}
