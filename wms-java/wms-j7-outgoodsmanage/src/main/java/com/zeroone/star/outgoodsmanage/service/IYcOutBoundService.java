package com.zeroone.star.outgoodsmanage.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.ycoutbound.YcOutBoundDTO;
import com.zeroone.star.project.query.j7.ycoutbound.YcOutBoundQuery;

/**
 * <p>
 * 异常出库通知 服务类
 * </p>
 *
 * @author keyuan
 * @since 2025-03-01
 */
public interface IYcOutBoundService {
    PageDTO<YcOutBoundDTO> queryAll(YcOutBoundQuery query);

    Long getPageSize();
}
