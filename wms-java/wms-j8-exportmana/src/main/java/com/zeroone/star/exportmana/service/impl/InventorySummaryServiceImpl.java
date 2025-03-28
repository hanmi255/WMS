package com.zeroone.star.exportmana.service.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.exportmana.mapper.InventoryMapper;
import com.zeroone.star.exportmana.mapper.InventorySummaryMapper;
import com.zeroone.star.exportmana.service.InventorySummaryService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.inventorysummary.InventoryDTO;
import com.zeroone.star.project.query.j8.shipmentmana.inventorysummary.InventorySummaryQuery;
import com.zeroone.star.project.vo.j8.shipmentmana.inventorysummary.InventorySummaryVo;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;


@Service
@RequiredArgsConstructor
public class InventorySummaryServiceImpl extends ServiceImpl<InventoryMapper,InventoryDTO> implements InventorySummaryService {

    @Resource
    private InventoryMapper mapper;
    @Resource
    private InventorySummaryMapper inventorySummaryMapper;
    private final EasyExcelComponent excel;

    @Override
    public PageDTO<InventorySummaryVo> queryInventorySummary(InventorySummaryQuery query) {
        Page<InventoryDTO> inventoryList = mapper.selectInventoryList(query);
        System.out.println(inventoryList.getRecords().toString());
        return PageDTO.create(inventoryList, inventorySummaryMapper :: toInventorySummaryVo);
    }

    @Override
    public ResponseEntity<byte[]> exportInventoryToExcel(InventorySummaryQuery query) {
        Page<InventoryDTO> inventoryList = mapper.selectInventoryList(query);
        PageDTO<InventorySummaryVo> inventorySummaryVoPageDTO = PageDTO.create(inventoryList, inventorySummaryMapper::toInventorySummaryVo);
        try {
            List<InventorySummaryVo> inventoryVOS = inventorySummaryVoPageDTO.getRows();
            //List<InTransitStock> transitStocks = BeanUtil.copyToList(transitStockVOS, InTransitStock.class);
            // 创建输出流
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            // 将数据输出到输出流
            excel.export("库存总表", out, InventorySummaryVo.class, inventoryVOS);
            // 将文件响应给前端
            HttpHeaders httpHeaders = new HttpHeaders();
            String fileName = "report-" + DateTime.now().toString("yyyyMMddHHmmss") + ".xlsx";
            httpHeaders.setContentDispositionFormData("attachment", fileName);
            httpHeaders.setContentType(MediaType.APPLICATION_OCTET_STREAM);
            ResponseEntity<byte[]> responseEntity = new ResponseEntity<>(out.toByteArray(), httpHeaders, HttpStatus.CREATED);
            // 关闭输出流
            out.close();
            return responseEntity;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}