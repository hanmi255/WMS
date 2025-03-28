package com.zeroone.star.daycheck.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.daycheck.entity.YichangDown;
import com.zeroone.star.daycheck.service.YichangDownService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.j3.daycheck.Arr.YichangDownDTO;
import com.zeroone.star.project.j3.daycheck.YichangDownApis;
import com.zeroone.star.project.query.j3.daycheck.Arr.YichangDownQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/22 14:12
 */
@Controller
@RequestMapping("/daycheck/yi-chang")
@Api(tags = "出货异常")
@Validated
public class YichangDownContrller implements YichangDownApis {

    @Resource
    YichangDownService yichangDownService;

    @Resource
    EasyExcelComponent excel;

    @GetMapping("/get-yichang-down")
    @ResponseBody
    @ApiOperation(value = "获取出库异常")
    @Override
    public JsonVO<List<YichangDownDTO>> getYichangDown(YichangDownQuery condition) {
        List<YichangDownDTO> yichangList =  yichangDownService.getYichangDownPage(condition);
        return JsonVO.success(yichangList);
    }

    @SneakyThrows
    @GetMapping("/download")
    @ApiOperation(value = "获取当前条件下的数据excel")
    @Override
    public ResponseEntity<byte[]> downLoadYicchang() {
        List<YichangDown> data = yichangDownService.getYichangDownDate();
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("sheet1",out,YichangDown.class,data);
        String fileName = "excel--" + DateTime.now().toString("yyyyMMdd") + ".xlsx";
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.setContentDispositionFormData("attachment", fileName);
        httpHeaders.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), httpHeaders, HttpStatus.CREATED);
        out.close();
        return result;
    }
}
