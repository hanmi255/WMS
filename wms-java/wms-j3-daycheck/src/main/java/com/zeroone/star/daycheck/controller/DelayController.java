package com.zeroone.star.daycheck.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.daycheck.entity.Delay;
import com.zeroone.star.daycheck.service.DelayService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.delay.WaringAllDTO;
import com.zeroone.star.project.j3.daycheck.DelayApi;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;

@RestController
@RequestMapping("daycheck")
@Api(tags = "进货延时示警")
public class DelayController implements DelayApi {

    @Resource
    DelayService delayService;

    @Resource
    EasyExcelComponent excel;

    @SneakyThrows
    @ApiOperation(value = "下载文件")
    @GetMapping(value = "/delay/download", produces = "application/octet-stream")
    public ResponseEntity<byte[]> exportExcel() {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("delay",out, Delay.class,delayService.selectExcel());
        String filename = "delay-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment",filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(),headers, HttpStatus.CREATED);
        out.close();
        return result;
    }



    @GetMapping("/delay/im-delay")
    @ApiOperation(value = "获取延时货物列表")
    @Override
    public JsonVO<PageDTO<WaringAllDTO>> queryAll(
            @RequestParam Integer pageIndex,
            @RequestParam Integer pageSize) {
        PageDTO<WaringAllDTO> waring = delayService.selectAll(pageIndex,pageSize);

        return JsonVO.success(waring);
    }




}
