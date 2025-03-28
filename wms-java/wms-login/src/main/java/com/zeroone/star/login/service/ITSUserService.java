package com.zeroone.star.login.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.TSUser;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.dto.login.RefreshTokenDTO;
import com.zeroone.star.project.dto.login.UserPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.LoginVO;

/**
 * <p>
 * 系统用户扩展 服务类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
public interface ITSUserService extends IService<TSUser> {

    // 通过用户名获取用户信息
    LoginVO getUserByUsername(UserDTO username);

    // 用户修改密码验证
    Boolean updatePassword(UserDTO userDTO, UserPasswordDTO userPasswordDTO);

    // 用户授权登录
    JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO);

    // 刷新凭证
    JsonVO<Oauth2TokenDTO> refreshToken(RefreshTokenDTO refreshTokenDTO);

    // 获取当前用户信息
    JsonVO<LoginVO> getCurrUser();

    // 退出登录
    JsonVO<String> logout() throws Exception;

}
