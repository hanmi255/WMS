package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;

/**
 * 仓库管理App用户实体类
 */
@Data
@TableName("t_s_user_org")
public class TSUserOrg implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键ID
     */
    private String id;

    /**
     * 用户id
     */
    private String userId;

    /**
     * 机构id
     */
    private String orgId;


}
