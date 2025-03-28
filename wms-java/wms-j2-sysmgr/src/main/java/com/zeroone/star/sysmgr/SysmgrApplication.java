package com.zeroone.star.sysmgr;

import cn.easyes.starter.register.EsMapperScan;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.data.mongodb.repository.config.EnableMongoRepositories;

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
@EsMapperScan("com.zeroone.star.sysmgr.mapper.es")
@MapperScan("com.zeroone.star.sysmgr.mapper")
public class SysmgrApplication {

    public static void main(String[] args) {

        SpringApplication.run(SysmgrApplication.class, args);
    }

}
