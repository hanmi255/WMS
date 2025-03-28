package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j1.sysmanager.entity.TSUser;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDetailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.DepartmentVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.RoleVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.UserDetailVO;

import java.util.List;

/**
 * <p>
 * InnoDB free: 599040 kB; (`id`) REFER `jeecg/t_s_base_user`(` 服务类
 * </p>
 *
 * @author PingShui
 * @since 2025-02-24
 */
public interface ITSUserService extends IService<TSUser> {
    /**
     * param  userDTO
     * return String
     * 新增用户
     **/
    JsonVO<String> SaveUser(UserDTO userDTO) throws Exception;

    /**
     * param  String
     * return Boolean
     * 查询是否存在重复的账号
     **/

    JsonVO<String> selectByUsername(String username);

    /**
     * return List<RoleVO>
     * 查询全部角色
     **/



    /**
     *
     * return List<DepartmentVO>
     * 查询全部部门
     * **/



    /**
     *  param  String
     * return UserDetailVO
     * 查询用户详细
     * **/

    JsonVO<UserDetailVO> queryUserDetail(String userId);

    /**
     * param  UserDetailDTO
     * return String
     * 修改用户信息
     * **/

    JsonVO<String> modifyUser(UserDetailDTO userDetailDTO) throws Exception;

    /**
     * param  String
     * return String
     * 修改用户状态为禁止
     * **/

    JsonVO<String> modifyUserStatus_to_Ban(String userId) throws Exception;

    /**
     * param  String
     * return String
     * 修改用户状态为激活
     * **/
    JsonVO<String> modifyUserStatus_to_Active(String userId) throws Exception;
}
