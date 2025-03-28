package com.zeroone.star.exportmana.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.exportmana.entity.InTransitStock;
import com.zeroone.star.exportmana.mapper.InTransitStockMapper;
import com.zeroone.star.exportmana.service.IInTransitStockService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j8.shipmentmana.intransitstock.InTransitStockQuery;
import com.zeroone.star.project.vo.j8.shipmentmana.intransitstock.InTransitStockVO;
import lombok.RequiredArgsConstructor;
import org.mapstruct.Mapper;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;


@Mapper(componentModel = "spring")
interface MsInTransitStockMapper {
    /**
     * description：将InTransitStock的do转为dto
     *
     * @param inTransitStock 实例do
     * @return 实例vo
     */
    InTransitStockVO sample2SampleDTO(InTransitStock inTransitStock);
}

/**
 * @ClassName: InTransitStockServiceImpl
 * @Package: com.zeroone.star.intransitstock.service.impl
 * @Description:
 * @Author: zk
 * @Create: 2025/2/27 - 下午10:18
 */
@Service
@RequiredArgsConstructor
public class InTransitStockServiceImpl extends ServiceImpl<InTransitStockMapper, InTransitStock> implements IInTransitStockService {
    // 在途库存Mapper
    private final InTransitStockMapper transitStockMapper;
    // Ms在途库存Mapper
    private final MsInTransitStockMapper msInTransitStockMapper;
    // Excel组件
    private final EasyExcelComponent excel;

    @Override
    public PageDTO<InTransitStockVO> listTransitStock(InTransitStockQuery query) {
        // 1. 构建分页对象
        Page<InTransitStock> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 2. 执行查询
        Page<InTransitStock> pageResult = transitStockMapper.select(page, query);
        // 3. 转换为VO并返回
        return PageDTO.create(pageResult, msInTransitStockMapper::sample2SampleDTO);
    }

    @Override
    public ResponseEntity<byte[]> exportTransitStock(InTransitStockQuery query) {
        try {
            // 根据查询条件获取在途库存列表
            List<InTransitStockVO> transitStockVOS = listTransitStock(query).getRows();
            // 将在途库存列表转换为在途库存实体列表
            List<InTransitStock> transitStocks = BeanUtil.copyToList(transitStockVOS, InTransitStock.class);
            // 创建输出流
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            // 将数据输出到输出流
            excel.export("在途库存", out, InTransitStock.class, transitStocks);
            // 将文件响应给前端
            HttpHeaders httpHeaders = new HttpHeaders();
            // 设置文件名
            String fileName = "report-" + DateTime.now().toString("yyyyMMddHHmmss") + ".xlsx";
            // 设置响应头
            httpHeaders.setContentDispositionFormData("attachment", fileName);
            httpHeaders.setContentType(MediaType.APPLICATION_OCTET_STREAM);
            // 创建响应实体
            ResponseEntity<byte[]> responseEntity = new ResponseEntity<>(out.toByteArray(), httpHeaders, HttpStatus.CREATED);
            // 关闭输出流
            out.close();
            return responseEntity;
        } catch (IOException e) {
            // 抛出运行时异常
            throw new RuntimeException(e);
        }
    }
}
