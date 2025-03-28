package com.zeroone.star.project.dto.j4.systemParameter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.Size;

/**
 * 系统参数列表基础对象
 */
@ToString
@Getter
@Setter
@ApiModel("系统参数列表基础对象")
public class SPBaseDTO {
    /**
     * sys_conf_type,sys_conf_step,sys_conf_org,sys_conf_partner,sys_para1,sys_para2,sys_para3,sys_conf_text
     */
    @ApiModelProperty(value = "系统参数类型", example = "测试")
    @Size(max = 32, message = "系统参数类型长度不能超过32个字符")
    private String sysConfType;

    @ApiModelProperty(value = "业务操作环节", example = "11")
    @Size(max = 32, message = "业务操作环节长度不能超过32个字符")
    private String sysConfStep;

    @ApiModelProperty(value = "组织", example = "组织")
    @Size(max = 32, message = "组织长度不能超过32个字符")
    private String sysConfOrg;

    @ApiModelProperty(value = "合作伙伴", example = "中国")
    @Size(max = 32, message = "合作伙伴长度不能超过32个字符")
    private String sysConfPartner;

    @ApiModelProperty(value = "参数1", example = "加急")
    @Size(max = 32, message = "参数1长度不能超过32个字符")
    private String sysPara1;

    @ApiModelProperty(value = "参数2", example = "常规")
    @Size(max = 32, message = "参数2长度不能超过32个字符")
    private String sysPara2;

    @ApiModelProperty(value = "参数3", example = "紧急")
    @Size(max = 32, message = "参数3长度不能超过32个字符")
    private String sysPara3;

    @ApiModelProperty(value = "备注", example = "这是演示案例")
    @Size(max = 32, message = "备注长度不能超过64个字符")
    private String sysConfText;
}
