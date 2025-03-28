package com.zeroone.star.j1.sysmanager.entity;

import cn.hutool.core.date.DateTime;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

@Getter
@Setter
public class TSUserManage implements Serializable {
    /**
     * id
     */
    private String id;
    /**
     * 用户账号
     */
    private  String username;
    /**
     * 用户名称 对应数据库中的用户Key
     */
    private String userKey;

    /**
     * 部门名
     */
    private String departname;
    /**
     * 角色名称
     */
    private String roleName;
    /**
     * 创建时间
     */
    private LocalDateTime createDate;
    /**
     * 状态
     */
    private Integer status;
}
