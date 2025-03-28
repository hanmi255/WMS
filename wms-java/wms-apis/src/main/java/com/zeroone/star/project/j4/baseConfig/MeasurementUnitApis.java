package com.zeroone.star.project.j4.baseConfig;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.measurementUnit.MeasurementUnitDTO;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementNameListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementUnitQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author qiaozhi
 * @title MeasurementUnitApis
 * @date 2025/2/21 21:59
 * @description 计量单位apis
 */
public interface MeasurementUnitApis {
    /**
     * 获取计量单位列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<MeasurementUnitVO>> queryMeasurementUnitList(MeasurementListQuery query);
    /**
     * 获取计量单位名称列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<List<String>> queryMeasurementUnitNameList(MeasurementNameListQuery query);

    /**
     * 录入计量单位
     * @param measurementUnitDTO 计量单位信息
     * @return 响应数据结果
     */
    JsonVO<MeasurementUnitVO> insertUnit(MeasurementUnitDTO measurementUnitDTO);

    /**
     * 修改计量单位
     * @param measurementUnitDTO 计量单位信息
     * @return 响应数据结果
     */
    JsonVO<MeasurementUnitVO> updateUnit(MeasurementUnitDTO measurementUnitDTO);

    /**
     * 删除计量单位(支持批量删除)
     * @param measurementUnitListDTO 计量单位信息集合(一个或多个)
     * @return 响应数据结果
     */
    JsonVO<String> deleteUnit(List<MeasurementUnitDTO> measurementUnitListDTO);

    /**
     * 导入计量单位
     * @return
     */
    ResponseEntity<String> importMeasurementUnit(@RequestParam("file") MultipartFile file);

    /**
     * 导出计量单位
     * @return
     */
    ResponseEntity<byte[]> expoMeasurementUnit(MeasurementUnitQuery query);

}
