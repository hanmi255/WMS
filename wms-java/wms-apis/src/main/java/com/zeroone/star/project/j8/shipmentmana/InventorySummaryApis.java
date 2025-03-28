package com.zeroone.star.project.j8.shipmentmana;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.inventorysummary.InventoryDTO;
import com.zeroone.star.project.query.j8.shipmentmana.inventorysummary.InventorySummaryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.shipmentmana.inventorysummary.InventorySummaryVo;
import org.springframework.http.ResponseEntity;

/**
 * 库存总表业务接口
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */
public interface InventorySummaryApis {
    JsonVO<PageDTO<InventorySummaryVo>> queryInventorySummary(InventorySummaryQuery query);

    ResponseEntity<byte[]> exportInventoryToExcel(InventorySummaryQuery query);
}
