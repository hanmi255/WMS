package com.zeroone.star.login.service;

import com.zeroone.cloud.oauth2.entity.Oauth2Token;
import com.zeroone.star.login.fallback.OauthServiceFallbackFactory;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.Map;

/**
 * <p>
 * 描述：授权声明式服务接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@FeignClient(value = "${sn.auth}", fallbackFactory = OauthServiceFallbackFactory.class)
public interface OauthService {
    /**
     * 声明式调用授权服务
     * @param parameters 参数列表
     * @return 授权数据
     */
    @PostMapping("/oauth/token")
    Oauth2Token postAccessToken(@RequestParam Map<String, String> parameters);
}
