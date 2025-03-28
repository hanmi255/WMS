package com.zeroone.star.baseConfig.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.AutomaticEncoding;
import com.zeroone.star.baseConfig.mapper.ExcelAutomaticEncodingMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.AutomaticEncodingDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.DeleteEncodingDTO;
import com.zeroone.star.project.query.j4.automaticEncoding.AutomaticEncodingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.automaticEncoding.DeleteEncodingVO;
import lombok.SneakyThrows;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author lzm
 * @since 2025-02-22
 */
public interface AutomaticEncodingService extends IService<AutomaticEncoding> {
    /**
     * 分页条件查询所有
     * @param condition
     * @return
     */
    PageDTO<AutomaticEncodingDTO> queryAll(AutomaticEncodingQuery condition);

    /**
     * 保存或修改
     * @param dto
     * @return
     */
    AutomaticEncodingDTO doSaveOrUpdate(AutomaticEncodingDTO dto);

    void saveBatch(List<ExcelAutomaticEncodingMapper> importedData);
    JsonVO<List<DeleteEncodingVO>> deleteEncoding(@RequestBody DeleteEncodingDTO dto);

    @SneakyThrows
    ResponseEntity<byte[]> exportExcel(
            String create_name,
            String endDate,
            String[] ids,
            String startDate,
            String exportDTO);
    /*String importExcel(importExcelDTO dto);*/

}
