package com.zeroone.star.j1.sysmanager.service;

import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionAssignmentDTO;

import com.zeroone.star.j1.sysmanager.entity.TSFunction;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionAssignmentDTO;

/**
 * <p>
 * InnoDB free: 600064 kB; (`parentfunctionid`) REFER `jeecg/t_ 服务类
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
public interface RoleResourseService {
    public RoleFunctionAssignmentDTO getRoleFunction(String langType);

    public RoleFunctionAssignmentDTO getRoleFunctionAssignment(String langType, String roleId);

    public String setRoleFunction(RoleFunctionAssignmentDTO roleFunctionAssignmentDTO);
}
