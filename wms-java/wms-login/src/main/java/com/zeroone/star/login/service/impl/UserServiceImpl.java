package com.zeroone.star.login.service.impl;


import cn.hutool.core.bean.BeanUtil;
import cn.hutool.json.JSONObject;
import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.nimbusds.jose.JWSObject;
import com.zeroone.cloud.oauth2.entity.Oauth2Token;
import com.zeroone.star.login.entity.TSBaseUser;
import com.zeroone.star.login.entity.TSUser;
import com.zeroone.star.login.mapper.TSBaseUserMapper;
import com.zeroone.star.login.mapper.TSUserMapper;
import com.zeroone.star.login.service.ITSUserService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.dto.login.RefreshTokenDTO;
import com.zeroone.star.project.dto.login.UserPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.LoginVO;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.http.ResponseEntity;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.text.ParseException;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 系统用户扩展 服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */

@Mapper(componentModel = "spring")
interface MsUserService {
    /**
     * TSUser 转换为 LoginVo
     * @param TSUser
     * @return
     */
    LoginVO userToLoginVo(TSUser TSUser);

}

@Service
public class UserServiceImpl extends ServiceImpl<TSUserMapper, TSUser> implements ITSUserService {

    @Autowired
    private TSUserMapper userMapper;

    @Autowired
    private TSBaseUserMapper TSBaseUserMapper;

    @Autowired
    private CaptchaService captchaService;

    @Resource
    OauthService oAuthService;

    @Autowired
    private MsUserService msUserService;

    @Value("${captcha.enabled}")
    private boolean captchaEnabled;

    private static final String LOGIN_TOKEN = "token";
    private static final String LOGIN_REFRESHTOKEN = "refreshToken";

    @Autowired
    private RedisTemplate<String, Object> redisTemplate;
    @Resource
    UserHolder userHolder;
    @Value("${zo.cloud.starter.oauth2.mgr-id}")
    String clientId;
    @Value("${zo.cloud.starter.oauth2.mgr-password}")
    String clientPassword;

    /**
     * 通过用户名获取用户信息
     */
    @Override
    public LoginVO getUserByUsername(UserDTO userDTO) {
        TSUser TSUser = userMapper.selectUserMesssageByUsername(userDTO.getUsername());
        LoginVO loginVO = msUserService.userToLoginVo(TSUser);
        loginVO.setRoles(userDTO.getRoles());
        loginVO.setUsername(userDTO.getUsername());
        // 返回查询结果
        return loginVO;
    }

    /**
     * 授权登录
     */
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        if(captchaEnabled)
        {
            //进行验证码二次校验
            CaptchaVO captchaVO = new CaptchaVO();
            captchaVO.setCaptchaVerification(loginDTO.getCode());
            ResponseModel response = captchaService.verification(captchaVO);
            //若验证码二次校验失败，返回验证码错误信息
            if(!response.isSuccess())
                return JsonVO.create(null,Integer.valueOf(response.getRepCode()),response.getRepMsg());
        }
        // 账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);
        // 认证失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }
        redisTemplate.opsForValue().set(loginDTO.getUsername() + ":" + LOGIN_TOKEN,
                oauth2Token.getToken(),oauth2Token.getExpiresIn(), TimeUnit.SECONDS);
        redisTemplate.opsForValue().set(loginDTO.getUsername() + ":" + LOGIN_REFRESHTOKEN,
                oauth2Token.getRefreshToken(),oauth2Token.getExpiresIn(), TimeUnit.SECONDS);
        return JsonVO.success(BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class));
    }
    /**
     * 验证用户修改密码
     */
    @Override
    public Boolean updatePassword(UserDTO userDTO, UserPasswordDTO userPasswordDTO) {
        BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();
        if (userPasswordDTO.getNewPassword().equals(userPasswordDTO.getRePassword())) {// 验证密码和重复密码
            // 构造查询条件
            LambdaQueryWrapper<TSBaseUser> queryWrapper = new LambdaQueryWrapper<>();
            queryWrapper.select(TSBaseUser::getPassword).eq(TSBaseUser::getUsername, userDTO.getUsername());
            // 验证密码
            boolean matches = passwordEncoder.matches(userPasswordDTO.getOldPassword(), TSBaseUserMapper.selectOne(queryWrapper).getPassword());
            if (matches) {
                LambdaUpdateWrapper<TSBaseUser> updateWrapper = new LambdaUpdateWrapper<>();
                updateWrapper.set(TSBaseUser::getPassword, passwordEncoder.encode(userPasswordDTO.getNewPassword()))
                        .eq(TSBaseUser::getUsername, userDTO.getUsername());
                // 修改密碼 删除凭证
                return TSBaseUserMapper.update(new TSBaseUser(), updateWrapper) == 1 &&
                        Boolean.TRUE.equals(redisTemplate.delete(userDTO.getUsername() + ":" + LOGIN_TOKEN)) &&
                        Boolean.TRUE.equals(redisTemplate.delete(userDTO.getUsername() + ":" + LOGIN_REFRESHTOKEN));
            }
        }
        ResponseEntity.badRequest().body("两次输入的密码不一致");
        return false;
    }


    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(RefreshTokenDTO refreshTokenDTO) {
        // TODO:未实现注销凭证验证
        String username = null;
        try {
            JWSObject jwsObject = JWSObject.parse(refreshTokenDTO.getToken());
            String userStr = jwsObject.getPayload().toString();
            JSONObject jsonObject = new JSONObject(userStr);
            username = jsonObject.getStr("user_name");
        } catch (ParseException e) {
            return JsonVO.create(null, ResultStatus.FAIL);
        }

        String token = (String) redisTemplate.opsForValue().get(username + ":" + LOGIN_TOKEN);
        String rToken = (String) redisTemplate.opsForValue().get(username + ":" + LOGIN_REFRESHTOKEN);
        if(!token.equals(refreshTokenDTO.getToken())||!rToken.equals(refreshTokenDTO.getRefreshToken())) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "凭证已过期，请重新登录");
        }
        // 刷新凭证
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("refresh_token", refreshTokenDTO.getRefreshToken());
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);

        // 刷新失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }

        // TODO:未实现刷新成功后如何刷新注销凭证（如删除与更新内存数据库）
        redisTemplate.opsForValue().set(username + ":" + LOGIN_TOKEN, oauth2Token.getToken(),oauth2Token.getExpiresIn(), TimeUnit.SECONDS);
        redisTemplate.opsForValue().set(username + ":" + LOGIN_REFRESHTOKEN, oauth2Token.getRefreshToken(),oauth2Token.getExpiresIn(), TimeUnit.SECONDS);
        // 响应刷新成功数据
        return JsonVO.success(BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class));
    }

    @Override
    public JsonVO<LoginVO> getCurrUser() {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        } else {
            // TODO:这里需要根据业务需求，重新实现
            return JsonVO.success(getUserByUsername(currentUser));
        }
    }

    @Override
    public JsonVO<String> logout() throws Exception {
        // 获取当前请求的token
        String token = userHolder.getCurrentToken();
        String username = userHolder.getCurrentUser().getUsername();
        if (token != null){
            // TODO:登出逻辑，需要配合登录逻辑实现
            Boolean delete = redisTemplate.delete(username + ":" + LOGIN_TOKEN);
            Boolean delete1 = redisTemplate.delete(username + ":" + LOGIN_REFRESHTOKEN);
            return Boolean.TRUE.equals(delete) && Boolean.TRUE.equals(delete1) ?
                    JsonVO.success("退出成功") : JsonVO.fail("服务器错误，请稍后重试");
        }
        return JsonVO.fail("获取凭证失败，退出失败");
    }
}
