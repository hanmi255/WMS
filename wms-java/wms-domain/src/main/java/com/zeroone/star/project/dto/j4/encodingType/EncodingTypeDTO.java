package com.zeroone.star.project.dto.j4.encodingType;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author qiaozhi
 * @title EncodingType
 * @date 2025/2/21 21:40
 * @description 编码类型dto
 */
@Setter
@Getter
@ToString
@ApiModel(value = "编码类型dto")
public class EncodingTypeDTO {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "主键",example = "4028f0329517c28e019517c2dc140001")
    private String id;
    @ApiModelProperty(value = "创建人名称",example = "管理员")
    private String createName;
    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    private String createBy;
    @ApiModelProperty(value = "更新人名称",example = "管理员")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称",example = "admin")
    private String updateBy;
    @ApiModelProperty(value = "所属部门",example = "A05")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司",example = "A05")
    private String sysCompanyCode;
    @ApiModelProperty(value = "编码类型代码",example = "11")
    private String snroTypeCode;
    @ApiModelProperty(value = "编码类型名称",example = "编码类型名称")
    private String snroTypeName;


}
