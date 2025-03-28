package com.zeroone.star.project.dto.j1.sysmanager.usermanager;


import com.zeroone.star.project.vo.j1.sysmanager.usermanager.UserDetailVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 *
 * PingShui
 * 2025/2/23 21:42
 */
@Data
@ApiModel("编辑用户信息的的数据模型")
public class UserDetailDTO extends UserDetailVO implements Serializable {
    @ApiModelProperty(value = "用户账号", example = "admin",required = false,hidden = true)
    private String username;

}
