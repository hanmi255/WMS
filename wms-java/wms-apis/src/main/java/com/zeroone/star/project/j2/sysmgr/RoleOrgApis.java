package com.zeroone.star.project.j2.sysmgr;

import com.zeroone.star.project.dto.j2.sysmgr.UpdateRoleOrgDTO;
import com.zeroone.star.project.query.j2.sysmgr.RoleOrgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.sysmgr.RoleOrgVO;

import java.util.List;

public interface RoleOrgApis {
    /**
     * 获取和组织机构关联的角色表
     * @param query
     * @return
     */
    JsonVO<List<RoleOrgVO>> queryRoleByOrg(RoleOrgQuery query);


    /**
     * 更新组织机构和角色的关联关系
     * @param dto
     * @return
     */
    JsonVO<String> updateRoleOrg(UpdateRoleOrgDTO dto);

}
