package com.zeroone.star.baseConfig.service.impl;

import com.zeroone.star.baseConfig.mapper.MeasurementUnitMapper;
import com.zeroone.star.baseConfig.service.MeasurementUnitService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementNameListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * @author adi
 * #Description 计量单位接口实现类
 * #Date: 2025/2/23 22:27
 */
@Service
@Transactional
@Slf4j
public class MeasurementUnitServiceImpl implements MeasurementUnitService {
    @Autowired
    private MeasurementUnitMapper measurementUnitMapper;

    @Override
    public JsonVO<PageDTO<MeasurementUnitVO>> queryMeasurementUnitList(MeasurementListQuery query) {
        try {
            // 处理分页参数
            if (query.getPageIndex() > 0) {
                // 将页码转换为偏移量
                query.setPageIndex((query.getPageIndex() - 1) * query.getPageSize());
            }
            
            log.info("查询条件: unitCode={}, unitZhName={}, unitEnName={}", 
                query.getUnitCode(), query.getUnitZhName(), query.getUnitEnName());
//
//            // 查询总条数
//            Long total = measurementUnitMapper.countTotal(query);
//            log.info("查询到的总记录数: {}", total);
            
            // 查询数据
            List<MeasurementUnitVO> records = measurementUnitMapper.queryMeasurementUnitList(query);
            log.info("当前页查询到的记录数: {}", records.size());
            
            // 构建分页对象
            PageDTO<MeasurementUnitVO> pageDTO = new PageDTO<>();
            pageDTO.setRows(records);
            pageDTO.setTotal((long) records.size());
            
            return JsonVO.success(pageDTO);
        } catch (Exception e) {
            log.error("查询计量单位列表失败", e);
            return JsonVO.fail(null);
        }
    }
    @Override
    public List<String> queryMeasurementUnitNameList(MeasurementNameListQuery query) {
        try {
            // 查询数据
            List<String> date = measurementUnitMapper.queryMeasurementUnitNameList(query);
            return date;
        } catch (Exception e) {
            log.error("查询计量单位名称列表失败", e);
            throw new RuntimeException("查询计量单位名称列表失败");
        }
    }


}
