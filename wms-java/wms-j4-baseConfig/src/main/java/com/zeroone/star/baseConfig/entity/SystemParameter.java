package com.zeroone.star.baseConfig.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author szq
 * @since 2025-02-23
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@TableName("ba_sys_conf")
@ApiModel(value="BaSysConf对象", description="系统参数表格")
public class SystemParameter implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.ASSIGN_UUID)
    private String id;

    @ApiModelProperty(value = "创建人名称")
    private String createName;

    @ApiModelProperty(value = "创建人登录名称")
    private String createBy;

    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "更新人名称")
    private String updateName;

    @ApiModelProperty(value = "更新人登录名称")
    private String updateBy;

    @ApiModelProperty(value = "更新日期")
    private LocalDateTime updateDate;

    @ApiModelProperty(value = "所属部门")
    private String sysOrgCode;

    @ApiModelProperty(value = "所属公司")
    private String sysCompanyCode;

    @ApiModelProperty(value = "系统参数类型")
    private String sysConfType;

    @ApiModelProperty(value = "业务操作环节")
    private String sysConfStep;

    @ApiModelProperty(value = "组织")
    private String sysConfOrg;

    @ApiModelProperty(value = "合作伙伴")
    private String sysConfPartner;

    @ApiModelProperty(value = "参数1")
    private String sysPara1;

    @ApiModelProperty(value = "参数2")
    private String sysPara2;

    @ApiModelProperty(value = "参数3")
    private String sysPara3;

    @ApiModelProperty(value = "备注")
    private String sysConfText;


}
