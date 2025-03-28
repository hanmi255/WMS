package com.zeroone.star.stockln.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.WvStockDTO;
import com.zeroone.star.project.j6.stockln.StockQueryApis;
import com.zeroone.star.project.query.j6.stockln.WvStockQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.stockln.service.IWvStockService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

@Api(tags = "库存查询")
@RestController
@RequestMapping("/stock/inventory-query")
public class StockQueryController implements StockQueryApis {
    @Resource
    IWvStockService Service;

    @Resource
    EasyExcelComponent excel;

    private List<WvStockDTO> WvStockDTOList;

    @GetMapping("query-all")
    @ApiOperation(value = "分页查询库存接口")
    @Override
    public JsonVO<PageDTO<WvStockDTO>> queryAllStock(WvStockQuery condition) {
        PageDTO<WvStockDTO> pageDTO = Service.listallStock(condition);
        WvStockDTOList =pageDTO.getRows();
        return JsonVO.success(pageDTO);
    }

    @SneakyThrows
    @ApiOperation(value = "导出库存报表")
    @GetMapping(value = "export",produces = "application/octet-stream")
    public ResponseEntity<byte[]> exportExcel(RedirectAttributes redirectAttributes) {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("WvStockDTO", out, WvStockDTO.class, WvStockDTOList);
        String filename = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.IMAGE_JPEG);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }
}
