package com.zeroone.star.project.vo.j1.sysmanager.usermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 *
 * PingShui
 * 2025/2/23 21:48
 */
@Data
@ApiModel(value = "新增用户中的角色VO模型")
public class RoleVO {
    @ApiModelProperty(value = "角色id", example = "随机生成的UUID")
    private String id;
    @ApiModelProperty(value = "角色名称", example = "财务")
    private String rolename;
}
