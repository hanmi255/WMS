package com.zeroone.star.exportmana.service;

import com.zeroone.star.exportmana.entity.Receipt;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptBaseDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptDeleteDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptPutDTO;
import com.zeroone.star.project.query.j8.shipmentmana.receiptmana.ReceiptQuery;
import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 回单 服务类
 * </p>
 *
 * @author asta
 * @since 2025-02-27
 */
public interface ReceiptService extends IService<Receipt> {

    /**
     * 获取回单信息
     * @param query 查询回单条件
     * @return 查询到的回单列表
     */
    public PageDTO<ReceiptListDTO> getReceipt(ReceiptQuery query);

    /**
     * 添加回单
     * @param dto 添加的回单内容
     * @return 添加结果，1为成功
     */
    public int addReceipt(ReceiptBaseDTO dto);

    /**
     * 修改回单信息
     * @param dto 需要修改的数据
     * @return 修改结果，1为成功
     */
    public int updateReceipt(ReceiptPutDTO dto);

    /**
     * 删除回单
     * @param dto 需要删除的回单id
     * @return 添加结果，1为成功
     */
    public int deleteReceipt(ReceiptDeleteDTO dto);

    /**
     * 导入数据
     * @param file 需要导入的excel文件
     * @return 导入结果，返回受影响的行数
     */
    public int importExcel(MultipartFile file);

    /**
     * 导出数据
     * @return excel文件字节流
     */
    public ResponseEntity<byte[]> exportExcel();
}
