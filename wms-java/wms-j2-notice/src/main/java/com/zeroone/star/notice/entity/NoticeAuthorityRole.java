package com.zeroone.star.notice.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * <p>
 * 公告授权角色表
 * </p>
 *
 * @author 恒
 */
@Data
@TableName("t_s_notice_authority_role")
public class NoticeAuthorityRole {
    //编号
    private String id;

    //公告id
    private String noticeId;

    //授权角色id
    private String userId;
}
