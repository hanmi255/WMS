package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleUserQuery;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.UserQuery;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleUserVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.UserVO;
import com.zeroone.star.j1.sysmanager.entity.TSBaseUser;

/**
 * <p>
 * 系统用户 服务类
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
public interface ITSBaseUserService extends IService<TSBaseUser> {

    /**
     * 获取用户列表（查询不属于该角色的用户）（条件+分页）
     * @param userQuery 查询条件
     * @return 查询结果 分页显示
     */
    PageDTO<UserVO> queryUserList(UserQuery userQuery);

    /**
     * 获取角色用户列表（查询数据该角色的用户）（条件+分页）
     * @param roleUserQuery 查询条件
     * @return 查询结果 分页显示
     */
    PageDTO<RoleUserVO> queryRoleUserList(RoleUserQuery roleUserQuery);
}
