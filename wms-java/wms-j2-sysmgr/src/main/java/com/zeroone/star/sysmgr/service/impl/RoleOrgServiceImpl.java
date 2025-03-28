package com.zeroone.star.sysmgr.service.impl;

import com.zeroone.star.project.dto.j2.sysmgr.UpdateRoleOrgDTO;
import com.zeroone.star.project.query.j2.sysmgr.RoleOrgQuery;
import com.zeroone.star.project.vo.j2.sysmgr.RoleOrgVO;
import com.zeroone.star.sysmgr.entity.TSRole;
import com.zeroone.star.sysmgr.entity.TSRoleOrg;
import com.zeroone.star.sysmgr.mapper.TSRoleMapper;
import com.zeroone.star.sysmgr.mapper.TSRoleOrgMapper;
import com.zeroone.star.sysmgr.service.RoleOrgService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;


@Service
public class RoleOrgServiceImpl implements RoleOrgService {

    @Autowired
    private TSRoleMapper roleMapper;

    @Autowired
    private TSRoleOrgMapper roleOrgMapper;
    /**
     * 查询机构关联的角色列表
     *
     * @param query 查询条件机构id,
     * @return
     */
    @Override
    public List<RoleOrgVO> listRoleByOrg(RoleOrgQuery query) {
        //查询机构关联的角色ID；
        List<String> roleIds = roleOrgMapper.selectRoleIdsByOrgId(query.getOrgId());
        if(CollectionUtils.isEmpty(roleIds)){
            return Collections.emptyList();
        }
        //根据角色ID获取角色详细信息；
        List<TSRole> roles = roleMapper.selectListByIds(roleIds);
        //转换为VO
        return roles.stream().map(tsRole -> new RoleOrgVO(
                tsRole.getId(),
                tsRole.getRolename(),
                query.getOrgId())).collect(Collectors.toList());
    }

    /**
     * 更新机构与角色的关联关系
     * @param dto
     */
    @Override
    public void updateRoleOrg(UpdateRoleOrgDTO dto) {
        //删除原有的关联
        roleOrgMapper.deleteByOrgId(dto.getOrgId());

        //插入新关联
        List<TSRoleOrg> list=dto.getRoleIds().stream()
                .map(roleId->{
                    TSRoleOrg roleOrg=new TSRoleOrg();
                    roleOrg.setOrgId(dto.getOrgId());
                    roleOrg.setRoleId(roleId);
                    return roleOrg;
                }).collect(Collectors.toList());
        roleOrgMapper.batchInsert(list);
    }
}
