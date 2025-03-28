package com.zeroone.star.exportmana.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.exportmana.entity.InTransitStock;
import com.zeroone.star.project.query.j8.shipmentmana.intransitstock.InTransitStockQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * @ClassName: InTransitStockMapper
 * @Package: com.zeroone.star.intransitstock.mapper
 * @Description:
 * @Author: zk
 * @Create: 2025/2/27 - 下午10:18
 */
@Mapper
public interface InTransitStockMapper extends BaseMapper<InTransitStock> {

    Page<InTransitStock> select(Page<InTransitStock> page, @Param("query") InTransitStockQuery query);
}
