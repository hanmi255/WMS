package com.zeroone.star.daycheck.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.daycheck.entity.NoUpGoods;
import com.zeroone.star.daycheck.service.NoUpService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.j3.daycheck.Arr.NoUpGoodsDTO;
import com.zeroone.star.project.j3.daycheck.NoUpApis;
import com.zeroone.star.project.query.j3.daycheck.Arr.NoUpGoodsQuery;
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
 * @date 2025/2/22 14:05
 */
@Controller
@RequestMapping("/daycheck/no-up")
@Api(tags = "收货未上架")
@Validated
public class NoUpController implements NoUpApis {

    @Resource
    NoUpService noUpService;

    @Resource
    EasyExcelComponent excel;

    @GetMapping("/get-no-up-goods")
    @ResponseBody
    @ApiOperation(value = "获取出货未上架")
    @Override
    public JsonVO<List<NoUpGoodsDTO>> getNoUpGoods(NoUpGoodsQuery condition) {
        List<NoUpGoodsDTO> result = noUpService.getNoUpGoodsPage(condition);
        return JsonVO.success(result);
    }

    @SneakyThrows
    @GetMapping("/download")
    @ApiOperation(value = "获取当前条件下的数据excel")
    @Override
    public ResponseEntity<byte[]> downLoadNoUp() {
        List<NoUpGoods> data = noUpService.getDate();
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("sheet1",out,NoUpGoods.class,data);
        String fileName = "excel--" + DateTime.now().toString("yyyyMMdd") + ".xlsx";
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.setContentDispositionFormData("attachment", fileName);
        httpHeaders.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), httpHeaders, HttpStatus.CREATED);
        out.close();
        return result;
    }
}
