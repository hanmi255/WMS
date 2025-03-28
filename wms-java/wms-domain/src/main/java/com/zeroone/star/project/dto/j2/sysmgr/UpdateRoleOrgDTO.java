package com.zeroone.star.project.dto.j2.sysmgr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("更新组织角色的请求参数")
public class UpdateRoleOrgDTO {

    @ApiModelProperty("角色Id列表")
    private List<String> roleIds;

    @ApiModelProperty("组织机构ID")
    private  String OrgId;


}
