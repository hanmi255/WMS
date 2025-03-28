package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * 通告授权角色表
 * @TableName t_s_notice_authority_role
 */
@TableName(value ="t_s_notice_authority_role")
@Data
public class TSNoticeAuthorityRole implements Serializable {
    /**
     * ID
     */
    @TableId(type = IdType.ASSIGN_UUID)
    private String id;

    /**
     * 通告ID
     */
    private String noticeId;

    /**
     * 授权角色ID
     */
    private String roleId;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
