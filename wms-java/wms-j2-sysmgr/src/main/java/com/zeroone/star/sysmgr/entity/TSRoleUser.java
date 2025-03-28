package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * InnoDB free: 599040 kB; (`userid`) REFER `jeecg/t_s_user`(`i
 * @TableName t_s_role_user
 */
@TableName(value ="t_s_role_user")
@Data
public class TSRoleUser implements Serializable {
    /**
     * ID
     */
    @TableId(type = IdType.ASSIGN_UUID)
    private String id;

    /**
     * 角色ID
     */
    private String roleid;

    /**
     * 用户ID
     */
    private String userid;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
