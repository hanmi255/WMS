package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.util.Date;
import lombok.Data;

/**
 * InnoDB free: 599040 kB; (`id`) REFER `jeecg/t_s_base_user`(`
 * @TableName t_s_user
 */
@TableName(value ="t_s_user")
@Data
public class TSUser implements Serializable {
    /**
     * id
     */
    @TableId
    private String id;

    /**
     * 邮箱
     */
    private String email;

    /**
     * 手机号
     */
    private String mobilephone;

    /**
     * 办公座机
     */
    private String officephone;

    /**
     * 签名文件
     */
    private String signaturefile;

    /**
     * 修改人
     */
    private String updateName;

    /**
     * 修改时间
     */
    private Date updateDate;

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
    private Date createDate;

    /**
     * 创建人id
     */
    private String createBy;

    /**
     *
     */
    private String userType;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}
