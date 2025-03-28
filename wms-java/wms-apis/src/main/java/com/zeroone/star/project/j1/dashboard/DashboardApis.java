package com.zeroone.star.project.j1.dashboard;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.dashboard.*;

import java.util.List;

/**
 * <p>
 * 描述：系统首页
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-yunyu
 * @version 1.0.0
 */
public interface DashboardApis {

    /**
     *查询待收货的货物件数
     * @return 货物待收货件数
     */
    JsonVO<GoodsPendingVO> queryPendingReceiptGoodNumber();

    /**
     * 查询待上架的货物件数
     * @return 货物待上架件数
     */
    JsonVO<GoodsPendingVO> queryPendingToUpGoodNumber();

    /**
     * 查询带拣货的货物件数
     * @return 货物待拣货件数
     */
    JsonVO<GoodsPendingVO> queryPendingPickGoodNumber();

    /**
     * 查询拣货中货物件数
     * @return 货物拣货中件数
     */
    JsonVO<GoodsPendingVO> queryCurrentPickGoodNumber();

    /**
     *查询上架商品数量前count位的商品,默认查询前6位
     * @param count 前几位
     * @return 符合条件的商品列表
     */
    JsonVO<List<GoodsToUpVO>> queryGoodsToUpNumberTopCount(int count);

    /**
     * 查询上架商品数量最近count天的商品,默认查询最近7天的商品
     * @param count 天数
     * @return 符合条件的商品列表
     */
    JsonVO<List<GoodsUpInRecentVO>> queryGoodsToUpNumberInRecentDays(int count);

    /**
     *  查询下架商品数量前count位的商品,默认查询前6位
     * @param count 前几位
     * @return 符合条件的商品列表
     */
    JsonVO<List<GoodsToDownVO>> queryGoodsToDownNumberTopCount(int count);

    /**
     *  查询下架商品数量最近count天的商品,默认查询最近7天的商品
     * @param count 天数
     * @return 符合条件的商品列表
     */
    JsonVO<List<GoodsDownInRecentVO>> queryGoodsToDownNumberInRecentDays(int count);

    /**
     *  查询每天费用合计最近count天的费用合计,默认查询最近7天的费用合计
     * @param count 天数
     * @return 符合条件的费用合计列表
     */
    JsonVO<List<WmDayCostInRecentVO>> queryOneDayTotalCostStatistics(int count);

}
