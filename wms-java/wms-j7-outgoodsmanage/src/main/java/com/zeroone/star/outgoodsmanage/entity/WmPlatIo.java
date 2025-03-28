package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

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
@Getter
@Setter
@TableName("wm_plat_io")
public class WmPlatIo implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
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
     * 车号
     */
    private String carno;

    /**
     * 单据编号
     */
    private String docId;

    /**
     * 月台编号
     */
    private String platId;

    /**
     * 进入时间
     */
    private LocalDateTime inData;

    /**
     * 驶出时间
     */
    private LocalDateTime outData;

    /**
     * 月台状态
     */
    private String platSta;

    /**
     * 备注
     */
    private String platBeizhu;

    /**
     * 计划进入时间
     */
    private LocalDateTime planIndata;

    /**
     * 计划驶出时间
     */
    private LocalDateTime planOutdata;

    /**
     * 月台操作
     */
    private String platOper;


}
