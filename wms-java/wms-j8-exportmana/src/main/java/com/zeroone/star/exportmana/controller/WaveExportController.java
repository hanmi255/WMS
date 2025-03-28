package com.zeroone.star.exportmana.controller;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.exportmana.service.WaveToDownService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.pdf.PdfComponent;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportDetailDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportExcelDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportPrintDTO;
import com.zeroone.star.project.j8.shipmentmana.WaveExportApis;
import com.zeroone.star.project.query.j8.shipmentmana.waveexport.WaveExportQuery;
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
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("exportmana")
@Api(tags = "波次导出")
public class WaveExportController implements WaveExportApis {

    @Resource
    WaveToDownService waveToDownService;

    @Resource
    EasyExcelComponent easyExcelComponent;

    @Resource
    PdfComponent pdfComponent;

    @GetMapping("/WaveExport/query-list")
    @ApiOperation(value = "查询波次列表接口")
    @Override
    public JsonVO<Page<WaveExportListDTO>> queryWaveExportList(WaveExportQuery query) {
        Page<WaveExportListDTO> page = waveToDownService.listAllWaveExport(query);
        return JsonVO.success(page);
    }

    @GetMapping("/WaveExport/query-one")
    @ApiOperation(value = "详细查询波次接口")
    @Override
    public JsonVO<WaveExportDetailDTO> queryWaveExportDetail(@RequestParam String waveId) {
        System.out.println("查询波次的详细信息");
        WaveExportDetailDTO waveExportDetailDTO = waveToDownService.listDetailWaveExport(waveId);
        return JsonVO.success(waveExportDetailDTO);
    }

    @SneakyThrows
    @GetMapping("/WaveExport/query-print")
    @ApiOperation(value = "查询打印内容接口")
    @Override
    public ResponseEntity<byte[]> queryWaveExportPrint(String waveId) {

        //获得要显示的内容
        WaveExportPrintDTO printDTO = waveToDownService.getPrintDTO(waveId);
        //构建要传入的对象
        Map<String,Object> data = new HashMap<>();
        ArrayList<WaveExportPrintDTO> list = new ArrayList<>();
        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        //向前端返回导出的pdf文件流
        pdfComponent.generateToStream("wms-j8-exportmana/src/main/resources/freemarker/pdf.fo",data,out);
        String date = DateTime.now().toString("yyyy-MM-dd");
        data.put("date", date);
        data.put("orderNumber",waveId);
        data.put("location",printDTO.getPositions());
        data.put("product",printDTO.getGoodsName());
        data.put("unit",printDTO.getUnit());
        data.put("productionDate",printDTO.getProducedTime());
        data.put("quantity",printDTO.getGoodsNumber());
        data.put("owner",printDTO.getGoodsOwner());
        data.put("remark",printDTO.getMessage());
        data.put("pallet",printDTO.getTuoPan());
        data.put("keywords",printDTO.getQrCode());
        data.put("qrcodeUrl", "http://qr.service/order-B020250301204217");
        data.put("url","https://www.x-easypdf.cn");
        //响应文件数据
        String filename = "pdf-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".pdf";
        out.close();

        return ResponseEntity.ok()
                .header(HttpHeaders.CONTENT_DISPOSITION, "inline; filename=\"" + filename + "\"") // inline直接展示
                .contentType(MediaType.APPLICATION_PDF) // 正确设置PDF MIME类型
                .body(out.toByteArray());
    }

    @SneakyThrows
    @GetMapping(value = "/WaveExport/exportExcel",produces = "application/octet-stream")
    @ApiOperation("查询并导出excel的接口")
    @Override
    public ResponseEntity<byte[]> WaveExportExcel(@RequestParam List<String> waveIds) {
        //在使用前需要导出EasyExcel的配置类
        //先获得要导出为Excel的数据
        List<WaveExportExcelDTO> exportExcelDTOS = waveToDownService.exportExcel(waveIds);

        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        easyExcelComponent.export("WaveExport",out, WaveExportExcelDTO.class,exportExcelDTOS);

        // 响应文件数据
        String filename = "img-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();

        return result;
    }


}
