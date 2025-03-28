package com.zeroone.star.outgoodsmanage.service.impl;


import com.zeroone.star.outgoodsmanage.entity.LoadCheckDO;
import com.zeroone.star.outgoodsmanage.entity.OutDetailDO;
import com.zeroone.star.outgoodsmanage.entity.OutDetailExcelDO;
import com.zeroone.star.outgoodsmanage.mapper.LoadCheckMapper;
import com.zeroone.star.outgoodsmanage.service.ILoadCheckService;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailDTO;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailExcelDTO;
import com.zeroone.star.project.dto.j7.zccheck.BatchCheckDTO;
import com.zeroone.star.project.dto.j7.zccheck.CheckDTO;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


@Mapper(componentModel = "spring")
interface MsLoadCheckMapper{
    /**
     * 将BatchCheckDTO 转为 LoadCheckDO 对象
     * @param loadCheckDO
     * @return
     */
    CheckDTO loadCheckDOToCheckDTO(LoadCheckDO loadCheckDO);

}
/**
 * <p>
 * 描述：
 * </p>
 *
 * @author chen
 * @since 2025/3/4 19:25
 */

@Service
public class LoadCheckServiceImpl implements ILoadCheckService{

    @Resource
    LoadCheckMapper loadCheckMapper;

    @Resource
    MsLoadCheckMapper msMapper;

    @Override
    public List<CheckDTO> updateBatchCheck(List<CheckDTO> checkDTOs) {

        int checkDOS = loadCheckMapper.updateBatchCheck(checkDTOs);
        if (checkDOS>0) return checkDTOs;
        else
            return null;
    }
}
