package com.zeroone.star.exportmana.controller;

import com.zeroone.star.exportmana.service.IInTransitStockService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.shipmentmana.InTransitStockApis;
import com.zeroone.star.project.query.j8.shipmentmana.intransitstock.InTransitStockQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.shipmentmana.intransitstock.InTransitStockVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @ClassName: InTransitStockController
 * @Package: com.zeroone.star.intransitstock.controller
 * @Description: 在途库存
 * @Author: zk
 * @Create: 2025/2/26 - 上午11:30
 */
@RestController
@RequestMapping("exportmana")
@Api(tags = "在途库存")
@RequiredArgsConstructor
public class InTransitStockController implements InTransitStockApis {
    // 注入IInTransitStockService接口的实现类
    private final IInTransitStockService transitStockService;


    // 查询在途库存
    @GetMapping("/intransitstock/query-intransitstock")
    @ApiOperation(value = "查询在途库存")
    @Override
    public JsonVO<PageDTO<InTransitStockVO>> queryInTransitStock(InTransitStockQuery query) {
        // 调用transitStockService的listTransitStock方法，传入query参数，返回PageDTO<InTransitStockVO>类型的数据
        PageDTO<InTransitStockVO> res = transitStockService.listTransitStock(query);
        return JsonVO.success(res);
    }

    // 导出在途库存
    @GetMapping("/intransitstock/export-intransitstock")
    @ApiOperation(value = "导出在途库存")
    @Override
    public ResponseEntity<byte[]> exportInTransitStock(InTransitStockQuery query) {
        // 调用transitStockService的exportTransitStock方法，传入query参数，返回ResponseEntity<byte[]>类型的数据
        return transitStockService.exportTransitStock(query);
    }
}
