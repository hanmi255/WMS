package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * 通告已读用户表
 * @TableName t_s_notice_read_user
 */
@TableName(value ="t_s_notice_read_user")
@Data
public class TSNoticeReadUser implements Serializable {
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
     * 用户ID
     */
    private String userId;

    /**
     * 是否已阅读
     */
    private Integer isRead;

    /**
     * 是否已删除
     */
    private Integer delFlag;

    /**
     * 创建时间
     */
    private Date createTime;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
