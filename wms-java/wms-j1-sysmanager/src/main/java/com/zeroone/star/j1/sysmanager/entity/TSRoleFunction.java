package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * InnoDB free: 599040 kB; (`roleid`) REFER `jeecg/t_s_role`(`I
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Getter
@Setter
@Data
@TableName("t_s_role_function")
public class TSRoleFunction implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 页面控件权限编码
     */
    private String operation;

    /**
     * 菜单ID
     */
    private String functionid;

    /**
     * 角色ID
     */
    private String roleid;

    /**
     * 数据权限规则ID
     */
    private String datarule;


}
