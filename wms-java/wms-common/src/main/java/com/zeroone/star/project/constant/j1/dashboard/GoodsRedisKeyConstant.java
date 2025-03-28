package com.zeroone.star.project.constant.j1.dashboard;
/**
 * <p>
 * 描述：redis中货物待办key值常量
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author j1-yunyu
 * @version 1.0.0
 */
public interface GoodsRedisKeyConstant {

    /**
     * 待收货
     */
    String GOODS_AWAITING_RECEIPT = "DASHBOARD:GOODS_AWAITING_RECEIPT";
    /**
     * 待上架
     */
    String GOODS_AWAITING_UP = "DASHBOARD:GOODS_AWAITING_UP";
    /**
     * 拣货中
     */
    String GOODS_PICKING_IN_PROGRESS = "DASHBOARD:GOODS_PICKING_IN_PROGRESS";
    /**
     * 待拣货
     */
    String GOODS_AWAITING_PICKING = "DASHBOARD:GOODS_AWAITING_PICKING";
    /**
     * 近日内上架商品数量
     */
    String GOODS_UP_IN_RECENT_DAYS = "DASHBOARD:GOODS_UP_IN_RECENT_DAYS";
    /**
     * 近日内下架商品数量
     */
    String GOODS_DOWN_IN_RECENT_DAYS = "DASHBOARD:GOODS_DOWN_IN_RECENT_DAYS";
    /**
     * 前几位总上架商品数量
     */
    String TOTAL_GOODS_UP = "DASHBOARD:TOTAL_GOODS_UP";
    /**
     * 前几位总下架商品数量
     */
    String TOTAL_GOODS_DOWN = "DASHBOARD:TOTAL_GOODS_DOWN";
    /**
     * 近日内每天费用合计
     */
    String ONE_DAY_TOTAL_COST = "DASHBOARD:ONE_DAY_TOTAL_COST";

}
