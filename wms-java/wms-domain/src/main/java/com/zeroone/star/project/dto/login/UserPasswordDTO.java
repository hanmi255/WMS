package com.zeroone.star.project.dto.login;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;

/**
 * 描述：用户修改密码录入
 *
 * @author nefertari
 * @version 1.0.0
 */
@Data
@ApiModel("用户修改密码对象")
@Validated
public class UserPasswordDTO {
    @ApiModelProperty(value = "用户旧密码", example = "123456")
    @Size(min = 6, max = 15, message = "输入的密码不小于6位或不大于15位")
    @NotEmpty(message = "输入的密码不能为空")
    private String oldPassword;
    @ApiModelProperty(value = "用户新密码", example = "llg123")
    @Size(min = 6, max = 15, message = "输入的密码不小于6位或不大于15位")
    @NotEmpty(message = "输入的密码不能为空")
    private String newPassword;
    @ApiModelProperty(value = "用户再次密码", example = "llg123")
    @Size(min = 6, max = 15, message = "输入的密码不小于6位或不大于15位")
    @NotEmpty(message = "输入的密码不能为空")
    private String rePassword;
}
