package com.zeroone.star.oauth2.service.impl.oauth2;

import com.zeroone.cloud.starter.oauth2.service.TokenGranterExtService;
import com.zeroone.cloud.starter.oauth2.service.impl.CompositeTokenGranterWrapper;
import com.zeroone.star.oauth2.granter.MobileTokenGranter;
import com.zeroone.star.oauth2.service.ITSRoleService;
import com.zeroone.star.oauth2.service.ITSUserService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：实现扩展TokenGranter服务，用于附加自定义授权模式
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class TokenGranterExtServiceImpl implements TokenGranterExtService {
    @Resource
    ITSUserService userService;

    @Resource
    ITSRoleService roleService;

    @Override
    public void configExtGranter(CompositeTokenGranterWrapper granterWrapper) {
        granterWrapper.addTokenGranter(new MobileTokenGranter(
                userService,
                roleService,
                granterWrapper.endpointsConfigurer.getTokenServices(),
                granterWrapper.endpointsConfigurer.getClientDetailsService(),
                granterWrapper.endpointsConfigurer.getOAuth2RequestFactory()));
    }
}
