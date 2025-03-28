package com.zeroone.star.othermana.entity;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class BaPort {
    @ApiModelProperty(value = "港口id", example = "8a7ba3345da000e0015da300bcd9002c")
    private String id;
    @ApiModelProperty(value = "创建人名称", example = "管理员")
    private String createName;
    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    private String createBy;
    @ApiModelProperty(value = "创建日期", example = "2025-02-26 18:24:01")
    private String createDate;
    @ApiModelProperty(value = "更新人名称", example = "管理员")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称", example = "admin")
    private String updateBy;
    @ApiModelProperty(value = "更新日期", example = "2025-02-26 18:24:01")
    private String updateDate;
    @ApiModelProperty(value = "所属部门", example = "部门1")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司", example = "公司1")
    private String sysCompanyCode;
    @ApiModelProperty(value = "港口代码", example = "yjq")
    private String portCode;
    @ApiModelProperty(value = "中文名称", example = "yjq")
    private String portZhName;
    @ApiModelProperty(value = "英文名称", example = "yjq")
    private String portEnName;
    @ApiModelProperty(value = "港口三字代码", example = "yjq")
    private String portThCode;
    @ApiModelProperty(value = "港口UNCODE", example = "yjq")
    private String portUcode;
    @ApiModelProperty(value = "港口代码1", example = "yjq1")
    private String portCode1;
    @ApiModelProperty(value = "港口代码2", example = "yjq2")
    private String portCode2;
    @ApiModelProperty(value = "备注", example = "超级港口")
    private String portText;
    @ApiModelProperty(value = "停用", example = "")
    private String portDel;
}
