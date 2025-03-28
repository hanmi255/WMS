package com.zeroone.star.project.query.j2.sysmgr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("获取组织角色的查询条件")
public class RoleOrgQuery {

    @ApiModelProperty("组织结构ID")
    private String orgId;//组织结构id

}
