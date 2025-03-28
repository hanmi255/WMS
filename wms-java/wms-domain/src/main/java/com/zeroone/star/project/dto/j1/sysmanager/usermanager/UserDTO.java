package com.zeroone.star.project.dto.j1.sysmanager.usermanager;


import com.zeroone.star.project.vo.j1.sysmanager.usermanager.DepartmentVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.RoleVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 *
 *  pingshui
 *  2025/2/23 21:01
 */
@Data
@ApiModel(value = "新增用户数据模型")
public class UserDTO extends UserInputDTO{
    @ApiModelProperty(value = "id", example = "不需要传由后端随机生成",hidden = true)
    private String id;
    @ApiModelProperty(value = "用户账号", example = "admin",required = true)
    private String username;
    @ApiModelProperty(value = "密码", example = "123456",required = true)
    private String password;
    @ApiModelProperty(value = "部门对象数组",required = true)
    private List<String> departmentIds;
    @ApiModelProperty(value = "角色对象数组",required = true)
    private List<String> roleIds;




}
