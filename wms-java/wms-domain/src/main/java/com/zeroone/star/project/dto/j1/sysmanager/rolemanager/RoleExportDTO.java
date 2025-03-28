package com.zeroone.star.project.dto.j1.sysmanager.rolemanager;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("角色导出数据模型")
public class RoleExportDTO{
    @ExcelProperty(value = "角色名称", index = 0)
    private String rolename;

    @ExcelProperty(value = "角色编码", index = 1)
    private String rolecode;
}
