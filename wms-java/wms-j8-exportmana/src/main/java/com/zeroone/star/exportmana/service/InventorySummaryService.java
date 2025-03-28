package com.zeroone.star.exportmana.service;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.inventorysummary.InventoryDTO;
import com.zeroone.star.project.query.j8.shipmentmana.inventorysummary.InventorySummaryQuery;
import com.zeroone.star.project.vo.j8.shipmentmana.inventorysummary.InventorySummaryVo;
import org.springframework.http.ResponseEntity;

public interface InventorySummaryService {
    PageDTO<InventorySummaryVo> queryInventorySummary(InventorySummaryQuery query);
    ResponseEntity<byte[]> exportInventoryToExcel(InventorySummaryQuery query);
}