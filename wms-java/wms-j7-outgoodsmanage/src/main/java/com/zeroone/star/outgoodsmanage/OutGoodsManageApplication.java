package com.zeroone.star.outgoodsmanage;

//import com.zeroone.star.outgoodsmanage.channel.*;
import com.zeroone.star.outgoodsmanage.channel.MySink;
import com.zeroone.star.outgoodsmanage.channel.MySource;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.stream.annotation.EnableBinding;

/**
 * <p>
 * 描述：出货管理模块启动类
 * </p>
 *
 * @author chen
 * @since 2025/2/22 17:23
 */

@SpringBootApplication
@EnableDiscoveryClient
@EnableBinding({MySource.class, MySink.class})
public class OutGoodsManageApplication {
    public static void main(String[] args) {
        SpringApplication.run(OutGoodsManageApplication.class,args);
    }
}
