package com.zeroone.star.daycheck.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @author Vast
 * @version 1.0
 * @function:Swagger配置
 */
@SuppressWarnings({"all"})
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket sysmanagerApi(){
        return SwaggerCore.defaultDocketBuilder("j3每日检查","com.zeroone.star.daycheck.controller","daycheck");
    }
}
