package com.zeroone.star.project.query.j2.sysmgr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author Henry
 */
@Data
@ApiModel("添加用户")
public class AddUserQuery {
    @ApiModelProperty(value = "组织机构id", example = "402880d38e31819a018e31ad9517000c")
    private String id;
    @ApiModelProperty(value = "（多个）用户账号",example = "admin")
    private List<String> usernameList;
}
