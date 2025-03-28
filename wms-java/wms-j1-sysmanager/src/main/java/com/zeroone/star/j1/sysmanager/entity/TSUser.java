package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * InnoDB free: 599040 kB; (`id`) REFER `jeecg/t_s_base_user`(`
 * </p>
 *
 * @author PingShui
 * @since 2025-02-24
 * @author halo
 * @since 2025-03-01
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
    @TableField("update_name")
    private String updateName;

    /**
     * 修改时间
     */
    @TableField("update_date")
    private LocalDateTime updateDate;

    /**
     * 修改人id
     */
    @TableField("update_by")
    private String updateBy;

    /**
     * 创建人
     */
    @TableField("create_name")
    private String createName;

    /**
     * 创建时间
     */
    @TableField("create_date")
    private LocalDateTime createDate;

    /**
     * 创建人id
     */
    @TableField("create_by")
    private String createBy;

    @TableField("user_type")
    private String userType;


}
