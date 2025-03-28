package com.zeroone.star.project.j8.shipmentmana;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j8.shipmentmana.intransitstock.InTransitStockQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.shipmentmana.intransitstock.InTransitStockVO;
import org.springframework.http.ResponseEntity;

/**
 * @ClassName: InTransitStockApis
 * @Package: com.zeroone.star.project.j8.shipmentmana.intransitstock
 * @Description: 在途库存接口
 * @Author: zk
 * @Create: 2025/2/26 - 上午10:52
 */

public interface InTransitStockApis {
    /**
     * 获取在途库存列表(条件+分页)
     * @param query 查询条件
     * @return 在途库存列表
     */
    JsonVO<PageDTO<InTransitStockVO>> queryInTransitStock(InTransitStockQuery query);

    /**
     * 导出在途库存列表
     * @param query 查询条件
     * @return
     */
    ResponseEntity<byte[]> exportInTransitStock(InTransitStockQuery query);
}
