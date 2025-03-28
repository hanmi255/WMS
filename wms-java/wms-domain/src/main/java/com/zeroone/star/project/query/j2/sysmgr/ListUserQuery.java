package com.zeroone.star.project.query.j2.sysmgr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Henry
 */
@Data
@ApiModel("获取组织成员")
public class ListUserQuery {
    @ApiModelProperty(value = "组织机构id",example = "402880d38e31819a018e31ad9517000c")
    private String id;
    @ApiModelProperty(value = "用户账号", example = "admin")
    private String username;
    @ApiModelProperty(value = "用户名称", example = "管理员")
    private String realname;
    @ApiModelProperty(value = "页码数",example = "1")
    private Integer pageIndex;
    @ApiModelProperty(value = "每页数量",example = "5")
    private Integer pageSize;
}
