package com.zeroone.star.baseConfig.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.BaMeasurementUnit;
import com.zeroone.star.project.dto.j4.measurementUnit.MeasurementUnitDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;

import java.util.List;

/**
 * @author 1+5
 * @title   MeasurementUnitService
 * @date 2025/2/23 14 43
 * @description 计量单位服务层接口
 */

public interface BaMeasurementUnitService extends IService<BaMeasurementUnit> {

    /**
     * 处理添加计量单位
     * @param measurementUnitDTO 计量单位信息
     * @return 响应数据结果
     */
    JsonVO<MeasurementUnitVO> insertUnit(MeasurementUnitDTO measurementUnitDTO);

    /**
     * 处理修改计量单位
     * @param measurementUnitDTO 计量单位信息
     * @return 响应数据结果
     */
    JsonVO<MeasurementUnitVO> updateUnit(MeasurementUnitDTO measurementUnitDTO);

    /**
     * 处理删除计量单位(支持批量删除)
     * @param measurementUnitListDTO 计量单位信息集合(一个或多个)
     * @return 响应数据结果
     */
    JsonVO<String> deleteUnit(List<MeasurementUnitDTO> measurementUnitListDTO);

}
