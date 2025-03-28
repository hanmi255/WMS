package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * @program: wms-java
 * @description: 分类数据实体
 * @author: Hao
 **/
@Getter
@Setter
@TableName("t_s_typegroup")
public class TypeGroup implements Serializable {
    @TableId(value = "ID",type = IdType.AUTO)
    private String id;

    @TableField("typegroupcode")
    private String typeGroupCode;

    @TableField("typegroupname")
    private String typeGroupName;

    @TableField("create_date")
    private Timestamp createDate;

    @TableField("create_name")
    private String createName;
}
