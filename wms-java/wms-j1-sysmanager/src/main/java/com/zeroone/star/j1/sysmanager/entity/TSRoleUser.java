package com.zeroone.star.j1.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import java.io.Serializable;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

/**
 * <p>
 * InnoDB free: 599040 kB; (`userid`) REFER `jeecg/t_s_user`(`i
 * </p>
 *
 * @author halo
 * @since 2025-03-02
 * @author PingShui
 * @since 2025-02-24
 */
@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@TableName("t_s_role_user")
public class TSRoleUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 角色ID
     */
    private String roleid;

    /**
     * 用户ID
     */
    private String userid;


}
