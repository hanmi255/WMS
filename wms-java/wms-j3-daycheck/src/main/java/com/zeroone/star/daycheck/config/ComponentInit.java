package com.zeroone.star.daycheck.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.ComponentScans;
import org.springframework.context.annotation.Configuration;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/25 15:16
 */
@Configuration
@ComponentScan({"com.zeroone.star.project.components.fastdfs","com.zeroone.star.project.components.easyexcel","com.zeroone.star.project.components.user","com.zeroone.star.project.components.jwt"})
public class ComponentInit {
}
