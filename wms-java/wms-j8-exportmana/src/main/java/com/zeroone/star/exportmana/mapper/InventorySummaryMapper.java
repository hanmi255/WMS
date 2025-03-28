package com.zeroone.star.exportmana.mapper;

import com.zeroone.star.project.dto.j8.shipmentmana.inventorysummary.InventoryDTO;
import com.zeroone.star.project.vo.j8.shipmentmana.inventorysummary.InventorySummaryVo;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

import java.util.List;

@Mapper(componentModel = "spring")
public interface InventorySummaryMapper {
    // 单个对象的映射
    @Mapping(source = "kuWeiBianMa", target = "storageLocation")
    @Mapping(source = "binId", target = "tray")
    @Mapping(source = "goodsCode", target = "goodsNumber")
    @Mapping(source = "shpMingCheng", target = "goodsName")
    @Mapping(source = "shpGuiGe", target = "specification")
    @Mapping(source = "baseUnit", target = "unit")
    @Mapping(source = "baseGoodscount", target = "totalStock")
    @Mapping(source = "daixiaj", target = "pendingRemovalStock")
    @Mapping(source = "keyongkucun", target = "availableStock")
    @Mapping(source = "goodsProData", target = "producedTime")
    @Mapping(source = "bzhiQi", target = "shelfLife")
    @Mapping(source = "dqr", target = "expirationDate")
    @Mapping(source = "kuWeiLeiXing", target = "storageLocationType")
    InventorySummaryVo toInventorySummaryVo(InventoryDTO dto);

    // 列表对象的映射
    List<InventorySummaryVo> toInventorySummaryVos(List<InventoryDTO> dtos);
}