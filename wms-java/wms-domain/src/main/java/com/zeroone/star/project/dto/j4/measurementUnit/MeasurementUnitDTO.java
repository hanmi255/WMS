package com.zeroone.star.project.dto.j4.measurementUnit;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * @author qiaozhi
 * @title MeasurementUnit
 * @date 2025/2/21 21:39
 * @description 计量单位dto
 */

@ToString
@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
public class MeasurementUnitDTO {


    @ApiModelProperty(value = "计量单位id",example = "402881b2653ba3dd01653bc236250007")
    private String id;

    /**
     * 创建人名称
     */
    @ApiModelProperty(value = "创建人名称",example = "admin")
    private String createName;

    /**
     * 创建人登录名称
     */
    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    private String createBy;

    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期",example = "2018-08-15 12:05:08")
    @JsonFormat(pattern="yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss") //接收时间类型
    private Date createDate;

    /**
     * 更新人名称
     */
    @ApiModelProperty(value = "更新人名称",example = "admin")
    private String updateName;

    /**
     * 更新人登录名称
     */
    @ApiModelProperty(value = "更新人登录名称",example = "admin")
    private String updateBy;

    /**
     * 更新日期
     */
    @ApiModelProperty(value = "更新日期",example = "2018-08-15 12:05:08")
    @JsonFormat(pattern="yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss") //接收时间类型
    private Date updateDate;

    /**
     * 所属部门
     */
    @ApiModelProperty(value = "所属部门",example = "A04")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ApiModelProperty(value = "所属公司",example = "A04")
    private String sysCompanyCode;

    /**
     * 单位代码
     */
    @ApiModelProperty(value = "单位代码",example = "个")
    private String unitCode;

    /**
     * 单位名称
     */
    @ApiModelProperty(value = "单位名称",example = "个")
    private String unitZhName;

    /**
     * 英文名称
     */
    @ApiModelProperty(value = "英文名称",example = "piece")
    private String unitEnName;

    /**
     * 国际度量衡换算值
     */
    @ApiModelProperty(value = "国际度量衡换算值",example = "1千克 = 2.20462磅")
    private String unitChange;

    /**
     * 单位类型
     */
    @ApiModelProperty(value = "单位类型",example = "质量单位")
    private String unitType;

    /**
     * 停用
     */
    @ApiModelProperty(value = "停用",example = "否")
    private String unitDel;

}

