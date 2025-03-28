package com.zeroone.star.sysmgr.config;
 
import io.swagger.models.auth.In;
import org.redisson.Redisson;
import org.redisson.api.RedissonClient;
import org.redisson.config.Config;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

/**
 *
 */
@Configuration
public class RedissonConfiguration {
 
    @Value("${spring.redis.host}")
    private String address;
 
    @Value("${spring.redis.port}")
    private String port;
 
    @Value("${spring.redis.password}")
    private String password;


    private final String timeout = "3000";
 
    @Bean
    public RedissonClient redisson() {
        Config config = new Config();

        if (password==null||"".equals(password)){
            config.useSingleServer()
                    .setAddress(address())
                    .setConnectTimeout(Integer.parseInt(timeout));
        }else {
            config.useSingleServer()
                    .setAddress(address())
                    .setPassword(password)
                    .setConnectTimeout(Integer.parseInt(timeout));
        }


        return Redisson.create(config);
    }
 
    /**
     * 生成address
     * @return
     */
    private String address() {
        return "redis://" + address + ":" + port;
    }
}