package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author halo
 * @since 2025-03-02
 */
@Getter
@Setter
@TableName("t_s_depart")
public class TSDepart implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    @TableId("ID")
    private String id;

    /**
     * 部门名称
     */
    private String departname;

    /**
     * 描述
     */
    private String description;

    /**
     * 父部门ID
     */
    private String parentdepartid;

    /**
     * 机构编码
     */
    @TableField("org_code")
    private String orgCode;

    /**
     * 机构类型
     */
    @TableField("org_type")
    private String orgType;

    /**
     * 手机号
     */
    private String mobile;

    /**
     * 传真
     */
    private String fax;

    /**
     * 地址
     */
    private String address;

    /**
     * 排序
     */
    @TableField("depart_order")
    private String departOrder;


}
