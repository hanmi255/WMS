package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

/**
 * <p>
 * 描述：重置密码数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-halo
 * @version 1.0.0
 */
@Data
@ApiModel("重置密码数据传输对象")
public class ResetPasswordDTO {
    
    @NotBlank(message = "用户ID不能为空")
    @ApiModelProperty(value = "用户ID", example = "402880879551861f019551c075a7000d", required = true)
    private String userId;

    @NotBlank(message = "新密码不能为空")
    @ApiModelProperty(value = "新密码", required = true)
    private String newPassword;
} 
