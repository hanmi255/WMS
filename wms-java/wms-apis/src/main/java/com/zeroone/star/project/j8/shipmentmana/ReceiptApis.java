package com.zeroone.star.project.j8.shipmentmana;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptBaseDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptDeleteDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptPutDTO;
import com.zeroone.star.project.query.j8.shipmentmana.receiptmana.ReceiptQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

/**
 * 回单管理接口
 */
public interface ReceiptApis {
    /**
     * 查询回单列表
     * @param query 查询条件
     * @return 根据条件查询到的回单列表数据
     */
    JsonVO<PageDTO<ReceiptListDTO>> queryReceiptList(ReceiptQuery query);

    /**
     * 添加回单
     * @param dto 添加的回单信息,主键自动生成
     * @return 是否添加成功
     */
    JsonVO<String> addReceipt(ReceiptBaseDTO dto);

    /**
     * 修改回单
     * @param dto 修改的回单信息，带主键指定修改哪个回单
     * @return 是否修改成功
     */
    JsonVO<String> putReceipt(ReceiptPutDTO dto);

    /**
     * 撤销回单
     * @param dto 撤销的回单信息
     * @return 是否撤销成功
     */
    JsonVO<String> deleteReceipt(ReceiptDeleteDTO dto);

    /**
     * 导入excel文件
     * @param file excel文件
     * @return 导入结果
     */
    JsonVO<String> imExcel(MultipartFile file);

    /**
     * 导出excel文件
     * @return excel附件
     */
    ResponseEntity<byte[]> exExcel();
}
