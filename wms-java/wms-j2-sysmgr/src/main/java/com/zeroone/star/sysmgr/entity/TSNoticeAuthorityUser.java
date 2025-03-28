package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Data;

/**
 * 通告授权用户表
 * @TableName t_s_notice_authority_user
 */
@TableName(value ="t_s_notice_authority_user")
@Data
public class TSNoticeAuthorityUser implements Serializable {
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
     * 授权用户ID
     */
    private String userId;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
