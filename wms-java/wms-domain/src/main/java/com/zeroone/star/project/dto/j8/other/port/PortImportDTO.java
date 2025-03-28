package com.zeroone.star.project.dto.j8.other.port;

import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.format.DateTimeFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：导入港口信息数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yjq
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("导入港口信息数据模型")
public class PortImportDTO {
    @ApiModelProperty(value = "港口id", example = "8a7ba3345da000e0015da300bcd9002c")
    @ExcelProperty("港口id")
    private String id;
    @ApiModelProperty(value = "创建人名称", example = "管理员")
    @ExcelProperty("创建人名称")
    private String createName;
    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    @ExcelProperty("创建人登录名称")
    private String createBy;
    @ApiModelProperty(value = "创建日期", example = "2025-02-26 18:24:01")
    @ExcelProperty(value = "创建日期")
    private String createDate;
    @ApiModelProperty(value = "更新人名称", example = "管理员")
    @ExcelProperty("更新人名称")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称", example = "admin")
    @ExcelProperty("更新人登录名称")
    private String updateBy;
    @ApiModelProperty(value = "更新日期", example = "2025-02-26 18:24:01")
    @ExcelProperty("更新日期")
    private String updateDate;
    @ApiModelProperty(value = "所属部门", example = "部门1")
    @ExcelProperty("所属部门")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司", example = "公司1")
    @ExcelProperty("所属公司")
    private String sysCompanyCode;
    @ApiModelProperty(value = "港口代码", example = "yjq")
    @ExcelProperty("港口代码")
    private String portCode;
    @ApiModelProperty(value = "中文名称", example = "yjq")
    @ExcelProperty("中文名称")
    private String portZhName;
    @ApiModelProperty(value = "英文名称", example = "yjq")
    @ExcelProperty("英文名称")
    private String portEnName;
    @ApiModelProperty(value = "港口三字代码", example = "yjq")
    @ExcelProperty("港口三字代码")
    private String portThCode;
    @ApiModelProperty(value = "港口UNCODE", example = "yjq")
    @ExcelProperty("港口UNCODE")
    private String portUcode;
    @ApiModelProperty(value = "港口代码1", example = "yjq1")
    @ExcelProperty("港口代码1")
    private String portCode1;
    @ApiModelProperty(value = "港口代码2", example = "yjq2")
    @ExcelProperty("港口代码2")
    private String portCode2;
    @ApiModelProperty(value = "备注", example = "超级港口")
    @ExcelProperty("备注")
    private String portText;
    @ApiModelProperty(value = "停用", example = "")
    @ExcelProperty("停用")
    private String portDel;
}
