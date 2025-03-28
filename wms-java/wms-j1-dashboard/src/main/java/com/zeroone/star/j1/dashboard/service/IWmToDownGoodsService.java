package com.zeroone.star.j1.dashboard.service;

import com.zeroone.star.j1.dashboard.entity.WmToDownGoods;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.j1.dashboard.GoodsDownInRecentVO;
import com.zeroone.star.project.vo.j1.dashboard.GoodsToDownVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
public interface IWmToDownGoodsService extends IService<WmToDownGoods> {

    /**
     * 查询最近几天下架商品数量，如果返回的集合不为null但size=0，代表数据库中没有数据但是缓存中由空数据，如果更新了数据库中数据，则需要删除缓存
     * @param count 天数
     * @return 下架商品数量集合
     */
    List<GoodsDownInRecentVO> listGoodsDownNumberInRecentDays(int count);

    /**
     * 查询下架前几位的商品数量
     * @param count 位数
     * @return 前几位下架商品数量集合
     */
    List<GoodsToDownVO> listTotalGoodsDownNumber(int count);
}
