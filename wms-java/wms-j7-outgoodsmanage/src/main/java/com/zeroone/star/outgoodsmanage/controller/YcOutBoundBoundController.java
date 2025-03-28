package com.zeroone.star.outgoodsmanage.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.outgoodsmanage.config.ExcelConfig;
import com.zeroone.star.outgoodsmanage.service.IYcOutBoundService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.ycoutbound.YcOutBoundDTO;
import com.zeroone.star.project.j7.ycoutbound.YcOutBoundApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j7.ycoutbound.YcOutBoundQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.List;

/**
 * <p>
 * 描述：异常出库通知 控制器
 * </p>
 *
 * @author keyuan
 * @since 2025/2/26 下午 5:55
 */
@RestController
@RequestMapping("/yc-outbound/")
@Api(tags = "异常出库通知明细相关接口")
public class YcOutBoundBoundController implements YcOutBoundApis {
    @Autowired
    private IYcOutBoundService ycOutBoundService;

    @Autowired
    private EasyExcelComponent excel;

    @GetMapping("query-all")
    @ApiOperation("获取异常出库通知明细列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<YcOutBoundDTO>> queryAll(YcOutBoundQuery query) {
        return JsonVO.success(ycOutBoundService.queryAll(query));
    }

    @SneakyThrows
    @GetMapping(value = "export-excel", produces = "application/octet-stream")
    @ApiOperation("导出异常出库通知数据")
    @Override
    public ResponseEntity<byte[]> exportExcel() {
        YcOutBoundQuery query = new YcOutBoundQuery();
        query.setPageIndex(1L);
        query.setPageSize(ycOutBoundService.getPageSize());

        //获取数据
        PageDTO<YcOutBoundDTO> pageDTO = ycOutBoundService.queryAll(query);
        List<YcOutBoundDTO> data = pageDTO.getRows();

        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("ycOutBoundDTO", out, YcOutBoundDTO.class, data);
        // 响应文件数据
        String filename = "异常出库通知报表" + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        ContentDisposition contentDisposition = ContentDisposition
                .builder("attachment")
                .filename(filename, StandardCharsets.UTF_8)  // 设置文件名和编码
                .build();
        headers.setContentDisposition(contentDisposition);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }
}
