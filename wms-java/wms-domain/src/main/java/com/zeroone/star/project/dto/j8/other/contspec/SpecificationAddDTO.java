package com.zeroone.star.project.dto.j8.other.contspec;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：箱规录入信息数据模型
 * </p>
 * <p>地址：01星球总部</p>
 *
 * @author xban
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("箱规录入信息数据模型")
public class SpecificationAddDTO extends SpecificationBaseDTO{
    @ApiModelProperty(value = "创建人名称", example = "管理员")
    @ExcelProperty(value = "创建人名称",index = 0)
    private String createName;
    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    @ExcelProperty(value = "创建人登录名称",index = 1)
    private String createBy;
    @ApiModelProperty(value = "创建日期", example = "2017-08-02T06:53:18")
    @ExcelProperty(value = "创建日期",index = 2)
    private LocalDateTime createDate;
    @ApiModelProperty(value = "所属部门", example = "A03")
    @ExcelProperty(value = "所属部门",index = 3)
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司", example = "A03")
    @ExcelProperty(value = "所属公司",index = 4)
    private String sysCompanyCode;
}
