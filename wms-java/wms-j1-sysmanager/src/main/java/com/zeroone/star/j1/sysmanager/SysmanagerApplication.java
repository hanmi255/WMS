package com.zeroone.star.j1.sysmanager;

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
 * @author 图团
 * @since 2023/7/19
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
public class SysmanagerApplication {

    public static void main(String[] args) {
        SpringApplication.run(SysmanagerApplication.class, args);
    }

}
