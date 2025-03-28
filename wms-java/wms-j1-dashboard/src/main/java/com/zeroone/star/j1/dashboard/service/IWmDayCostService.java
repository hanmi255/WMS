package com.zeroone.star.j1.dashboard.service;

import com.zeroone.star.j1.dashboard.entity.WmDayCost;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.j1.dashboard.WmDayCostInRecentVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-03-04
 */
public interface IWmDayCostService extends IService<WmDayCost> {
    /**
     * 查询近几天的总费用，如果返回的集合不为null但size=0，代表数据库中没有数据但是缓存中由空数据，如果更新了数据库中数据，则需要删除缓存
     * @param count
     * @return List<WmDayCostInRecentVO>
     */
    List<WmDayCostInRecentVO> listOneDayTotalCost(int count);
}
