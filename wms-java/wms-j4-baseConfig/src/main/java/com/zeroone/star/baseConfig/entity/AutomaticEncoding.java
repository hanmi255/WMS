package com.zeroone.star.baseConfig.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author lzm
 * @since 2025-02-22
 */
@Getter
@Setter
@TableName("ba_snro")
public class AutomaticEncoding implements Serializable {

    private static final long serialVersionUID = 1L;

    private String id;

    /**
     * 创建人名称
     */
    private String createName;

    /**
     * 创建人登录名称
     */
    private String createBy;

    /**
     * 创建日期
     */
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    private String updateName;

    /**
     * 更新人登录名称
     */
    private String updateBy;

    /**
     * 更新日期
     */
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    private String sysOrgCode;

    /**
     * 所属公司
     */
    private String sysCompanyCode;

    /**
     * 编号类型
     */
    private String snroTypeCode;

    /**
     * 组织机构
     */
    private String snroOrg;

    /**
     * 前缀
     */
    private String snroFindex;

    /**
     * 分隔符
     */
    private String snroSplit;

    /**
     * 年位数
     */
    private String snroYear;

    /**
     * 月位数
     */
    private String snroMonth;

    /**
     * 日位数
     */
    private String snroDay;

    /**
     * 序号位数
     */
    private String snroSeri;

    /**
     * 示例号码
     */
    private String snroExp;


}
