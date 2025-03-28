package com.zeroone.star.j1.sysmanager.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

/**
 *
 *  PingShui
 *  2025/2/26 16:00
 */
@Configuration
@ComponentScan({"com.zeroone.star.project.components.jwt", "com.zeroone.star.project.components.user"})
public class AppComponent {
    @Bean
    PasswordEncoder passwordEncoder(){
        return new BCryptPasswordEncoder() {
        };
    }
}
