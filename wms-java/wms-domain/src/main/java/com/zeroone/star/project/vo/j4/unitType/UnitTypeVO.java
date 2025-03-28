package com.zeroone.star.project.vo.j4.unitType;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述:单位类型响应对象
 * </p>
 *
 * @author Dorain
 * @version 1.0.0
 * @since 2025/2/23
 */
@Getter
@Setter
@ToString
public class UnitTypeVO {
    @ApiModelProperty(value = "单位类型ID", required = true, example = "45612165642136")
    private String id;

    @ApiModelProperty(value = "单位类型代码", example = "10005")
    private String unitTypeCode;

    @ApiModelProperty(value = "单位类型名称", example = "件")
    private String unitTypeName;

    @ApiModelProperty(value = "创建人名称", example = "张三")
    private String createName;

    @ApiModelProperty(value = "创建人登录名称", example = "zhangsan")
    private String createBy;

    @ApiModelProperty(value = "创建日期", example = "2025-02-23T10:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "更新人名称", example = "李四")
    private String updateName;

    @ApiModelProperty(value = "更新人登录名称", example = "lisi")
    private String updateBy;

    @ApiModelProperty(value = "更新日期", example = "2025-02-23 13:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd'T'HH:mm:ss")
    private LocalDateTime updateDate;

    @ApiModelProperty(value = "所属部门", example = "部门代码")
    private String sysOrgCode;

    @ApiModelProperty(value = "所属公司", example = "公司代码")
    private String sysCompanyCode;
}
