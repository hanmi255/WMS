package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * @program: wms-java
 * @description: 多语言数据实体
 * @author: hamhuo
 **/

@Setter
@Getter
@TableName("t_s_muti_lang")
public class MultiLang implements Serializable {

    private static final long serialVersionUID = 5L;

    @TableId(value = "id", type = IdType.ASSIGN_ID)
    private String id;

    private String langCode;

    private String langKey;

    private String langContext;

    private String createBy;

    private String createName;

    private Timestamp createDate;

    private String updateBy;

    private Timestamp updateDate;

    private String updateName;
}