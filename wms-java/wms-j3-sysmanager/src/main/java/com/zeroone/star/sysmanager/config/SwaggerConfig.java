package com.zeroone.star.sysmanager.config;

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
        return SwaggerCore.defaultDocketBuilder("j3系统管理（数据字典、系统图标、分类管理、国际化语言）","com.zeroone.star.sysmanager.controller","sysmanager");
    }
}
