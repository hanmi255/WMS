package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;

/**
 * <p>
 * 描述：用户编辑数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "用户编辑数据模型")
public class UserEditDTO extends UserManagementBaseDTO implements Serializable {

    @ApiModelProperty(value = "用户类型", example = "1-4    1代表 系统用户，2代表接口用户，3代表公司权限 4代表当前用户接口")
    private String userType;

    @ApiModelProperty(value = "手机号码", example = "123456789")
    private String mobilePhone;

    @ApiModelProperty(value = "办公电话", example = "123456789")
    private String officePhone;

    @ApiModelProperty(value = "邮箱", example = "123456789@qq.com")
    private String email;
}
