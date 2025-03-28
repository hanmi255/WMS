package com.zeroone.star.j1.sysmanager.controller;

import com.zeroone.star.j1.sysmanager.service.RoleResourseService;
import com.zeroone.star.j1.sysmanager.service.impl.TSFunctionServiceImpl;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionAssignmentDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionDTO;
import com.zeroone.star.project.j1.sysmanager.rolemanage.RoleResourcesApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：角色资源
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-图团
 * @version 1.0.0
 */
@RestController
@RequestMapping("/role")
@Api(tags = "角色管理 -> 角色资源")
@Validated
public class RoleResourcesController implements RoleResourcesApis {

    @Resource
    RoleResourseService tsFunctionService;
    /**
     * 获取资源名称树
     *  匿名的好友
     * @return 资源名称树
     */
    @ApiOperation(value = "获取资源名称树")
    @GetMapping("/getAllFunctionTree")
    @Override
    public JsonVO<RoleFunctionAssignmentDTO> getRoleAllFunction(@RequestParam(value = "langType", defaultValue = "zh-cn") String langType) {
        RoleFunctionAssignmentDTO roleFunctionAssignment = tsFunctionService.getRoleFunction(langType);
        return JsonVO.success(roleFunctionAssignment);
    }
    /**
     * 获取角色分配资源
     *
     *  匿名的好友
     * @param roleCode
     * @return 角色分配资源
     */
    @ApiOperation(value = "获取角色分配资源")
    @GetMapping("/getFunctionTree/{roleCode}")
    @Override
    public JsonVO<RoleFunctionAssignmentDTO> getRoleFunction(@PathVariable(value = "roleCode") String roleCode,
                                                             @RequestParam(value = "langType", defaultValue = "en") String langType) {
        RoleFunctionAssignmentDTO roleFunctionAssignment = tsFunctionService.getRoleFunctionAssignment(roleCode,langType);
        if (roleFunctionAssignment.hasError()) {
            // 根据错误码返回不同状态
            if ("ROLE_NOT_FOUND".equals(roleFunctionAssignment.getErrorCode())) {
                return JsonVO.fail(roleFunctionAssignment);
            }
        }
        return JsonVO.success(roleFunctionAssignment);
    }
    /**
     * 设置角色分配资源
     *
     *  匿名的好友
     * @param roleFunctionAssignmentDTO
     * @return 角色分配资源
     */
    @ApiOperation(value = "设置角色分配资源")
    @PostMapping("/setFunction")
    @Override
    public JsonVO<String> setRoleFunction(@RequestBody RoleFunctionAssignmentDTO roleFunctionAssignmentDTO) {
        String s = tsFunctionService.setRoleFunction(roleFunctionAssignmentDTO);
        if(s.equals("成功：角色功能权限设置完成")){
            return JsonVO.success(s);
        }else {
            return JsonVO.fail(s);
        }

    }


}
