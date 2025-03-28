package com.zeroone.star.j1.sysmanager.controller;

import com.zeroone.star.j1.sysmanager.entity.TSRoleUser;
import com.zeroone.star.j1.sysmanager.service.ITSRoleUserService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleUserDTO;
import com.zeroone.star.project.j1.sysmanager.rolemanage.RoleUserApis;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleUserQuery;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.UserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleUserVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.UserVO;
import com.zeroone.star.j1.sysmanager.service.ITSBaseUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/2/19
 */
@RestController
@RequestMapping("/role")
@Api(tags = "角色管理 -> 角色用户")
@Validated
public class RoleUserController implements RoleUserApis {

    @Resource
    ITSBaseUserService baseUserService;

    @Resource
    ITSRoleUserService roleUserService;

    @GetMapping("query-userList")
    @ApiOperation(value = "获取用户列表（查询不属于该角色的用户）（条件+分页）")
    @Override
    public JsonVO<PageDTO<UserVO>> queryUserList(UserQuery userQuery) {
        //角色id不能为空
        if (userQuery.getRoleId() == null || userQuery.getRoleId().isEmpty()) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(baseUserService.queryUserList(userQuery));
    }

    @ApiOperation(value = "获取角色用户列表（查询属于该角色的用户）（条件+分页）")
    @GetMapping("query-roleUserList")
    @Override
    public JsonVO<PageDTO<RoleUserVO>> queryRoleUserList(RoleUserQuery roleUserQuery) {
        //角色id不能为空
        if (roleUserQuery.getId() == null || roleUserQuery.getId().isEmpty()) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(baseUserService.queryRoleUserList(roleUserQuery));
    }

    @PostMapping("add-roleUser")
    @ApiOperation(value = "添加角色用户（添加单个）" +
            "（如果出现此类报错you're adding a foreign key, you need to make sure that XXXX,是由于库表中主外键的影响，并不是代码是错的）")
    @Override
    public JsonVO<Boolean> addRoleUser(RoleUserDTO roleUserDTO) {
        TSRoleUser roleUser = roleUserService.selectRoleUser(roleUserDTO);
        if(roleUser != null) {//已存在该角色用户
            return JsonVO.fail(false);
        }
        Boolean flag = roleUserService.addRoleUser(roleUserDTO);
        if (flag) {
            return JsonVO.success(true);
        }
        else {
            return JsonVO.fail(false);
        }
    }

    @DeleteMapping("delete-roleUser")
    @ApiOperation(value = "删除角色用户")
    @Override
    public JsonVO<Boolean> deleteRoleUser(RoleUserDTO roleUserDTO) {
        return JsonVO.success(roleUserService.deleteRoleUser(roleUserDTO));
    }



}
