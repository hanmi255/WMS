package com.zeroone.star.notice.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * <p>
 * 公告授权用户表
 * </p>
 *
 * @author 恒
 */
@Data
@TableName("t_s_notice_authority_user")
public class NoticeAuthorityUser {
    //编号
    private String id;

    //公告id
    private String noticeId;

    //用户id
    private String userId;
}
