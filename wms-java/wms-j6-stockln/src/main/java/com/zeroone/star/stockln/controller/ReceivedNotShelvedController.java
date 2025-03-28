package com.zeroone.star.stockln.controller;

import com.zeroone.star.project.j6.stockln.ReceivedNotShelvedApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "收货未上架")
@RestController
@RequestMapping("/stock/not-shelved")
public class ReceivedNotShelvedController implements ReceivedNotShelvedApis {
}
