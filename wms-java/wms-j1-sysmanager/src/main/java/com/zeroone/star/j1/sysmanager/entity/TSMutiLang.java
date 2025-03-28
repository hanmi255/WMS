package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.*;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 多语言映射实体类
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Getter
@Setter
@TableName("t_s_muti_lang")
public class TSMutiLang implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @TableId(value = "id", type = IdType.ASSIGN_UUID) // UUID 方式生成主键
    private String id;

    /**
     * 语言主键
     */
    @TableField("lang_key")
    private String langKey;

    /**
     * 内容
     */
    @TableField("lang_context")
    private String langContext;

    /**
     * 语言
     */
    @TableField("lang_code")
    private String langCode;

    /**
     * 创建时间
     */
    @TableField(value = "create_date", fill = FieldFill.INSERT)
    private LocalDateTime createDate;

    /**
     * 创建人编号
     */
    @TableField("create_by")
    private String createBy;

    /**
     * 创建人姓名
     */
    @TableField("create_name")
    private String createName;

    /**
     * 更新日期
     */
    @TableField(value = "update_date", fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateDate;

    /**
     * 更新人编号
     */
    @TableField("update_by")
    private String updateBy;

    /**
     * 更新人姓名
     */
    @TableField("update_name")
    private String updateName;
}
