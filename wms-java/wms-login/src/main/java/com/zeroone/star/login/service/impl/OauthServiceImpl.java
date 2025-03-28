package com.zeroone.star.login.service.impl;

import com.zeroone.cloud.oauth2.entity.Oauth2Token;
import com.zeroone.star.login.service.OauthService;
import lombok.AllArgsConstructor;

import java.util.Map;

/**
 * <p>
 * 描述：授权服务降级实现
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@AllArgsConstructor
public class OauthServiceImpl implements OauthService {
    private Throwable throwable;

    @Override
    public Oauth2Token postAccessToken(Map<String, String> parameters) {
        Oauth2Token error = new Oauth2Token();
        if (throwable.getMessage() != null) {
            error.setErrorMsg(throwable.getMessage());
        } else {
            error.setErrorMsg(throwable.getClass().toGenericString());
        }
        return error;
    }
}
