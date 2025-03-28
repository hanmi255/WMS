package com.zeroone.star.stockln.controller;

import com.zeroone.star.project.j6.stockln.ImNoticeIApis;
import io.swagger.annotations.Api;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "进货通知明细")
@RestController
@RequestMapping("/stock/imNotice-detail")
public class ImNoticeIController implements ImNoticeIApis {
}
