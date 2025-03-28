package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：用户表导出数据模型（匹配Excel模板）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author halo
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "用户表导出数据模型")
public class UserExportDTO {

    @ExcelProperty(index = 0, value = "手机")
    @ApiModelProperty(value = "用户手机号", example = "17661928852")
    private String mobile;

    @ExcelProperty(index = 1, value = "办公电话")
    @ApiModelProperty(value = "办公电话", example = "17661928852")
    private String officePhone;

    @ExcelProperty(index = 2, value = "邮箱")
    @ApiModelProperty(value = "电子邮箱", example = "838398945@qq.com")
    private String email;

    @ExcelProperty(index = 3, value = "用户名")
    @ApiModelProperty(value = "用户名", example = "Halo0007")
    private String username;

    @ExcelProperty(index = 4, value = "真实姓名")
    @ApiModelProperty(value = "真实姓名", example = "1231")
    private String realName;

    @ExcelProperty(index = 5, value = "角色编码")
    @ApiModelProperty(value = "角色编码（多个角色编码用逗号分隔）", example = "cs")
    private String roleCodes;

    @ExcelProperty(index = 6, value = "组织机构编码")
    @ApiModelProperty(value = "组织机构编码（多个组织机构编码用逗号分隔）", example = "A05")
    private String orgCodes;
}