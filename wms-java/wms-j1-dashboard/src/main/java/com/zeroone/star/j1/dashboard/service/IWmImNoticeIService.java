package com.zeroone.star.j1.dashboard.service;

import com.zeroone.star.j1.dashboard.entity.WmImNoticeI;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.j1.dashboard.GoodsPendingVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
public interface IWmImNoticeIService extends IService<WmImNoticeI> {

    /**
     * 查询待收货的货物件数
     * @return 待收货的货物件数
     */
    GoodsPendingVO getReceiptGoodNumber();

}
