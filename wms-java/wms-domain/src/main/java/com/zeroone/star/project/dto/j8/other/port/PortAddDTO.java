package com.zeroone.star.project.dto.j8.other.port;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
/**
 * <p>
 * 描述：录入港口信息数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yjq
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("录入港口信息数据模型")
public class PortAddDTO extends PortBaseDTO{
    @ApiModelProperty(value = "创建人名称", example = "管理员")
    private String createName;
    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    private String createBy;
    @ApiModelProperty(value = "创建日期", example = "2025-02-26 18:24:01")
    private String createDate;
    @ApiModelProperty(value = "所属部门", example = "部门1")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司", example = "公司1")
    private String sysCompanyCode;

}
