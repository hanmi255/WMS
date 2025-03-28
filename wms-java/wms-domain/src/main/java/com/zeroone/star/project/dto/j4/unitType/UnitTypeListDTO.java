package com.zeroone.star.project.dto.j4.unitType;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * @author 1+5
 * @title UnitTypeListDTO
 * @date 2025/2/23 21 45
 * @description 单位类型DTO
 */
@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class UnitTypeListDTO extends PageDTO {


    @ApiModelProperty(value = "单位类型id",example = "2c9efaca9169cf1101926ef8b1d801b3")
    private String id;

    /**
     * 创建人名称
     */
    @ApiModelProperty(value = "创建人名称",example = "管理员")
    private String createName;

    /**
     * 创建人登录名称
     */
    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    private String createBy;

    /**
     * 创建日期
     */
    @JsonFormat(pattern="yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss") //接收时间类型
    @ApiModelProperty(value = "创建日期",example = "2024-10-09 09:50:45")
    private Date createDate;

    /**
     * 更新人名称
     */
    @ApiModelProperty(value = "更新人名称",example = "管理员")
    private String updateName;

    /**
     * 更新人登录名称
     */
    @ApiModelProperty(value = "更新人登录名称",example = "admin")
    private String updateBy;

    /**
     * 更新日期
     */
    @JsonFormat(pattern="yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss") //接收时间类型
    @ApiModelProperty(value = "更新日期",example = "2024-10-09 09:50:45")
    private Date updateDate;

    /**
     * 所属部门
     */
    @ApiModelProperty(value = "所属部门",example = "A05")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ApiModelProperty(value = "所属公司",example = "A05")
    private String sysCompanyCode;

    /**
     * 单位类型代码
     */
    @ApiModelProperty(value = "单位类型代码",example = "10001")
    private String unitTypeCode;

    /**
     * 单位类型名称
     */
    @ApiModelProperty(value = "单位类型名称",example = "件")
    private String unitTypeName;



}
