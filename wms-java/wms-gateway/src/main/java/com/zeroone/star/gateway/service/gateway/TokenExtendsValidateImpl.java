package com.zeroone.star.gateway.service.gateway;

import cn.hutool.json.JSONObject;
import com.nimbusds.jose.JWSObject;
import com.zeroone.cloud.starter.gateway.service.TokenExtendsValidate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import java.text.ParseException;
import java.util.Objects;

/**
 * <p>
 * 描述：这里实现注销凭证校验处理
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class TokenExtendsValidateImpl implements TokenExtendsValidate {

    @Autowired
    private RedisTemplate<String, Object> redisTemplate;
    private static final String LOGIN_TOKEN = "token";

    @Override
    public boolean isLogout(String token) {
        String realToekn = token.replace("Bearer", "");
        try {
            JWSObject jwsObject = JWSObject.parse(token);
            String userStr = jwsObject.getPayload().toString();
            JSONObject jsonObject = new JSONObject(userStr);
            String username = jsonObject.getStr("user_name");
            // TODO：判断凭证是否注销需要在此补充逻辑
            return !Objects.equals(redisTemplate.opsForValue().get(username + ":" + LOGIN_TOKEN), token);
        } catch (ParseException e) {
            return true;
        }
    }
}
