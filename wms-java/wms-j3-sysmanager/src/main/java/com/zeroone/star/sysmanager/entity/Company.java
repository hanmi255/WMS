package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * 仓库管理App用户实体类
 */
@Data
@TableName("bs_comp")
public class Company implements Serializable {

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
     * 所属部门code
     */
    private String sysOrgCode;

    /**
     * 所属公司code
     */
    private String sysCompanyCode;
}
