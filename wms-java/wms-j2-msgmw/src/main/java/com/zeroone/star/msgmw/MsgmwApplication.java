package com.zeroone.star.msgmw;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.ComponentScan;

/**
 * <p>
 * 描述：程序启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@ComponentScan(basePackages = {"com.zeroone.star.project.components.user","com.zeroone.star.project.components.jwt","com.zeroone.star.msgmw"})
public class MsgmwApplication {
    public static void main(String[] args) {
        SpringApplication.run(MsgmwApplication.class, args);
    }

}
