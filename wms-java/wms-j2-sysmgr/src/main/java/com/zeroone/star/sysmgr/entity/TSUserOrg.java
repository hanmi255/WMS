package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author henry
 * @since 2025-02-21
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
