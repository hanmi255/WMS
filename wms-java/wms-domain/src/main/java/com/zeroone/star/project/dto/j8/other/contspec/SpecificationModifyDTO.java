package com.zeroone.star.project.dto.j8.other.contspec;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：箱规修改信息数据模型
 * </p>
 * <p>地址：01星球总部</p>
 *
 * @author xban
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("箱规修改信息数据模型")
public class SpecificationModifyDTO extends SpecificationBaseDTO {
    @NotBlank(message = "主键不能为空")
    @ApiModelProperty(value = "主键",example = "8a7ba3345da000e0015da000e06e0000")
    private String id;
    @ApiModelProperty(value = "更新人名称", example = "管理员")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称", example = "admin")
    private String updateBy;
    @ApiModelProperty(value = "更新日期", example = "2025-02-27T18:24:01")
    private LocalDateTime updateDate;
    @ApiModelProperty(value = "所属部门", example = "A03")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司", example = "A03")
    private String sysCompanyCode;
}
