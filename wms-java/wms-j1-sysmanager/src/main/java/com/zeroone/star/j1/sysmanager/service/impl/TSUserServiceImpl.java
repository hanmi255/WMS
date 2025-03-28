package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.*;
import com.zeroone.star.j1.sysmanager.mapper.*;
import com.zeroone.star.j1.sysmanager.service.ITSUserService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDetailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.DepartmentVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.RoleVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.UserDetailVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;
import java.util.stream.Collectors;

/**
 * <p>
 * InnoDB free: 599040 kB; (`id`) REFER `jeecg/t_s_base_user`(` 服务实现类
 * </p>
 *
 * @author PingShui
 * @since 2025-02-24
 */
@Service
public class TSUserServiceImpl extends ServiceImpl<TSUserMapper, TSUser> implements ITSUserService {
    @Autowired
    private UserHolder userHolder;
    @Autowired
    private TSUserMapper userMapper;
    @Autowired
    private TSRoleUserMapper roleUserMapper;
    @Autowired
    private TSUserOrgMapper userOrgMapper;
    @Autowired
    private TSBaseUserMapper baseUserMapper;
    @Autowired
    PasswordEncoder passwordEncoder;
    @Autowired
    private TSRoleMapper roleMapper;
    @Autowired
    private TSDepartMapper departMapper;
    /**
     * param  String
     * return String
     * 修改用户状态为禁止
     * **/
    @Transactional
    @Override
    public JsonVO<String> modifyUserStatus_to_Ban(String userId) throws Exception {
//        获取当前登录人的信息
        com.zeroone.star.project.components.user.UserDTO currentUser =
                userHolder.getCurrentUser();


        System.out.println("-------------------------------" + currentUser.getId());
        TSBaseUser currentBaseUser = baseUserMapper.selectById(currentUser.getId());

        System.out.println("-------------------------------" + currentBaseUser);
//        首先修改用户的基础表改为禁用
        
         QueryWrapper<TSBaseUser> wrapper = new QueryWrapper<>();
        wrapper.eq("id", userId);
        TSBaseUser tsBaseUserDetail= baseUserMapper.selectOne(wrapper);
        if (tsBaseUserDetail.getUsername().equals("admin")){
            return JsonVO.fail("admin用户不能被操作");
        }
        TSBaseUser tsBaseUser = new TSBaseUser() {{
            setId(userId);
            setStatus(0);
        }};
        baseUserMapper.updateById(tsBaseUser);

//        其次修改用户的详情信息表修改，更新时间和操作人
        TSUser tsUser = new TSUser() {{
            setId(userId);
            setUpdateName(currentBaseUser.getRealname());
            setUpdateBy(currentBaseUser.getUsername());

            setUpdateDate(LocalDateTime.now());
        }};
        userMapper.updateById(tsUser);
        return JsonVO.success("修改用户状态为禁止");
    }
    /**
     * param  String
     * return String
     * 修改用户状态为激活
     * **/
    @Transactional
    @Override
    public JsonVO<String> modifyUserStatus_to_Active(String userId) throws Exception {
        //        获取当前登录人的信息
        com.zeroone.star.project.components.user.UserDTO currentUser = userHolder.getCurrentUser();

        TSBaseUser currentBaseUser = baseUserMapper.selectById(currentUser.getId());

        //        首先修改用户的基础表改为激活
         QueryWrapper<TSBaseUser> wrapper = new QueryWrapper<>();
        wrapper.eq("id", userId);
        TSBaseUser tsBaseUserDetail= baseUserMapper.selectOne(wrapper);
        if (tsBaseUserDetail.getUsername().equals("admin")){
            return JsonVO.fail("admin用户不能被操作");
        }
        TSBaseUser tsBaseUser = new TSBaseUser() {{
            setId(userId);
            setStatus(1);
        }};
        baseUserMapper.updateById(tsBaseUser);
//        其次修改用户的详情信息表修改，更新时间和操作人
        TSUser tsUser = new TSUser() {{
            setId(userId);
            setUpdateName(currentBaseUser.getRealname());
            setUpdateBy(currentBaseUser.getUsername());
            setUpdateDate(LocalDateTime.now());
        }};
        userMapper.updateById(tsUser);
        return JsonVO.success("修改用户状态为激活");
    }
    /**
     * param  UserDetailDTO
     * return String
     * 修改用户信息
     * **/
    @Transactional
    @Override
    public JsonVO<String> modifyUser(UserDetailDTO userDetailDTO) throws Exception {
        if (userDetailDTO.getDepartmentVO() == null || userDetailDTO.getRoleVO() == null) {
            return JsonVO.fail("请选择部门或者角色");
        }
        com.zeroone.star.project.components.user.UserDTO currentUser = userHolder.getCurrentUser();
        TSBaseUser currentBaseUser = baseUserMapper.selectById(userDetailDTO.getId());
//        因为涉及的表太多了，逐个修改很麻烦，所以先全部删除，再全部插入
//        先删除用户和角色关联表
        QueryWrapper<TSRoleUser> roleUserWrapper = new QueryWrapper<>();
        roleUserWrapper.eq("userid", userDetailDTO.getId());

        roleUserMapper.delete(roleUserWrapper);
//        重新插入用户和角色关联表
        for (RoleVO roleVO : userDetailDTO.getRoleVO()) {
            TSRoleUser tsRoleUser = new TSRoleUser() {{
                setId(UUID.randomUUID().toString().replaceAll("-", ""));
                setUserid(userDetailDTO.getId());
                setRoleid(roleVO.getId());
            }};
            roleUserMapper.insert(tsRoleUser);
        }
//        再删除用户和部门关联表
        QueryWrapper<TSUserOrg> userOrgWrapper = new QueryWrapper<>();
        userOrgWrapper.eq("user_id", userDetailDTO.getId());
        userOrgMapper.delete(userOrgWrapper);

//        重新插入用户和部门关联表
        for (DepartmentVO departmentVO : userDetailDTO.getDepartmentVO()) {
            TSUserOrg tsUserOrg = new TSUserOrg() {{
                setId(UUID.randomUUID().toString().replaceAll("-", ""));
                setUserId(userDetailDTO.getId());
                setOrgId(departmentVO.getId());
            }};
            userOrgMapper.insert(tsUserOrg);
        }
//        修改用户的基础表信息
        TSBaseUser tsBaseUser = new TSBaseUser() {{
            setId(userDetailDTO.getId());
            setRealname(userDetailDTO.getRealname());
        }};
        baseUserMapper.updateById(tsBaseUser);

//        修改用户表的信息
        TSUser tsUser = new TSUser() {{
            setId(userDetailDTO.getId());
            setUserType(userDetailDTO.getUserType());
            setMobilePhone(userDetailDTO.getMobilePhone());
            setOfficePhone(userDetailDTO.getOfficePhone());
            setEmail(userDetailDTO.getEmail());
            setUpdateDate(LocalDateTime.now());
            setUpdateName(currentBaseUser.getRealname());
            setUpdateBy(currentUser.getUsername());
        }};
        userMapper.updateById(tsUser);


        return JsonVO.success("修改成功");
    }

    /**
     *  param  String
     * return UserDetailVO
     * 查询用户详细
     * **/
    @Override
    public JsonVO<UserDetailVO> queryUserDetail(String userId) {
        UserDetailVO userDetailVO = new UserDetailVO();
//        baseUser表内信息
        userDetailVO = userMapper.selectUserDetail(userId);
        if (userDetailVO == null) {
            throw new RuntimeException("用户不存在");
        }

        return JsonVO.success(userDetailVO);
    }


    /**
     *
     * return List<DepartmentVO>
     * 查询全部部门
     * **/



    /**
     * return List<RoleVO>
     * 查询全部角色
     **/



    /**
     * param  String
     * return Boolean
     * 查询是否存在重复的账号
     **/
    @Override
    public JsonVO<String> selectByUsername(String username) {
        QueryWrapper<TSBaseUser> queryWrapper = new QueryWrapper<>();
        queryWrapper.apply("BINARY username = {0}", username);
        List<TSBaseUser> tsBaseUsers = baseUserMapper.selectList(queryWrapper);
        if (tsBaseUsers.size()!=0) {
            return JsonVO.fail("账号已经存在");
        }

        return JsonVO.success("账号不存在");
    }

    /**
     * param  userDTO
     * return String
     * 新增用户
     **/
    @Transactional
    @Override
    public JsonVO<String> SaveUser(UserDTO userDTO) throws Exception {
        if (userDTO == null) {
            throw new RuntimeException("传入的实体对象不能为空");
        }else if (userDTO.getDepartmentIds() == null || userDTO.getDepartmentIds().size()==0){
            throw new RuntimeException("请选择部门");
        }else if (userDTO.getRoleIds() == null || userDTO.getRoleIds().size()==0){
            throw new RuntimeException("请选择角色");
        }else if (userDTO.getUsername() == null || userDTO.getUsername().length()==0){
            throw new RuntimeException("请输入账号");
        }else if (userDTO.getPassword() == null || userDTO.getPassword().length()==0){
            throw new RuntimeException("请输入密码");
        }
        JsonVO<String> stringJsonVO = selectByUsername(userDTO.getUsername());
        if (stringJsonVO.getData().equals("账号已经存在")){
            throw new RuntimeException("账号已经存在");
        }
//        获取当前登录人的信息
        com.zeroone.star.project.components.user.UserDTO currentUser =
                userHolder.getCurrentUser();
        System.out.println("====================="+currentUser);
        if (currentUser==null){
            throw new RuntimeException("获取当前用户信息失败");
        }

//        生成id
        userDTO.setId(UUID.randomUUID().toString().replaceAll("-", ""));
//        加密密码
        userDTO.setPassword(passwordEncoder.encode(userDTO.getPassword()));
        //        插入用户的基础信息
        TSBaseUser tsBaseUser = new TSBaseUser() {{
            setId(userDTO.getId());
            setUsername(userDTO.getUsername());
            setPassword(userDTO.getPassword());
            setRealname(userDTO.getRealname());
            setStatus(1);
            setDeleteFlag(0);
        }};
        baseUserMapper.insert(tsBaseUser);
//        插入用户详细信息
//        获取操作用户的全部信息
        QueryWrapper<TSBaseUser> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("username", currentUser.getUsername());
        TSBaseUser currentBaseUser = baseUserMapper.selectOne(queryWrapper);
        TSUser tsUser = new TSUser() {{
            setId(userDTO.getId());
            setEmail(userDTO.getEmail());
            setMobilePhone(userDTO.getMobilePhone());
            setOfficePhone(userDTO.getOfficePhone());
            setCreateName(currentBaseUser.getRealname());
            setCreateDate(LocalDateTime.now());
            setCreateBy(currentBaseUser.getUsername());
            setUserType(userDTO.getUserType());
        }};
        userMapper.insert(tsUser);
//        新建用户要涉及到，角色和用户关联表，用户和部门关联表
//        先插入角色和用户关联表

        for (String roleId : userDTO.getRoleIds()) {
            TSRoleUser tsRoleUser = new TSRoleUser() {{
                setId(UUID.randomUUID().toString().replaceAll("-", ""));
                setUserid(userDTO.getId());
                setRoleid(roleId);
            }};
            roleUserMapper.insert(tsRoleUser);
        }
//        其次是插入用户和部门关联表
        for (String departmentId : userDTO.getDepartmentIds()) {
            TSUserOrg tsUserOrg = new TSUserOrg() {{
                setId(UUID.randomUUID().toString().replaceAll("-", ""));
                setUserId(userDTO.getId());
                setOrgId(departmentId);
            }};
            userOrgMapper.insert(tsUserOrg);
        }


        return JsonVO.success("添加成功");
    }
}
