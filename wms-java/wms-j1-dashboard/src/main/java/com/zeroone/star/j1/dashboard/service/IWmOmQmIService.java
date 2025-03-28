package com.zeroone.star.j1.dashboard.service;

import com.zeroone.star.j1.dashboard.entity.WmOmQmI;
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
public interface IWmOmQmIService extends IService<WmOmQmI> {

    /**
     * 查询待拣货的货物件数
     * @return 待拣货的货物件数
     */
    GoodsPendingVO getPickGoodNumber();

    /**
     * 查询拣货中的货物件数
     * @return 拣货中的货物件数
     */
    GoodsPendingVO getCurrentPickGoodNumber();
}
