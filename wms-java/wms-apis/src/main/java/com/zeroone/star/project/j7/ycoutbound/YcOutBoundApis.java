package com.zeroone.star.project.j7.ycoutbound;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.ycoutbound.YcOutBoundDTO;
import com.zeroone.star.project.query.j7.ycoutbound.YcOutBoundQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

/**
 * <p>
 * 描述：异常出库查询接口
 * </p>
 *
 * @author keyuan
 * @since 2025/2/25 下午 9:25
 */
public interface YcOutBoundApis {
    /**
     * 分页获取异常出库列表
     * @param  query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<YcOutBoundDTO>> queryAll(YcOutBoundQuery query);

    /**
     * 导出异常出库列表excel数据表
     * @return 响应数据结果
     */
    ResponseEntity<byte[]> exportExcel();
}