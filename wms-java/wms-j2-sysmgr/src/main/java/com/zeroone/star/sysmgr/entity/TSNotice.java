package com.zeroone.star.sysmgr.entity;

import cn.easyes.annotation.IndexField;
import cn.easyes.annotation.IndexId;
import cn.easyes.annotation.IndexName;
import cn.easyes.common.constants.Analyzer;
import cn.easyes.common.enums.FieldType;
import cn.easyes.common.enums.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Data;
import org.springframework.data.mongodb.core.mapping.Document;
import org.springframework.format.annotation.DateTimeFormat;

/**
 * 通知公告表
 * @TableName t_s_notice
 */
@TableName(value ="t_s_notice")
@Data
@IndexName(value = "ee_tsnotice")
public class TSNotice implements Serializable {
    /**
     * ID
     */
    @TableId
    @IndexId(type = IdType.CUSTOMIZE)
    private String id;

    /**
     * 通知标题
     */
    private String noticeTitle;

    /**
     * 通知公告内容
     */
    @IndexField(fieldType = FieldType.TEXT,analyzer = Analyzer.IK_MAX_WORD)
    private String noticeContent;

    /**
     * 通知公告类型（1：通知，2:公告）
     */
    private String noticeType;

    /**
     * 通告授权级别（1:全员，2：角色，3：用户）
     */
    private String noticeLevel;

    /**
     * 阅读期限
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime noticeTerm;

    /**
     * 创建者
     */
    private String createUser;

    /**
     * 创建时间
     */
    private LocalDateTime createTime;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
