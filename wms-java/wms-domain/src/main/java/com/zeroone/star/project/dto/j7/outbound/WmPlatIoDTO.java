package com.zeroone.star.project.dto.j7.outbound;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 月台计划
 * </p>
 *
 * @author lenyan
 * @since 2025-02-21
 */
@Data
@ApiModel("月台计划")
public class WmPlatIoDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @ApiModelProperty(value = "主键", example = "123e4567-e89b-12d3-a456-426614174000")
    private String id;

    /**
     * 创建人名称
     */
    @ApiModelProperty(value = "创建人名称", example = "张三")
    private String createName;

    /**
     * 创建人登录名称
     */
    @ApiModelProperty(value = "创建人登录名称", example = "zhangsan")
    private String createBy;

    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期", example = "2025-02-21T13:51:00")
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    @ApiModelProperty(value = "更新人名称", example = "李四")
    private String updateName;

    /**
     * 更新人登录名称
     */
    @ApiModelProperty(value = "更新人登录名称", example = "lisi")
    private String updateBy;

    /**
     * 更新日期
     */
    @ApiModelProperty(value = "更新日期", example = "2025-02-21T14:30:00")
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    @ApiModelProperty(value = "所属部门", example = "技术部")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ApiModelProperty(value = "所属公司", example = "01星球有限公司")
    private String sysCompanyCode;

    /**
     * 车号
     */
    @ApiModelProperty(value = "车号", example = "京A88888")
    private String carno;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "DOC123456")
    private String docId;

    /**
     * 月台编号
     */
    @ApiModelProperty(value = "月台编号", example = "PLAT001")
    private String platId;

    /**
     * 进入时间
     */
    @ApiModelProperty(value = "进入时间", example = "2025-02-21T13:00:00")
    private LocalDateTime inData;

    /**
     * 驶出时间
     */
    @ApiModelProperty(value = "驶出时间", example = "2025-02-21T15:00:00")
    private LocalDateTime outData;

    /**
     * 月台状态
     */
    @ApiModelProperty(value = "月台状态", example = "占用中")
    private String platSta;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "无")
    private String platBeizhu;

    /**
     * 计划进入时间
     */
    @ApiModelProperty(value = "计划进入时间", example = "2025-02-21T12:00:00")
    private LocalDateTime planIndata;

    /**
     * 计划驶出时间
     */
    @ApiModelProperty(value = "计划驶出时间", example = "2025-02-21T16:00:00")
    private LocalDateTime planOutdata;

    /**
     * 月台操作
     */
    @ApiModelProperty(value = "月台操作", example = "装卸货")
    private String platOper;
}
