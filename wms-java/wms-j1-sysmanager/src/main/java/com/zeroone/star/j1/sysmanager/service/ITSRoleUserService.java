package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleUserDTO;
import com.zeroone.star.j1.sysmanager.entity.TSRoleUser;

/**
 * <p>
 * 角色用户 服务类
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
public interface ITSRoleUserService extends IService<TSRoleUser> {

    /**
     * 添加角色用户
     * @param roleUserDTO 新增角色用户信息（添加单个用户）
     * @return true表示添加成功
     */
    Boolean addRoleUser(RoleUserDTO roleUserDTO);

    /**
     * 删除角色用户
     * @param roleUserDTO 删除角色用户信息
     * @return true表示删除成功
     */
    Boolean deleteRoleUser(RoleUserDTO roleUserDTO);

    /**
     * 查询是否存在该角色用户
     * @param roleUserDTO 查询角色用户信息
     * @return 返回查询到的角色用户
     */
    TSRoleUser selectRoleUser(RoleUserDTO roleUserDTO);
}
