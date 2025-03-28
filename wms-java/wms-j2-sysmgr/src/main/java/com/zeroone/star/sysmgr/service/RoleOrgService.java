package com.zeroone.star.sysmgr.service;

import com.zeroone.star.project.dto.j2.sysmgr.UpdateRoleOrgDTO;
import com.zeroone.star.project.query.j2.sysmgr.RoleOrgQuery;
import com.zeroone.star.project.vo.j2.sysmgr.RoleOrgVO;

import java.util.List;

public interface RoleOrgService {

    /**
     * 查询机构关联的角色列表
     * @param query 查询条件 机构id
     * @return
     */
    List<RoleOrgVO> listRoleByOrg(RoleOrgQuery query );

    /**
     * 更新机构与角色的关联关系
     * @param dto
     */
    void updateRoleOrg(UpdateRoleOrgDTO dto);
}
