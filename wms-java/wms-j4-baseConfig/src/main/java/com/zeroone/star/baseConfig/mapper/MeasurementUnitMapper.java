package com.zeroone.star.baseConfig.mapper;


import com.zeroone.star.project.query.j4.measurementUnit.MeasurementListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementNameListQuery;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * 接口
 *
 * @author adi
 * #Date: 2025/3/8 08:11
 */
@Mapper
public interface MeasurementUnitMapper {
    
    /**
     * 查询计量单位列表
     * @param query 查询条件
     * @return 计量单位列表
     */
    List<MeasurementUnitVO> queryMeasurementUnitList(MeasurementListQuery query);

    /**
     * 查询计量单位名称列表
     * @param query 查询条件
     * @return 计量单位名称列表
     */
    List<String> queryMeasurementUnitNameList(MeasurementNameListQuery query);

    /**
     * 查询总记录数
     * @param query 查询条件
     * @return 总记录数
     */
    Long countTotal(MeasurementListQuery query);
}
