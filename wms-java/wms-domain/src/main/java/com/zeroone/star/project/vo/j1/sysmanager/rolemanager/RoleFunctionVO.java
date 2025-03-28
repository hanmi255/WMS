package com.zeroone.star.project.vo.j1.sysmanager.rolemanager;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.TableField;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

@Getter
@Setter
@Data
@TableName("t_s_function")
public class RoleFunctionVO implements Serializable {
    /**
     * 主键 ID（varchar(32)）
     */
    @TableField("ID")
    private String id;  // 主键

    /**
     * 菜单等级（smallint）
     */
    @TableField("functionlevel")
    private Short functionLevel;  // 菜单等级

    /**
     * 菜单名称（varchar(50)）
     */
    @TableField("functionname")
    private String functionName;  // 菜单名称

    /**
     * 排序（varchar(255)）
     */
    @TableField("functionorder")
    private String functionOrder;  // 排序

    /**
     * URL（varchar(500)）
     */
    @TableField("functionurl")
    private String functionUrl;  // URL

    /**
     * 父菜单ID（varchar(32)）
     */
    @TableField("parentfunctionid")
    private String parentFunctionId;  // 父菜单ID

    /**
     * 图标ID（varchar(32)）
     */
    @TableField("iconid")
    private String iconId;  // 图标ID



}