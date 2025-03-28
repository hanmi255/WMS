package com.zeroone.star.project.j1.sysmanager.usermanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.DepartmentDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserListDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.DepartmentQuery;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.UserManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

/**
 *  白纸懒洋洋 接口位置调整
 * @author 李云毅
 * @version 1.0.0
 * 2025/3/1
 */
public interface UserManage2Apis {

    /**
     * 获取组织名称树
     * @return 组织名称树
     */
    JsonVO<PageDTO<DepartmentDTO>> queryDepartmentAll(DepartmentQuery query);

    /**
     * 通过角色名称查询
     * @return 角色
     */
    JsonVO<PageDTO<RoleListDTO>> queryRoleByRoleName(@RequestBody RoleManagementQuery roleName);

    /**
     * 查询用户列表
     * @return 用户列表
     */
    JsonVO<PageDTO<UserListDTO>> queryRole(@RequestBody UserManagementQuery userQuery);

}
