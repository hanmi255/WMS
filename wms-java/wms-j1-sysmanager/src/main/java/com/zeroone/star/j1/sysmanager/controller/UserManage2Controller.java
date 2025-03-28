package com.zeroone.star.j1.sysmanager.controller;

import com.zeroone.star.j1.sysmanager.service.ITSDepartService;
import com.zeroone.star.j1.sysmanager.service.ITSRoleNameService;
import com.zeroone.star.j1.sysmanager.service.ITSUserManageService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.DepartmentDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserListDTO;
import com.zeroone.star.project.j1.sysmanager.usermanage.UserManage2Apis;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.DepartmentQuery;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.UserManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;


/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/3/1
 */
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理->获取列表资源")
@Validated
public class UserManage2Controller implements UserManage2Apis {
    @Resource
    ITSDepartService itsDepartService;
    @Resource
    ITSRoleNameService itsRoleNameService;
    @Resource
    ITSUserManageService itsUserManageService;


    @ApiOperation(value = "获取组织名称树")
    @GetMapping("query-department-all")
    @Override
    public JsonVO<PageDTO<DepartmentDTO>> queryDepartmentAll(DepartmentQuery query) {
        return JsonVO.success(itsDepartService.listDepartAll(query));
    }


    @ApiOperation(value = "获取角色名称列表（条件+分页）")
    @PostMapping("query-role")
    @Override
    public JsonVO<PageDTO<RoleListDTO>> queryRoleByRoleName(@RequestBody RoleManagementQuery roleName) {
        return JsonVO.success(itsRoleNameService.listRoleName(roleName));
    }

    @ApiOperation(value = "获取用户列表（条件+分页）")
    @PostMapping("query-user")
    @Override
    public JsonVO<PageDTO<UserListDTO>> queryRole(@RequestBody UserManagementQuery userQuery) {
        return JsonVO.success(itsUserManageService.listUserManage(userQuery));
    }


}
