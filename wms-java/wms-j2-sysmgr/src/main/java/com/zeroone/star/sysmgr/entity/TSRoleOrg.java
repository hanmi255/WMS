package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

@Data
@TableName("t_s_role_org")
public class TSRoleOrg  implements Serializable {
    private static final long serialVersionUID = 1L;
    /**
     * 主键
     */
    private String id;
    /**
     * 机构ID
     */
    private String orgId;
    /**
     * 角色ID
     */
    private String roleId;
}
