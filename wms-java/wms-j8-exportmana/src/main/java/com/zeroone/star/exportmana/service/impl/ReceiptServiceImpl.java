package com.zeroone.star.exportmana.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.exportmana.entity.Receipt;
import com.zeroone.star.exportmana.mapper.MsReceiptMapper;
import com.zeroone.star.exportmana.mapper.ReceiptMapper;
import com.zeroone.star.exportmana.service.ReceiptService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptBaseDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptDeleteDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptPutDTO;
import com.zeroone.star.project.query.j8.shipmentmana.receiptmana.ReceiptQuery;
import lombok.SneakyThrows;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 回单 服务实现类
 * </p>
 *
 * @author asta
 * @since 2025-02-27
 */
@Service
public class ReceiptServiceImpl extends ServiceImpl<ReceiptMapper, Receipt> implements ReceiptService {

    @Resource
    MsReceiptMapper ms;

    @Resource
    EasyExcelComponent ee;

    @Override
    public PageDTO<ReceiptListDTO> getReceipt(ReceiptQuery query) {
        Page<Receipt> receiptPage = baseMapper.selectByQuery(query);
        return PageDTO.create(receiptPage, ms::toReceiptListDTO);
    }

    @Override
    public int addReceipt(ReceiptBaseDTO dto) {
        Receipt receipt = ms.ReceiptBaseDTOtoReceipt(dto);
        return baseMapper.insert(receipt);
    }

    @Override
    public int updateReceipt(ReceiptPutDTO dto) {
        Receipt receipt = ms.ReceiptPutDTOtoReceipt(dto);
        return baseMapper.updateById(receipt);
    }

    @Override
    public int deleteReceipt(ReceiptDeleteDTO dto) {
        return baseMapper.deleteById(dto.getId());
    }

    @SneakyThrows
    @Override
    public int importExcel(MultipartFile file) {
        //读取文件数据
        InputStream in = file.getInputStream();
        ExcelReadListener<ReceiptListDTO> listener = new ExcelReadListener<>();
        EasyExcel.read(in, ReceiptListDTO.class,listener).sheet().doRead();
        List<ReceiptListDTO> dataList = listener.getDataList();
        //写入数据到数据库
        int affList = 0;//插入数据条数
        for (ReceiptListDTO i : dataList) {
            int aff = baseMapper.insert(ms.ReceiptListDTOtoReceipt(i));
            affList += aff;
        }
        return affList;
    }

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportExcel() {
        //获取导出数据
        List<Receipt> res = baseMapper.selectAll();
        List<ReceiptListDTO> data = new ArrayList<>();
        res.forEach(i->data.add(ms.toReceiptListDTO(i)));
        //导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        ee.export("回单管理",out, ReceiptListDTO.class,data);
        //响应文件数据
        String filename = "receipt-"+ DateTime.now().toString("yyyyMMddHHmmssS")+".xlsx";
        HttpHeaders headers= new HttpHeaders();
        headers.setContentDispositionFormData("attachment",filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }
}
