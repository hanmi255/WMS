package com.zeroone.star.j1.sysmanager.entity;

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
 * @since 2025-03-01
 */
@Getter
@Setter
@TableName("t_s_user_org")
public class TSUserOrg implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * id
     */
    private String id;

    /**
     * 用户id
     */
    private String userId;

    /**
     * 部门id
     */
    private String orgId;


}
