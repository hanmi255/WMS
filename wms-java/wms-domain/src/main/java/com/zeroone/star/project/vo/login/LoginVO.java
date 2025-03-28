package com.zeroone.star.project.vo.login;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：登录显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@ApiModel("登录显示对象")
@Data
public class LoginVO {

    @ApiModelProperty(value = "用户唯一编号", example = "1")
    private String id;

    @ApiModelProperty(value = "用户名", example = "admin")
    private String username;

    @ApiModelProperty(value = "是否启用 1 启用 0 禁用 ", example = "1")
    private Byte isEnabled;

    @ApiModelProperty(value = "用户角色列表", example = "['ADMIN','MANAGER']")
    private List<String> roles;

    @ApiModelProperty(value = "用户名称", example = "nefertari")
    private String realname;

    @ApiModelProperty(value = "用户电话", example = "15793169971")
    private String mobilePhone;

    @ApiModelProperty(value = "用户企业电话", example = "18177643697")
    private String officePhone;

    @ApiModelProperty(value = "用户邮件", example = "xicolil250@usoplay.com")
    private String email;

    @ApiModelProperty(value = "签名文件", example = "SHA256withRSA:base64EncodedSignature==")
    private String signatureFile;
}
