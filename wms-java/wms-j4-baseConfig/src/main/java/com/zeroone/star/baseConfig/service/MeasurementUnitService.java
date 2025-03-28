package com.zeroone.star.baseConfig.service;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementNameListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;

import java.util.List;

/**
 * @author adi
 * #Description  计量单位服务层接口
 * #Date: 2025/2/23 22:25
 */
public interface MeasurementUnitService {


    JsonVO<PageDTO<MeasurementUnitVO>> queryMeasurementUnitList(MeasurementListQuery query);

    List<String> queryMeasurementUnitNameList(MeasurementNameListQuery query);
}
