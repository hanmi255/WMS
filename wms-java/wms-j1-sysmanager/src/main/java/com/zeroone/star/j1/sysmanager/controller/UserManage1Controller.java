package com.zeroone.star.j1.sysmanager.controller;



import com.zeroone.star.j1.sysmanager.service.ITSUserService;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserDetailDTO;
import com.zeroone.star.project.j1.sysmanager.usermanage.UserManage1Apis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.UserDetailVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2025/3/1
 */
@RestController
@RequestMapping("/user")
@Api(tags = "用户管理->添加编辑")
@Validated
public class UserManage1Controller implements UserManage1Apis {

    @Autowired
    private ITSUserService userService;
    @ApiOperation(value = "添加用户")
    @PostMapping("adduser")
    @Override
    public JsonVO<String> addUser(@RequestBody UserDTO userDTO) throws Exception {

        return userService.SaveUser(userDTO);
    }
    @ApiOperation(value = "查询是否存在重复账号")
    @GetMapping("get/username/{username}")
    @Override
    public JsonVO<String> qeuryUserAccount(@PathVariable(value = "username") String username) {
        return userService.selectByUsername(username);
    }

    @ApiOperation(value = "查询用户详情")
    @GetMapping("get/userdetail/{userId}")
    @Override
    public JsonVO<UserDetailVO> queryUserDetail(@PathVariable(value = "userId") String userId) {
        return userService.queryUserDetail(userId);
    }
    @ApiOperation(value = "编辑用户详情")
    @PutMapping("modify/userdetail")
    @Override
    public JsonVO<String> modifyUser(@RequestBody UserDetailDTO userDetailDTO) throws Exception {
        return userService.modifyUser(userDetailDTO);
    }
    @ApiOperation(value = "锁定用户状态")
    @PutMapping("modify/modifyuserstatus-to-ban")
    @Override
    public JsonVO<String> modifyUserStatus_to_Ban(String userId) throws Exception {
        return userService.modifyUserStatus_to_Ban(userId);
    }
    @ApiOperation(value = "激活用户状态")
    @PutMapping("modify/modifyuserstatus-to-active")
    @Override
    public JsonVO<String> modifyUserStatus_to_Active(String userId) throws Exception {
        return userService.modifyUserStatus_to_Active(userId);
    }
}
