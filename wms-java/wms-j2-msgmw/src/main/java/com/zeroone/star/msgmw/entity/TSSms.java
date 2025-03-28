package com.zeroone.star.msgmw.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

/**
 * <p>
 * 消息模板配置
 * </p>
 *
 * @author Maple
 * @since 2025-02-23
 */
@Data
@NoArgsConstructor
@TableName("t_s_sms")
public class TSSms {
    // 消息ID
    private String id;
    // 创建人
    private String createName;
    // 创建人登录名称
    private String createBy;
    // 创建日期
    private String createDate;
    // 更新人
    private String updateName;
    // 更新人登录名称
    private String updateBy;
    // 更新日期
    private String updateDate;
    // 标题
    private String esTitle;
    // 类型
    private String esType;
    // 发送人
    private String esSender;
    // 接收人
    private String esReceiver;
    // 发送内容
    private String esContent;
    // 发送时间
    private String esSendtime;
    // 备注
    private String remark;
    // 发送状态
    private String esStatus;
}
