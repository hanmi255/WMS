package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.TSRole;
import com.zeroone.star.j1.sysmanager.mapper.TSRoleMapper;
import com.zeroone.star.j1.sysmanager.service.ITSRoleNameService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  获取角色类型 服务实现类
 * </p>
 *
 * @author langyanyan
 * @since 2025-03-01
 */
@Mapper(componentModel = "spring")
interface MsRoleNameMapper{
    /**
     * 将do对象：TSRole 转换为RoleListDTO
     * @param
     * @return 转换后的对象
     */
    RoleListDTO TSRoleToRoleListDTO(TSRole tsRole);
}
@Service
public class TSRoleManageServiceImpl extends ServiceImpl<TSRoleMapper, TSRole> implements ITSRoleNameService {
    @Resource
    MsRoleNameMapper rOleNameMapper;

    @Override
    public PageDTO<RoleListDTO> listRoleName(RoleManagementQuery query) {
        //构建分页对象
        Page<TSRole> page = new Page<>(query.getPageIndex(),query.getPageSize());
        //构建查询条件
        QueryWrapper<TSRole> queryWrapper = new QueryWrapper<>();
        queryWrapper.like("rolename",query.getRolename());
        //查询数据
        Page<TSRole> tsRolePage = baseMapper.selectPage(page,queryWrapper);

        return PageDTO.create(tsRolePage,rOleNameMapper::TSRoleToRoleListDTO);
    }
}
