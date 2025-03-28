package com.zeroone.star.oauth2.service.impl.oauth2;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.cloud.oauth2.entity.SecurityUser;
import com.zeroone.cloud.starter.oauth2.service.LoadUserDetailService;
import com.zeroone.star.oauth2.entity.TSBaseUser;
import com.zeroone.star.oauth2.entity.TSRole;
import com.zeroone.star.oauth2.service.ITSBaseUserService;
import com.zeroone.star.oauth2.service.ITSRoleService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：加载用户信息服务实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class LoadUserDetailServiceImpl implements LoadUserDetailService {
    @Resource
    ITSRoleService roleService;

    @Resource
    ITSBaseUserService baseUserService;

    @Override
    public SecurityUser loadUserDetailForMgr(String username) throws UsernameNotFoundException {
        // TODO：通过用户名查询用户,需要根据你的数据库设计来修改代码
        // 1 通过用户名查找用户对象
        TSBaseUser baseUser = new TSBaseUser();
        baseUser.setUsername(username);
        baseUser = baseUserService.getOne(new LambdaQueryWrapper<TSBaseUser>()
                .eq(TSBaseUser::getUsername, username));
        if(baseUser == null)
        {
            throw new UsernameNotFoundException("用户名或密码错误");
        }
        // TODO：通过用户编号查询角色,需要根据你的数据库设计来修改代码
        // 2 通过用户ID获取角色列表
        List<TSRole> roles = roleService.listRoleByUserId(baseUser.getId());
        // 3 构建权限角色对象
        return SecurityUser.create(baseUser, baseUser.getUsername(), baseUser.getPassword(), roles.stream().map(TSRole::getRolecode).collect(Collectors.toList()));
    }

    @Override
    public SecurityUser loadUserDetailForUser(String username) throws UsernameNotFoundException {
        throw new UsernameNotFoundException("用户端查找用户尚未实现");
    }
}
