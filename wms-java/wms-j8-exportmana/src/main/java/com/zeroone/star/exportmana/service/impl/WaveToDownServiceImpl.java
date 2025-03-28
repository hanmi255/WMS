package com.zeroone.star.exportmana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.exportmana.entity.WaveToDown;
import com.zeroone.star.exportmana.mapper.MsWaveExportMapper;
import com.zeroone.star.exportmana.mapper.WaveToDownMapper;
import com.zeroone.star.exportmana.service.WaveToDownService;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportDetailDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportExcelDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.WaveExport.WaveExportPrintDTO;
import com.zeroone.star.project.query.j8.shipmentmana.waveexport.WaveExportQuery;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.apache.commons.lang.StringUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * <p>
 * VIEW 服务实现类
 * </p>
 *
 * @author wuven
 * @since 2025-03-06
 */
@Service
public class WaveToDownServiceImpl extends ServiceImpl<WaveToDownMapper, WaveToDown> implements WaveToDownService {

    @Resource
    WaveToDownMapper waveToDownMapper;

    @Resource
    MsWaveExportMapper msWaveExportMapper;

    @Override
    public WaveExportPrintDTO getPrintDTO(String waveId) {
        QueryWrapper<WaveToDown> wrapper = new QueryWrapper<>();
        wrapper.like("wave_id", waveId);
        return msWaveExportMapper.toWaveExportPrintDTO(waveToDownMapper.selectOne(wrapper));
    }

    @Override
    public Page<WaveExportListDTO> listAllWaveExport(WaveExportQuery query) {

        //使用分页查询
        Page<WaveToDown> page=new Page<>(query.getPageIndex(), query.getPageSize());
        //构建query条件
        QueryWrapper<WaveToDown> queryWrapper=new QueryWrapper<>();
        //模糊查询的条件
        //保证传入的值不是空值，才能够正常进行查询
        queryWrapper
                .like(StringUtils.isNotBlank(query.getCustomerName()), "cus_name",  query.getCustomerName() )
                .like(StringUtils.isNotBlank(query.getWaveNumber()), "wave_id",  query.getWaveNumber() )
                .like(StringUtils.isNotBlank(query.getGoodsNumber()), "goods_id",  query.getGoodsNumber() )
                .like(StringUtils.isNotBlank(query.getPositions()), "bin_id",  query.getPositions() )
                .like(StringUtils.isNotBlank(query.getContainersRemove()), "first_rq",  query.getContainersRemove() );
        Page<WaveToDown> waveToDownPage = waveToDownMapper.selectPage(page, queryWrapper);
        List<WaveToDown> records = waveToDownPage.getRecords();
        List<WaveExportListDTO> waveExportListDTOS=new ArrayList<>();
        for (WaveToDown waveToDown : records) {
            WaveExportListDTO waveExportListDTO = msWaveExportMapper.toWaveExportListDTO(waveToDown);
            waveExportListDTOS.add(waveExportListDTO);
        }
        //传到前端的结果
        Page<WaveExportListDTO> result =new Page<>(query.getPageIndex(), query.getPageSize()) ;
        result.setRecords(waveExportListDTOS);

        return result;
    }

    @Override
    public List<WaveExportExcelDTO> exportExcel(List<String> waveIds) {
        //取出需要导出的数据
        QueryWrapper wrapper = new QueryWrapper();
        wrapper.in("wave_id",waveIds);

        List<WaveToDown> list = waveToDownMapper.selectList(wrapper);
        List<WaveExportExcelDTO> waveExportExcelDTOS=new ArrayList<>();
        for (WaveToDown waveToDown:list){
            WaveExportExcelDTO waveExportExcelDTO = msWaveExportMapper.toWaveExportExcelDTO(waveToDown);
            waveExportExcelDTOS.add(waveExportExcelDTO);
        }

        return waveExportExcelDTOS;
    }

    @Override
    public WaveExportDetailDTO listDetailWaveExport(String id) {
        QueryWrapper<WaveToDown> queryWrapper = new QueryWrapper<>();
        queryWrapper.like("wave_id",id);
        return msWaveExportMapper.toWaveExportDetailDTO(waveToDownMapper.selectOne(queryWrapper));
    }
}
