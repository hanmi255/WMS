package com.zeroone.star.login.controller;


import com.zeroone.star.login.service.ITSFunctionService;
import com.zeroone.star.login.service.ITSUserService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.dto.login.RefreshTokenDTO;
import com.zeroone.star.project.dto.login.UserPasswordDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.FunctionTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("login")
@Api(tags = "登录模块")
public class LoginController implements LoginApis {



    @Autowired
    private ITSUserService userService;
    @Autowired
    UserHolder userHolder;

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(@RequestBody LoginDTO loginDTO) {
        // 响应认证成功数据
        return userService.authLogin(loginDTO);
    }

    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(@RequestBody RefreshTokenDTO refreshTokenDTO) {
        return userService.refreshToken(refreshTokenDTO);
    }

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<LoginVO> getCurrUser() {
        return userService.getCurrUser();
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() throws Exception {
        return userService.logout();
    }

    @ApiOperation("修改密码")
    @PostMapping("modify-password")
    @Override
    public JsonVO<String> modifyPassword(@Validated UserPasswordDTO userPasswordDTO) {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
            Boolean success = userService.updatePassword(currentUser, userPasswordDTO);
            return success ? JsonVO.success("密码修改成功") : JsonVO.fail("旧密码错误，请重新输入");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Resource
    ITSFunctionService functionService;

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<FunctionTreeVO>> getMenus() throws Exception {
        // TODO:未实现根据实际数据库设计业务逻辑，下面逻辑属于示例逻辑
        // 1 获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        // 2 获取当前用户拥有的菜单
        List<FunctionTreeVO> menus = functionService.listFunctionByRoleName(currentUser.getRoles());
        return JsonVO.success(menus);
    }
}
