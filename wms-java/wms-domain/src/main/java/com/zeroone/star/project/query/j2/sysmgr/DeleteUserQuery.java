package com.zeroone.star.project.query.j2.sysmgr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Henry
 */
@Data
@ApiModel("删除组织成员")
public class DeleteUserQuery {
    @ApiModelProperty(value = "组织机构id", example = "402880d38e31819a018e31ad9517000c")
    private String id;
    @ApiModelProperty(value = "用户账号",example = "admin")
    private String username;
}
