package com.zeroone.star.outgoodsmanage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.outgoodsmanage.entity.AnDanPickDO;
import com.zeroone.star.outgoodsmanage.mapper.AnDanPickMapper;
import com.zeroone.star.outgoodsmanage.service.IAnDanPickService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickListDTO;
import com.zeroone.star.project.dto.j7.adpick.OutDetailExcelDTO;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;

import static com.alibaba.druid.sql.ast.SQLPartitionValue.Operator.List;

/**
 * <p>
 *  按单拣货实现类
 * </p>
 *
 * @author qiuye
 * @since 2025-02-25
 */
@Service
public class AnDanPickServiceImpl extends ServiceImpl<AnDanPickMapper, AnDanPickDO> implements IAnDanPickService {
    @Resource
    private AnDanPickMapper anDanPickMapper;

    @Resource
    EasyExcelComponent easyExcelComponent;

    @Override
    public JsonVO<PageDTO<AdPickDTO>> modify(AdPickDTO adPickDTO) {
        int result = anDanPickMapper.updateAdPick(adPickDTO);
        if (result > 0) {
            // 创建一个包含单个修改项的 PageDTO 对象
            PageDTO<AdPickDTO> pageDTO = new PageDTO<>();
            pageDTO.setPageIndex(1L);
            pageDTO.setPageSize(1L);
            pageDTO.setTotal(1L);
            pageDTO.setPages(1L);
            pageDTO.setRows((List<AdPickDTO>) adPickDTO);

            return JsonVO.success(pageDTO);
        } else {
            return JsonVO.fail(null);
        }
    }

    @Override
    public JsonVO<PageDTO<AdPickListDTO>> modifyList(List<AdPickListDTO> adPickListDTOs) {
        int rowsAffected = anDanPickMapper.batchUpdateAdPick(adPickListDTOs);
        if (rowsAffected > 0) {
            // 创建一个包含批量修改项的 PageDTO 对象
            PageDTO<AdPickListDTO> pageDTO = new PageDTO<>();
            pageDTO.setPageIndex(1L);
            pageDTO.setPageSize((long) adPickListDTOs.size());
            pageDTO.setTotal((long) adPickListDTOs.size());
            pageDTO.setPages(1L);
            pageDTO.setRows(adPickListDTOs);

            return JsonVO.success(pageDTO);
        } else {
            return JsonVO.fail(null);
        }
    }

    /**
     * 导出拣货数据到Excel
     *
     * @param adPickQuery 查询条件
     * @throws IOException IO 异常
     */
    @Override
    public byte[] exportExcel(AdPickQuery adPickQuery) {
        List<OutDetailExcelDTO> dataList = anDanPickMapper.getExportData(adPickQuery);

        try (ByteArrayOutputStream outputStream = new ByteArrayOutputStream()) {
            easyExcelComponent.export("Sheet1", outputStream, OutDetailExcelDTO.class, dataList);
            return outputStream.toByteArray();
        } catch (IOException e) {
            e.printStackTrace();
            return new byte[0];
        }
    }
}
