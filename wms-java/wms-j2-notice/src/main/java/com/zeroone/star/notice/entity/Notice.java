package com.zeroone.star.notice.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;
import java.util.Date;

/**
 * <p>
 * 公告
 * </p>
 *
 * @author 恒
 */

@Data
@TableName("t_s_notice")
public class Notice {
    //编号
    private String id;

    //通知标题
    private String noticeTitle;

    //通知公告内容
    private String noticeContent;

    //通知公告类型(1:通知,2:公告)
    private String noticeType;

    //通告授权级别（1:全员，2:角色，3:用户）
    private String noticeLevel;

    //阅读期限
    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd HH:mm:ss")
    private Date noticeTerm;

    //创建者
    private String createUser;

    //创建时间
    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd HH:mm:ss")
    private Date createTime;

}
