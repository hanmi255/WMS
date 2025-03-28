package com.zeroone.star.project.j7.outdetail;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailDTO;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailExcelDTO;
import com.zeroone.star.project.query.j7.outdetail.OutDetailExcelQuery;
import com.zeroone.star.project.query.j7.outdetail.OutDetailQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 描述：出库明细接口
 * </p>
 *
 * @author chen
 * @since 2025/2/22 12:47
 */
public interface OutDetailApis {
    /**
     * 获取出库明细列表
     * @param detailQuery 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<OutDetailDTO>> queryAll(OutDetailQuery detailQuery);

    /**
     * 导出出库明细数据
     * @return 响应数据结果
     */
    public ResponseEntity<byte[]> exportExcel()throws Exception;
}
