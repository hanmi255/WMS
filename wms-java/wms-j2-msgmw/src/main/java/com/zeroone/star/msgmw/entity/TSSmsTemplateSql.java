package com.zeroone.star.msgmw.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 消息模板配置
 * </p>
 *
 * @author qunzhong
 * @since 2025-02-21
 */
@Getter
@Setter
@TableName("t_s_sms_template_sql")
public class TSSmsTemplateSql implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 配置CODE
     */
    private String code;

    /**
     * 配置名称
     */
    private String name;

    /**
     * 业务SQLID
     */
    private String sqlId;

    /**
     * 消息模本ID
     */
    private String templateId;

    /**
     * 创建日期
     */
    private LocalDateTime createDate;

    /**
     * 创建人登录名称
     */
    private String createBy;

    /**
     * 创建人名称
     */
    private String createName;

    /**
     * 更新日期
     */
    private LocalDateTime updateDate;

    /**
     * 更新人登录名称
     */
    private String updateBy;

    /**
     * 更新人名称
     */
    private String updateName;


}
