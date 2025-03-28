package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import java.io.Serializable;
import java.sql.Blob;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * InnoDB free: 600064 kB; (`departid`) REFER `jeecg/t_s_depart
 * </p>
 * 用户表
 *
 * @author halo
 * @since 2025-02-23
 * @author PingShui
 * @since 2025-02-24
 */
@Getter
@Setter
@TableName("t_s_base_user")
@ToString
public class TSBaseUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    @TableId
    private String id;

    /**
     * 同步流程（数据库无此字段）
     */
    @TableField("activitiSync")
    private Integer activitiSync;

    /**
     * 浏览器
     */
    private String browser;

    /**
     * 密码
     */
    private String password;

    /**
     * 用户名称
     */
    private String realname;

    /**
     * 签名
     */
    private Blob signature;

    /**
     * 有效状态
     */
    private Integer status;

    /**
     * 用户KEY
     */
    private String userkey;

    /**
     * 用户账号
     */
    private String username;

    /**
     * 部门ID（对应数据库字段departid）
     */
    @TableField("departid")
    private String departId;

    /**
     * 删除状态（对应数据库字段delete_flag）
     */
    @TableField("delete_flag")
    private Integer deleteFlag;

    /**
     * 微信openid（对应数据库字段wxopenid）
     */
    @TableField("wxopenid")
    private String wxOpenId;

}
