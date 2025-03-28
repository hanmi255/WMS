package com.zeroone.star.daycheck.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * @author Vast
 * @version 1.0
 * @function: Mp初始化
 */
@SuppressWarnings({"all"})
@Configuration
@ComponentScan({"com.zeroone.star.project.config.mybatis", "com.zeroone.star.project.components.easyexcel"})
public class MPInit {
}
