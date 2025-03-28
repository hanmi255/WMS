package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.sql.Blob;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * InnoDB free: 600064 kB; (`departid`) REFER `jeecg/t_s_depart
 * </p>
 *
 * @author henry
 * @since 2025-02-21
 */
@Getter
@Setter
@TableName("t_s_base_user")
public class TSBaseUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 同步流程
     */
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
     * 真实名字
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
     * 部门ID
     */
    private String departid;

    /**
     * 删除状态
     */
    private Integer deleteFlag;

    /**
     * 微信openid
     */
    private String wxopenid;


}
