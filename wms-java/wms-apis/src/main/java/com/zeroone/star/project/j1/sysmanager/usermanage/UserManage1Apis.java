package com.zeroone.star.project.j1.sysmanager.usermanage;

import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDetailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.UserDetailVO;

import java.util.List;

/**
 *  萍水相逢他乡客 接口位置调整
 * @author 李云毅
 * @version 1.0.0
 * 2025/3/1
 */
public interface UserManage1Apis {

    /**
     * 修改用户
     *
     * @param userDetailDTO 用户详情的数据模型对象
     * @return 返回重置结果
     */
    JsonVO<String> modifyUser(UserDetailDTO userDetailDTO) throws Exception;

    /**
     * 锁定用户信息接口
     *
     * @param userId 用户ID
     * @return 返回重置结果
     */
    JsonVO<String> modifyUserStatus_to_Ban(String userId) throws Exception;

    /**
     * 激活用户信息接口
     *
     * @param userId 用户ID
     * @return 返回重置结果
     */
    JsonVO<String> modifyUserStatus_to_Active(String userId) throws Exception;


    /**
     * 新增用户
     *
     * @param userDTO 传入用户的DTO对象模型
     * @return 返回重置结果
     */
    JsonVO<String> addUser(UserDTO userDTO) throws Exception;

    /**
     * 新增用户中的效验账号查询接口
     *
     * @param username 传入账号
     * @return 返回重置结果
     */
    JsonVO<String> qeuryUserAccount(String username);



    /**
     * 修改用户信息前的查询用户详情接口
     *
     * @param userId 用户ID
     * @return 返回重置结果
     */
    JsonVO<UserDetailVO> queryUserDetail(String userId);



}
