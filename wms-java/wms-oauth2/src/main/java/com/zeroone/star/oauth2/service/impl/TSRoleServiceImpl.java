package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.TSRole;
import com.zeroone.star.oauth2.mapper.TSRoleMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.service.ITSRoleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 角色信息 服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Service
public class TSRoleServiceImpl extends ServiceImpl<TSRoleMapper, TSRole> implements ITSRoleService {

    @Autowired
    TSRoleMapper TSRoleMapper;

    /**
     * 获取菜单url对应的所有角色
     */
    @Override
    public List<TSRole> listRoleByFunctionUrl(String functionurl) {
        return TSRoleMapper.selectRoleByFunctionUrl(functionurl);
    }

    /**
     * 通过用户id获取角色
     */
    @Override
    public List<TSRole> listRoleByUserId(String id) {
        return TSRoleMapper.selectRoleByUserId(id);
    }
}
