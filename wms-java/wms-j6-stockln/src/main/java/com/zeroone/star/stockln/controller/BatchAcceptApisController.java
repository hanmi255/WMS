package com.zeroone.star.stockln.controller;


import com.zeroone.star.project.j6.stockln.BatchAcceptApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "批量收货")
@RestController
@RequestMapping("/stock/batch-accept")
public class BatchAcceptApisController implements BatchAcceptApis {
}
