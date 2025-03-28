package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

import java.sql.Timestamp;

/**
 * 仓库管理App用户实体类
 */
@Data
@TableName("wms_app_user")
public class WmsAppUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
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
    private Timestamp createDate;

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
    private Timestamp updateDate;

    /**
     * 所属部门
     */
    private String sysOrgCode;

    /**
     * 所属公司
     */
    private String sysCompanyCode;

    /**
     * 用户编号
     */
    private String appuserCode;

    /**
     * 用户名称
     */
    private String appuserName;

    /**
     * 角色ID
     */
    private String approleId;

    /**
     * 角色编号
     */
    private String approleCode;

    /**
     * 角色名称
     */
    private String approleName;

}
