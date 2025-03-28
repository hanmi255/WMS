package com.zeroone.star.project.j8.shipmentmana;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportDetailDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportPrintDTO;
import com.zeroone.star.project.query.j8.shipmentmana.waveexport.WaveExportQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

import java.util.List;

public interface WaveExportApis {

    /**
     * 导出波次列表
     * @param query
     * @return
     */
    JsonVO<Page<WaveExportListDTO>> queryWaveExportList(WaveExportQuery query);

    /**
     * 根据波次的id展示详细信息
     * @param waveId
     * @return
     */
    JsonVO<WaveExportDetailDTO> queryWaveExportDetail(String waveId);

    /**
     * 根据波次编号查出导出打印数据
     * @param waveId
     * @return
     */
    public ResponseEntity<byte[]> queryWaveExportPrint(String waveId);

    /**
     * 将数据导出为Excel表格
     * @param waveIds
     * @return
     */
    ResponseEntity<byte[]> WaveExportExcel(List<String> waveIds);

}
