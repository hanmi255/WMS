package com.zeroone.star.exportmana.controller;

import com.zeroone.star.exportmana.service.InventorySummaryService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.shipmentmana.InventorySummaryApis;
import com.zeroone.star.project.query.j8.shipmentmana.inventorysummary.InventorySummaryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.shipmentmana.inventorysummary.InventorySummaryVo;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */
@RestController
@RequestMapping("exportmana")
@Api(tags = "库存总表")
public class InventorySummaryController implements InventorySummaryApis {

    @Resource
    private InventorySummaryService inventorySummaryService;

    @GetMapping("/inventory/query-inventory")
    @ApiOperation("查询库存总表")
    @Override
    public JsonVO<PageDTO<InventorySummaryVo>> queryInventorySummary(InventorySummaryQuery query) {
        PageDTO<InventorySummaryVo> inventoryPages = inventorySummaryService.queryInventorySummary(query);
        return JsonVO.success(inventoryPages);
    }

    @PostMapping("/inventory/export-inventory")
    @ApiOperation("导出库存总表")
    @Override
    public ResponseEntity<byte[]> exportInventoryToExcel(InventorySummaryQuery query) {
        return inventorySummaryService.exportInventoryToExcel(query);
    }
}
