package com.zeroone.star.exportmana.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.exportmana.entity.WaveToDown;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportDetailDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportExcelDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportPrintDTO;
import com.zeroone.star.project.query.j8.shipmentmana.waveexport.WaveExportQuery;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * VIEW 服务类
 * </p>
 *
 * @author wuven
 * @since 2025-03-06
 */
public interface WaveToDownService extends IService<WaveToDown> {

    WaveExportPrintDTO getPrintDTO(String waveId);

    Page<WaveExportListDTO> listAllWaveExport(WaveExportQuery query);

    List<WaveExportExcelDTO> exportExcel(List<String> waveIds);

    WaveExportDetailDTO listDetailWaveExport(String id);
}
