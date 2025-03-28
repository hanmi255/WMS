package com.zeroone.star.j1.dashboard.controller;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class TestDashboardController {
    @Test
    public void testQueryGoodsToUpNumberValidated() {
        DashboardController dashboardController = new DashboardController();
        dashboardController.queryGoodsUpNumberValidated(6);
    }
}
