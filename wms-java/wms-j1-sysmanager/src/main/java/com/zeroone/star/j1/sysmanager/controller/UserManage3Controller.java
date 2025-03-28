package com.zeroone.star.j1.sysmanager.controller;

import com.zeroone.star.j1.sysmanager.service.ISysUserService;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.ResetPasswordDTO;
import com.zeroone.star.project.j1.sysmanager.usermanage.UserManage3Apis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;


/**
 * j1-小马（halo）接口位置
 * @author 李云毅
 * @version 1.0.0
 * 2025/3/1
 */
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理->重置删除导入导出")
@Validated
public class UserManage3Controller implements UserManage3Apis {

    @Resource
    private ISysUserService sysUserService;

    /**
     * 重置用户密码
     *dto 重置密码数据对象
     */
    @PostMapping("reset-password")
    @Override
    public JsonVO<String> resetUserPassword(@Valid ResetPasswordDTO dto) {
        try {
            sysUserService.resetPassword(dto);
            return JsonVO.success("密码重置成功");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    /**
     * 删除用户
     */
    @DeleteMapping("{userId}")
    @Override
    public JsonVO<String> deleteUser(@PathVariable String userId, @RequestParam(defaultValue = "false") boolean isPhysicalDelete) {
        try {
            sysUserService.deleteUser(userId, isPhysicalDelete);
            return JsonVO.success("用户删除成功");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    /**
     * 导出用户信息
     */
    @GetMapping("export")
    @Override
    public void exportUsers(HttpServletResponse response) {
        try {
            sysUserService.exportUsers(response);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 导入用户信息
     */
    @PostMapping("import")
    @Override
    public JsonVO<String> importUsers(@RequestParam("file") MultipartFile file) {
        try {
            String result = sysUserService.importUsers(file);
            return JsonVO.success(result);
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }
}
