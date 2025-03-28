package com.zeroone.star.exportmana.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.exportmana.entity.InTransitStock;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j8.shipmentmana.intransitstock.InTransitStockQuery;
import com.zeroone.star.project.vo.j8.shipmentmana.intransitstock.InTransitStockVO;
import org.springframework.http.ResponseEntity;

/**
 * @ClassName: InTransitStockService
 * @Package: com.zeroone.star.intransitstock.service
 * @Description:
 * @Author: zk
 * @Create: 2025/2/27 - 下午10:16
 */
public interface IInTransitStockService extends IService<InTransitStock> {
    /**
     * 多条件查询在途库存
     * @param query 查询参数
     * @return 在途库存列表
     */
    PageDTO<InTransitStockVO> listTransitStock(InTransitStockQuery query);

    /**
     * 导出在途库存信息
     *
     * @param query 查询条件
     * @return ResponseEntity<byte[]> 响应实体，包含导出的文件字节数组
     */
    ResponseEntity<byte[]> exportTransitStock(InTransitStockQuery query);
}
