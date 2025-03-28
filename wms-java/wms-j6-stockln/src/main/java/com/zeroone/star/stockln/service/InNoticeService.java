package com.zeroone.star.stockln.service;

import com.zeroone.star.project.query.j6.stockln.InNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.stockln.InNoticePageVO;

/**
 * <p>
 * 描述：入库通知明细服务接口
 * </p>
 *
 * @author [Susu]
 * @version 1.0.0
 */
public interface InNoticeService {

    /**
     * 获取入库通知明细列表，支持条件查询和分页查询
     * @param query 查询条件
     * @param page 页码
     * @param size 每页数量
     * @return 返回分页的入库通知明细列表
     */
    InNoticePageVO getInNoticeItems(InNoticeQuery query, int page, int size);
}
