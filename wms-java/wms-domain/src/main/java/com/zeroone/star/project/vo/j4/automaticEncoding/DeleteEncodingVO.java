package com.zeroone.star.project.vo.j4.automaticEncoding;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author qiaozhi
 * @title NumberingTypeVO
 * @date 2025/2/24
 * @description 编号类型 VO
 */

@ToString
@Getter
@Setter
@ApiModel(value = "DeleteEncodingVO", description = "删除自动编码规则")
public class DeleteEncodingVO {

    @ApiModelProperty(value = "编号类型 ID", example = "402881b2653ba3dd01653bc236250007")
    private String id;

    @ApiModelProperty(value = "创建人名称", example = "admin")
    private String create_name;

    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    private String create_by;

    @ApiModelProperty(value = "创建日期", example = "2018-08-15 12:05:08")
    private String create_date;

    @ApiModelProperty(value = "更新人名称", example = "admin")
    private String update_name;

    @ApiModelProperty(value = "更新人登录名称", example = "admin")
    private String update_by;

    @ApiModelProperty(value = "更新日期", example = "2018-08-15 12:05:08")
    private String update_date;

    @ApiModelProperty(value = "所属部门", example = "A04")
    private String sys_org_code;

    @ApiModelProperty(value = "所属公司", example = "A04")
    private String sys_company_code;

    @ApiModelProperty(value = "编号类型代码", example = "SNRO01")
    private String snro_type_code;

    @ApiModelProperty(value = "组织机构", example = "A04")
    private String snro_org;

    @ApiModelProperty(value = "前缀", example = "ORD")
    private String snro_findex;

    @ApiModelProperty(value = "分隔符", example = "-")
    private String snro_split;

    @ApiModelProperty(value = "年位数", example = "4")
    private Integer snro_year;

    @ApiModelProperty(value = "月位数", example = "2")
    private Integer snro_month;

    @ApiModelProperty(value = "日位数", example = "2")
    private Integer snro_day;

    @ApiModelProperty(value = "序号位数", example = "5")
    private Integer snro_seri;

    @ApiModelProperty(value = "示例号码", example = "ORD-2025-02-24-00001")
    private String snro_exp;

}
