package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 系统日志
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
@Getter
@Setter
@TableName("t_s_log")
public class TSLog implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    private String id;

    /**
     * 浏览器
     */
    private String broswer;

    /**
     * 日志内容
     */
    private String logcontent;

    /**
     * 日志级别
     */
    private Integer loglevel;

    /**
     * IP
     */
    private String note;

    /**
     * 操作时间
     */
    private LocalDateTime operatetime;

    /**
     * 操作类型
     */
    private Integer operatetype;

    /**
     * 用户ID
     */
    private String userid;


}
