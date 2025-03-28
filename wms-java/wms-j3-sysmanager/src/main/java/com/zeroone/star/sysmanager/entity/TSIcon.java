package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.sql.Blob;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 系统图标
 * </p>
 *
 * @author Vast
 * @since 2025-02-21
 */
@Getter
@Setter
@TableName("t_s_icon")
public class TSIcon implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    private String id;

    /**
     * 图片后缀
     */
    private String extend;

    /**
     * 类型
     */
    private String iconclas;

    /**
     * 图片流内容
     */
    private Blob content;

    /**
     * 名字
     */
    private String name;

    /**
     * 路径
     */
    private String path;

    /**
     * 类型 1系统图标/2菜单图标/3桌面图标
     */
    private Integer type;


}
