package com.zeroone.star.othermana;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * <p>
 * 描述：程序启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author yjq
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
public class OthermanaApplication {

    public static void main(String[] args) {
        SpringApplication.run(OthermanaApplication.class, args);
    }

}
