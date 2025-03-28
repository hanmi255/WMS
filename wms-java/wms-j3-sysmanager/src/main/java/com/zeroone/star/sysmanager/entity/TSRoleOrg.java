package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * 仓库管理App用户实体类
 */
@Data
@TableName("t_s_role_org")
public class TSRoleOrg implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    private String id;

    /**
     * 机构id
     */
    private String orgId;

    /**
     * 角色id
     */
    private String roleId;
}
