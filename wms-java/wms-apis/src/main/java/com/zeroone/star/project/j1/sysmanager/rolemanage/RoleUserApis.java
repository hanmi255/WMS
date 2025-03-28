package com.zeroone.star.project.j1.sysmanager.rolemanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleUserDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleUserQuery;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleUserVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.UserVO;

/**
 *
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/19
 */
public interface RoleUserApis {

    /**
     * 获取用户列表（查询不属于该角色的用户）（条件+分页）
     * @param userQuery 查询条件
     * @return 查询结果 分页显示
     */
    JsonVO<PageDTO<UserVO>> queryUserList(UserQuery userQuery);

    /**
     * 获取角色用户列表（查询属于该角色的用户）（条件+分页）
     * @param roleUserQuery 查询条件
     * @return 查询结果 分页显示
     */
    JsonVO<PageDTO<RoleUserVO>> queryRoleUserList(RoleUserQuery roleUserQuery);

    /**
     * 添加角色用户
     * @param roleUserDTO 新增角色用户信息（添加单个用户）
     * @return true表示添加成功
     */
    JsonVO<Boolean> addRoleUser(RoleUserDTO roleUserDTO);

    /**
     * 根据用户ID删除角色用户
     * @param roleUserDTO 需要删除的角色用户
     * @return true表示删除成功
     */
    JsonVO<Boolean> deleteRoleUser(RoleUserDTO roleUserDTO);

}
