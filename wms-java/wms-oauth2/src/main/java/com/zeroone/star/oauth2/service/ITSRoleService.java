package com.zeroone.star.oauth2.service;

import com.zeroone.star.oauth2.entity.TSRole;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 角色信息 服务类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
public interface ITSRoleService extends IService<TSRole> {
    /**
     * 获取菜单对应的角色
     */
    List<TSRole> listRoleByFunctionUrl(String functionurl);

    /**
     * 根据用户id获取角色n
     */
    List<TSRole> listRoleByUserId(String id);


}
