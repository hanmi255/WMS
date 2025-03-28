package com.zeroone.star.login.config;

import com.zeroone.star.project.config.redis.RedisConfig;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;

/**
 * 描述：redis配置类
 *
 * @author nefertari
 * @version 1.0.0
 */
@Configuration
@Import(RedisConfig.class)
public class LoginRedisConfig {
}
