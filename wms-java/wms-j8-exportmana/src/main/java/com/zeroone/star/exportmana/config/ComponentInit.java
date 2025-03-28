package com.zeroone.star.exportmana.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan({"com.zeroone.star.project.components.easyexcel","com.zeroone.star.project.components.pdf"})
public class ComponentInit {
}
