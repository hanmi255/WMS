package com.zeroone.star.project.components.user;

import lombok.Builder;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：用户数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@Builder
public class UserDTO {
    /**
     * 用户编号 t_s_base_user的id为字符串类型
     */
    private String id;
    /**
     * 用户名称
     */
    private String username;
    /**
     * 用户姓名
     */
    private String realname;
    /**
     * 所属部门
     */
    private String orgCode;
    /**
     * 所属公司
     */
    private String companyCode;
    /**
     * 是否启用
     */
    private Byte isEnabled;
    /**
     * 用户拥有角色列表
     */
    private List<String> roles;
}
