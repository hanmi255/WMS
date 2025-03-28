package com.zeroone.star.exportmana.mapper;

import com.zeroone.star.exportmana.entity.WaveToDown;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.*;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;

@Mapper(componentModel = "spring")
public interface MsWaveExportMapper {


    @Mappings({
            @Mapping(source = "cusName", target = "customerName"),
            @Mapping(source = "waveId", target = "waveNumber"),
            @Mapping(source = "goodsId", target = "goodsNumber"),
            @Mapping(source = "binId", target = "positions"),
            @Mapping(source = "firstRq", target = "containersRemove")
    })
    WaveExportBaseDTO toWaveExportBaseDTO(WaveToDown waveToDown);

    @Mapping(source = "createBy", target = "createdLoginMemberName")
    @Mapping(source = "createName", target = "createdMemberName")
    @Mapping(source = "cusCode", target = "goodsOwner")
    @Mapping(source = "cusName", target = "customerName")
    @Mapping(source = "waveId", target = "waveId")
    @Mapping(source = "goodsId", target = "goodsId")
    @Mapping(source = "goodsName", target = "goodsName")
    @Mapping(source = "imCusCode", target = "imCusCode")
    @Mapping(source = "binId", target = "positions")
    @Mapping(source = "tinId", target = "tray")
    @Mapping(source = "proData", target = "producedTime")
    @Mapping(source = "baseGoodscount", target = "goodsNumber")
    @Mapping(source = "baseUnit", target = "unit")
    @Mapping(source = "omBeiZhu", target = "omBeiZhu")
    @Mapping(source = "firstRq", target = "firstRq")
    @Mapping(source = "secondRq", target = "secondRq")
    @Mapping(source = "by1", target = "by1")
    @Mapping(source = "by2", target = "by2")
    @Mapping(source = "by3", target = "by3")
    @Mapping(source = "by4", target = "by4")
    @Mapping(source = "by5", target = "by5")
    WaveExportDetailDTO toWaveExportDetailDTO(WaveToDown waveToDown);

    @Mapping(source = "shpTiaoMa", target = "shpTiaoMa")
    @Mapping(source = "createBy", target = "createdLoginMemberName")
    @Mapping(source = "createName", target = "createdMemberName")
    @Mapping(source = "cusCode", target = "goodsOwner")
    @Mapping(source = "cusName", target = "customerName")
    @Mapping(source = "waveId", target = "waveId")
    @Mapping(source = "goodsId", target = "goodsId")
    @Mapping(source = "goodsName", target = "goodsName")
    @Mapping(source = "imCusCode", target = "imCusCode")
    @Mapping(source = "binId", target = "positions")
    @Mapping(source = "tinId", target = "tray")
    @Mapping(source = "proData", target = "producedTime")
    @Mapping(source = "baseGoodscount", target = "goodsNumber")
    @Mapping(source = "baseUnit", target = "unit")
    @Mapping(source = "omBeiZhu", target = "omBeiZhu")
    @Mapping(source = "firstRq", target = "firstRq")
    @Mapping(source = "secondRq", target = "secondRq")
    @Mapping(source = "by1", target = "by1")
    @Mapping(source = "by2", target = "by2")
    @Mapping(source = "by3", target = "by3")
    @Mapping(source = "by4", target = "by4")
    @Mapping(source = "by5", target = "by5")
    WaveExportExcelDTO toWaveExportExcelDTO(WaveToDown waveToDown);

    @Mappings({
            @Mapping(source = "createBy", target = "createdLoginMemberName"),
            @Mapping(source = "createName", target = "createdMemberName"),
            @Mapping(source = "cusCode", target = "goodsOwner"),
            @Mapping(source = "goodsName", target = "goodsName"),
            @Mapping(source = "imCusCode", target = "number"),
            @Mapping(source = "tinId", target = "tray"),
            @Mapping(source = "proData", target = "producedTime"),
            @Mapping(source = "baseGoodscount", target = "goodsNumbers"),
            @Mapping(source = "baseUnit", target = "unit"),
            @Mapping(source = "omBeiZhu",target = "message"),
            @Mapping(source = "secondRq", target = "containersSorting"),
            @Mapping(source = "cusName", target = "customerName"),
            @Mapping(source = "waveId", target = "waveNumber"),
            @Mapping(source = "goodsId", target = "goodsNumber"),
            @Mapping(source = "binId", target = "positions"),
            @Mapping(source = "firstRq", target = "containersRemove")
    })
    WaveExportListDTO toWaveExportListDTO(WaveToDown waveToDown);

    @Mapping(source = "binId", target = "positions")
    @Mapping(source = "goodsName", target = "goodsName")
    @Mapping(source = "baseUnit", target = "unit")
    @Mapping(source = "proData", target = "producedTime")
    @Mapping(source = "baseGoodscount", target = "goodsNumber")
    @Mapping(source = "cusCode", target = "goodsOwner")
    @Mapping(source = "omBeiZhu", target = "message")
    @Mapping(source = "tinId", target = "tuoPan")
    @Mapping(source = "shpTiaoMa", target = "qrCode")
    WaveExportPrintDTO toWaveExportPrintDTO(WaveToDown waveToDown);


}


