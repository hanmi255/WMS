package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * @program: wms-java
 * @description: 更新记录表实体
 * @author: hamhuo
 **/
@Getter
@Setter
@TableName("t_s_muti_lang")
public class MultiLangUpdate implements Serializable {
    private static final long serialVersionUID = 5L;

    private String id;

    private String langCode;

    private String langKey;

    private String langContext;

    private String updateBy;

    private Timestamp updateDate;

    private String updateName;
}