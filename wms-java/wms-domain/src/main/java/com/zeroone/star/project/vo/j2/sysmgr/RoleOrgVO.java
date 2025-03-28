package com.zeroone.star.project.vo.j2.sysmgr;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@ApiModel(value = "获取和更新组织角色后的返回对象")
@NoArgsConstructor
@AllArgsConstructor
public class RoleOrgVO {
    /**
     * 角色id
     */
    @ApiModelProperty("角色id")
    private String roleId;

    /**
     * 角色名字
     */
    @ApiModelProperty("角色名字")
    private String roleName;
    /**
     * 组织id
     */
    @ApiModelProperty("组织id")
    private String orgID;
}
