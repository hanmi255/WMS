package com.zeroone.star.notice.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

/**
 * <p>
 * 公告已读用户
 * </p>
 *
 * @author 恒
 */
@Data
@TableName("t_s_notice_read_user")
public class NoticeReadUser {
    //编号
    private String id;

    //公告id
    private String noticeId;

    //用户id
    private String userId;

    //是否阅读
    private Integer isRead;

    //是否删除
    private Integer delFlag;

    //创建时间
    private Date createTime;

}
