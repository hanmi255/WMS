package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 系统用户扩展
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Getter
@Setter
@TableName("t_s_user")
public class TSUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    private String id;

    /**
     * 邮箱
     */
    private String email;

    /**
     * 手机号
     */
    @TableField("mobilePhone")
    private String mobilePhone;

    /**
     * 办公座机
     */
    @TableField("officePhone")
    private String officePhone;

    /**
     * 签名文件
     */
    @TableField("signatureFile")
    private String signatureFile;

    /**
     * 修改人
     */
    private String updateName;

    /**
     * 修改时间
     */
    private LocalDateTime updateDate;

    /**
     * 修改人id
     */
    private String updateBy;

    /**
     * 创建人
     */
    private String createName;

    /**
     * 创建时间
     */
    private LocalDateTime createDate;

    /**
     * 创建人id
     */
    private String createBy;

    private String userType;


}
