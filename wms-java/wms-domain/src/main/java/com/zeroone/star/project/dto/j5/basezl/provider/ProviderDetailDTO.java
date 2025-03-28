package com.zeroone.star.project.dto.j5.basezl.provider;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * 功能：供应商详细数据模型
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:31
 */
@Getter
@Setter
@ToString
@ApiModel("供应商详细数据模型")
public class ProviderDetailDTO extends ProviderModifyDTO {

    @ApiModelProperty(value = "创建人名称",example = "管理员")
    private String createName;
    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    private String createBy;
    @ApiModelProperty(value = "创建日期",example = "2024-10-09 09:32:11")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "更新人名称",example = "管理员")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称",example = "admin")
    private String updateBy;
    @ApiModelProperty(value = "更新日期",example = "2024-10-09 09:32:11")
    private LocalDateTime updateDate;

    @ApiModelProperty(value = "所属部门",example = "A05")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司",example = "A05")
    private String sysCompanyCode;

}
