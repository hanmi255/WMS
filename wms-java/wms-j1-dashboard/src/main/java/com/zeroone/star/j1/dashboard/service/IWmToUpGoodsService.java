package com.zeroone.star.j1.dashboard.service;

import com.zeroone.star.j1.dashboard.entity.WmToUpGoods;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.j1.dashboard.GoodsToUpVO;
import com.zeroone.star.project.vo.j1.dashboard.GoodsUpInRecentVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
public interface IWmToUpGoodsService extends IService<WmToUpGoods> {

    /**
     * 查询最近几天上架商品数量，如果返回的集合不为null但size=0，代表数据库中没有数据但是缓存中由空数据，如果更新了数据库中数据，则需要删除缓存
     * @param count 天数
     * @return 上架商品数量集合
     */
    List<GoodsUpInRecentVO> listGoodsToUpNumberInRecentDays(int count);

    /**
     * 查询上架前几位的商品数量
     * @param count 位数
     * @return 前几位上架商品数量集合
     */
    List<GoodsToUpVO> listTotalGoodsUpNumber(int count);
}
