package com.zeroone.star.baseConfig.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.baseConfig.entity.UnitType;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeAddDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeModifyDTO;
import com.zeroone.star.project.query.j4.unitType.UnitTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 计量单位类型 服务类
 * </p>
 *
 * @author Dorain
 * @since 2025-02-22
 */
public interface UnitTypeService extends IService<UnitType> {

    @Transactional(rollbackFor = Exception.class)
    JsonVO<String> addUnitType(UnitTypeAddDTO dto);

    @Transactional(rollbackFor = Exception.class)
    JsonVO<String> updateUnitType(UnitTypeModifyDTO dto);



    @Transactional(rollbackFor = Exception.class)
    JsonVO<String> deleteBatchUnitType(List<String> ids);

    List<UnitType> queryUnitTypes(UnitTypeQuery query);

    void importParameterType(MultipartFile file);
}
