package com.zeroone.star.sysmanager.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * <p>
 * 描述：用户信息初始化
 * @author hamhuo
 * @version 1.0.0
 */
@Configuration
@ComponentScan(basePackages = {"com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.jwt"})
public class UserHolderInit {
}
