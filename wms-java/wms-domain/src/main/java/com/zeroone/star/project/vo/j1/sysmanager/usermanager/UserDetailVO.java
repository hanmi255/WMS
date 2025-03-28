package com.zeroone.star.project.vo.j1.sysmanager.usermanager;

import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserEditDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 *
 * PingShui
 * 2025/2/23 21:38
 */
@ApiModel(value = "查询用户详情的VO模型")
@Data
public class UserDetailVO extends UserEditDTO {
    @ApiModelProperty(value = "用户id", example = "随机生成的UUID")
    private String id;
    @ApiModelProperty(value = "部门id")
    private List<DepartmentVO> departmentVO;
    @ApiModelProperty(value = "角色id")
    private List<RoleVO> roleVO;


}
