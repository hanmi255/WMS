package com.zeroone.star.project.dto.j4.measurementUnit;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

/**
 * @author adi
 * #Description 获取计量单位列表DTO
 * #Date: 2025/2/23 22:55
 */
@ToString
@Getter
@Setter
@ApiModel("获取计量单位列表")
public class MeasurementUnitListDTO extends PageDTO {
    @ApiModelProperty(value = "计量单位id",example = "402881b2653ba3dd01653bc236250007")
    private String id;

    @ApiModelProperty(value = "创建人名称",example = "admin")
    private String create_name;

    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    private String create_by;

    @ApiModelProperty(value = "创建日期",example = "2018-08-15 12:05:08")
    private Date create_date;

    @ApiModelProperty(value = "更新人名称",example = "admin")
    private String update_name;

    @ApiModelProperty(value = "更新人登录名称",example = "admin")
    private String update_by;

    @ApiModelProperty(value = "更新日期",example = "2018-08-15 12:05:08")
    private Date update_date;

    @ApiModelProperty(value = "所属部门",example = "A04")
    private String sys_org_code;

    @ApiModelProperty(value = "所属公司",example = "A04")
    private String sys_company_code;

    @ApiModelProperty(value = "单位代码",example = "个")
    private String unit_code;

    @ApiModelProperty(value = "单位名称",example = "个")
    private String unit_zh_name;

    @ApiModelProperty(value = "英文名称",example = "piece")
    private String unit_en_name;

    @ApiModelProperty(value = "国际度量衡换算值",example = "1千克 = 2.20462磅")
    private String unit_change;

    @ApiModelProperty(value = "单位类型",example = "质量单位")
    private String unit_type;

    @ApiModelProperty(value = "停用",example = "否")
    private String unit_del;

}
