package com.zeroone.star.oauth2;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.security.crypto.password.PasswordEncoder;

import javax.annotation.Resource;

@SpringBootTest
class Oauth2ApplicationTests {
    @Resource
    PasswordEncoder passwordEncoder;

    @Test
    void contextLoads() {
        System.out.println(passwordEncoder.matches("123456","$2a$10$HXENiHggO0u86R7x2iuex.EHvI5B7yxzMjIzP3OdSktiYnh3p5trq"));
    }

}
