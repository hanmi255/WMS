package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@TableName("t_s_type")
public class Type {
    @TableId(value = "ID", type = IdType.ASSIGN_UUID)
    private String id; // 修正为Long类型

    @TableField("typecode")
    private String typeCode; // 小驼峰命名

    @TableField("typename")
    private String typeName;

    @TableField("typepid")
    private String typePid; // 修正字段名

    @TableField("typegroupid")
    private String typeGroupId;

    @TableField("create_date")
    private LocalDateTime createDate;

    @TableField("create_name")
    private String createName;
}
