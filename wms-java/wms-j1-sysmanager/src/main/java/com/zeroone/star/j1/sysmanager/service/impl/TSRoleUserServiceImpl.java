package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.TSRoleUser;
import com.zeroone.star.j1.sysmanager.mapper.TSRoleUserMapper;
import com.zeroone.star.j1.sysmanager.service.ITSRoleUserService;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleUserDTO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.UUID;

/**
 * <p>
 * 角色用户 服务实现类
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
@Service
public class TSRoleUserServiceImpl extends ServiceImpl<TSRoleUserMapper, TSRoleUser> implements ITSRoleUserService {


    @Resource
    private TSRoleUserMapper roleUserMapper;

    @Override
    public Boolean addRoleUser(RoleUserDTO roleUserDTO) {
        String id = UUID.randomUUID().toString().substring(0, 31);
        Boolean flag = roleUserMapper.insertRoleUser(id,roleUserDTO.getRoleId(),roleUserDTO.getUserId());
        return flag;
    }

    @Override
    public Boolean deleteRoleUser(RoleUserDTO roleUserDTO) {
        Boolean flag = roleUserMapper.deleteRoleUser(roleUserDTO.getRoleId(),roleUserDTO.getUserId());
        return flag;
    }

    @Override
    public TSRoleUser selectRoleUser(RoleUserDTO roleUserDTO) {
        QueryWrapper<TSRoleUser> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("ID","roleid","userid")
                .like("roleid",roleUserDTO.getRoleId())
                .like("userid",roleUserDTO.getUserId());
        return roleUserMapper.selectOne(queryWrapper);
    }

}
