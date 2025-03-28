package com.zeroone.star.project.dto.j4.automaticEncoding;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * @ClassName: AutomaticEncodingDTO
 * @Description:
 * @Author: lzm
 * @Date: 2025-02-23 00:18
 */
@Data
@Getter
@Setter
@ToString
public class AutomaticEncodingDTO {
    private static final long serialVersionUID = 1L;

    private String id;

    /**
     * 创建人名称
     */
    @ApiModelProperty(value = "创建人名称")
    private String createName;

    /**
     * 创建人登录名称
     */
    @ApiModelProperty(value = "创建人登录名称")
    private String createBy;

    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    @ApiModelProperty(value = "更新人名称")
    private String updateName;

    /**
     * 更新人登录名称
     */
    @ApiModelProperty(value = "更新人登录名称")
    private String updateBy;

    /**
     * 更新日期
     */
    @ApiModelProperty(value = "更新日期")
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    @ApiModelProperty(value = "所属部门")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ApiModelProperty(value = "所属公司")
    private String sysCompanyCode;


    /*------------------------------------------**/
    /**
     * 编号类型
     */

    @ApiModelProperty(value = "编号类型",required = true)
    private String snroTypeCode;

    /**
     * 组织机构
     */
    @ApiModelProperty(value = "组织机构",required = true)
    private String snroOrg;

    /**
     * 前缀
     */
    @ApiModelProperty(value = "前缀",required = true)
    private String snroFindex;

    /**
     * 分隔符
     */
    @ApiModelProperty(value = "分隔符",required = true)
    private String snroSplit;

    /**
     * 年位数
     */
    @ApiModelProperty(value = "年位数",required = true)
    private String snroYear;

    /**
     * 月位数
     */
    @ApiModelProperty(value = "月位数",required = true)
    private String snroMonth;

    /**
     * 日位数
     */
    @ApiModelProperty(value = "日位数",required = true)
    private String snroDay;

    /**
     * 序号位数
     */
    @ApiModelProperty(value = "序号位数",required = true)
    private String snroSeri;

    /**
     * 示例号码
     */
    @ApiModelProperty(value = "示例号码",required = true)
    private String snroExp;
}
