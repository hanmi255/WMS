package com.zeroone.star.baseConfig.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.BaUnitType;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeListDTO;
import com.zeroone.star.project.query.j4.unitType.UnitTypeListQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author 1+5
 * @title BaUnitTypeService
 * @date 2025/2/23 23 11
 * @description
 */


public interface BaUnitTypeService extends IService<BaUnitType> {

    /**
     *  获取单位类型名称列表
     * @param
     * @return 响应数据结果
     */
    JsonVO<List<String>> getUnitTypeNameList( );

    /**
     *  获取单位类型列表（条件+分页）
     * @param unitTypeListQuery 单位类型查询
     * @return 响应数据结果
     */
    JsonVO<PageDTO<UnitTypeListDTO>> getUnitTypeList(UnitTypeListQuery unitTypeListQuery);
}
