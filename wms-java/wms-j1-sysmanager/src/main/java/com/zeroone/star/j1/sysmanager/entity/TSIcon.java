package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.IdType;
import lombok.Getter;
import lombok.Setter;
import java.io.Serializable;

@Getter
@Setter
@TableName("t_s_icon") // 指定数据库表名
public class TSIcon implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID (主键)
     */
    @TableId(value = "ID", type = IdType.ASSIGN_UUID)
    private String id;

    /**
     * 图片后缀 (如 .png, .jpg)
     */
    @TableField("extend")
    private String extend;

    /**
     * 图标类型 (可能表示 CSS 类)
     */
    @TableField("iconclas") // 注意数据库字段名为 `iconclas`
    private String iconclas;

    /**
     * 图片流内容 (二进制数据)
     */
    @TableField("content")
    private byte[] content;

    /**
     * 图标名称
     */
    @TableField("name")
    private String name;

    /**
     * 存储路径 (如果 `content` 存二进制图片，此字段可能为空)
     */
    @TableField("path")
    private String path;

    /**
     * 图标类型 (1: 系统图标, 2: 菜单图标, 3: 桌面图标)
     */
    @TableField("type")
    private Integer type;
}
