package com.zeroone.star.project.dto.j2.sysmgr;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Henry
 */
@Data
@ApiModel(value = "UserDTO", description = "用户模型")
public class UserDTO {
    @ApiModelProperty(value = "用户账号", example = "admin")
    private String username;
    @ApiModelProperty(value = "用户名称", example = "管理员")
    private String realname;
    @ApiModelProperty(value = "有效状态", example = "1")
    private Integer status;
}
