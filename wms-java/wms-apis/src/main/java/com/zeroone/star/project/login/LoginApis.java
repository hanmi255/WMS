package com.zeroone.star.project.login;

import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.dto.login.RefreshTokenDTO;
import com.zeroone.star.project.dto.login.UserPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.login.FunctionTreeVO;
import com.zeroone.star.project.vo.login.LoginVO;

import java.util.List;

/**
 * <p>
 * 描述：用户登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface LoginApis {
    /**
     * 授权登录接口
     * @param loginDTO 登录数据
     * @return 授权登录结果
     */
    JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO);

    /**
     * 刷新Token认证
     * @param refreshTokenDTO 刷新凭证数据对象
     * @return 刷新Token结果
     */
    JsonVO<Oauth2TokenDTO> refreshToken(RefreshTokenDTO refreshTokenDTO);

    /**
     * 获取当前用户信息
     * @return 返回当前用户信息
     */
    JsonVO<LoginVO> getCurrUser();

    /**
     * 退出登录
     * @return 退出结果
     */
    JsonVO<String> logout() throws Exception;

    /**
     * 修改密码
     */
    JsonVO<String> modifyPassword(UserPasswordDTO userPasswordDTO);

    /**
     * 获取菜单数据
     * @return 菜单数据
     */
    JsonVO<List<FunctionTreeVO>> getMenus() throws Exception;
}
