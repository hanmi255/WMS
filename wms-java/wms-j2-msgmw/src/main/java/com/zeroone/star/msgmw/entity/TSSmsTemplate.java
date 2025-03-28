package com.zeroone.star.msgmw.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

/**
 * 消息模板实体类
 */
@TableName("t_s_sms_template")
@Data
public class TSSmsTemplate {
    // 主键
    private String id;
    // 模板类型
    private String templateType;
    // 模板名称
    private String templateName;
    // 模板内容
    private String templateContent;
    // 创建日期
    private Date createDate;
    // 创建人登录名称
    private String createBy;
    // 创建人名称
    private String createName;
    // 更新日期
    private Date updateDate;
    // 更新人登录名称
    private String updateBy;
    // 更新人名称
    private String updateName;
}

