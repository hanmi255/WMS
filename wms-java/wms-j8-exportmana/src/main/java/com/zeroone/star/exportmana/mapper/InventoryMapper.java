package com.zeroone.star.exportmana.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j8.shipmentmana.inventorysummary.InventoryDTO;
import com.zeroone.star.project.query.j8.shipmentmana.inventorysummary.InventorySummaryQuery;
import org.apache.ibatis.annotations.Mapper;
import java.util.List;

/**
 * @author start
 * @since 2025-03-02
 */
@Mapper
public interface InventoryMapper extends BaseMapper<InventoryDTO> {
    default Page<InventoryDTO> selectInventoryList(InventorySummaryQuery query){
        Page<InventoryDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<InventoryDTO> queryWrapper = new QueryWrapper<>();
        queryWrapper.or(i->i.like("ku_wei_bian_ma",query.getStorageLocation()))
                .or(i->i.like("bin_id",query.getTray()))
                .or(i->i.like("goods_code",query.getGoodsNumber()))
                .or(i->i.like("shp_gui_ge",query.getGoodsName()));
        return this.selectPage(page,queryWrapper);
    }
}