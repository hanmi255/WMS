package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j1.sysmanager.entity.TSRole;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langyanyan
 * @since 2025-03-01
 */
public interface ITSRoleNameService extends IService<TSRole> {
    /**
     * 根据条件查询角色
     * @param query
     * @return 查询结果
     */
    PageDTO<RoleListDTO> listRoleName(RoleManagementQuery query);

}
