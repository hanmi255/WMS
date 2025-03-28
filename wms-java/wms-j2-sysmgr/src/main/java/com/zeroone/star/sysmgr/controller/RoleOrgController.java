package com.zeroone.star.sysmgr.controller;

import com.zeroone.star.project.dto.j2.sysmgr.UpdateRoleOrgDTO;
import com.zeroone.star.project.j2.sysmgr.RoleOrgApis;
import com.zeroone.star.project.query.j2.sysmgr.RoleOrgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.sysmgr.RoleOrgVO;
import com.zeroone.star.sysmgr.service.RoleOrgService;
import com.zeroone.star.sysmgr.service.impl.RoleOrgServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/sysmgr/role-org")
@Api(tags = "组织角色相关")
public class RoleOrgController implements RoleOrgApis {
    @Autowired
    RoleOrgService roleOrgService;
    /**
     * 获取和组织机构关联的角色表
     *
     * @param query
     * @return
     */
    @GetMapping("/query-by-org")
    @ApiOperation("获取组织角色")
    @Override
    public JsonVO<List<RoleOrgVO>> queryRoleByOrg(RoleOrgQuery query) {

        return JsonVO.success(roleOrgService.listRoleByOrg(query));
    }

    /**
     * 更新组织机构和角色的关联关系
     *
     * @param dto
     * @return
     */
    @PostMapping("/update-role-org")
    @ApiOperation("更新组织角色")
    @Override
    public JsonVO<String> updateRoleOrg(@RequestBody UpdateRoleOrgDTO dto) {

        roleOrgService.updateRoleOrg(dto);
        return JsonVO.success(null);
    }
}
