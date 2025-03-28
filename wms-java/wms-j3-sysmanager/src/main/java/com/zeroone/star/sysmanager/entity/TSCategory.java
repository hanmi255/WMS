package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.project.utils.tree.TreeNode;
import lombok.Data;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * 分类管理实体类
 */

@Data
@TableName("t_s_category")
public class TSCategory implements Serializable {


    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 图标ID
     */
    private String iconId;

    /**
     * 类型编码
     */
    private String code;

    /**
     * 类型名称
     */
    private String name;

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
     * 上级ID
     */
    private String parentId;

    /**
     * 机构
     */
    private String sysOrgCode;

    /**
     * 公司
     */
    private String sysCompanyCode;

    /**
     * 父邮编
     */
    private String parentCode;
}



