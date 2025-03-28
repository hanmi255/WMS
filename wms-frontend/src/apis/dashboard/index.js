// 系统首页
import Request from "../request";

/**
 * 查询待收货的货物件数
 */

export const getWaitReceiveGoodsCountAPI = () => {
	return Request.requestForm(Request.GET, "/dashboard/query-pend-receipt");
};

/**
 * 待上架的货物件数
 */
export const getWaitShelfGoodsCountAPI = () => {
	return Request.requestForm(Request.GET, "/dashboard/query-pend-to-up");
};

/**
 * 待拣货的货物件数
 */
export const getWaitPickGoodsCountAPI = () => {
	return Request.requestForm(Request.GET, "/dashboard/query-pend-pick");
};

/**
 * 拣货中的货物件数
 */
export const getPickingGoodsCountAPI = () => {
	return Request.requestForm(Request.GET, "/dashboard/query-cur-pick");
};

/**
 * 查询上架商品数量Top6，默认返回6位。
 */
export const getTopShelfGoodsCountAPI1 = (count = 6) => {
	return Request.requestForm(Request.GET, "/dashboard/query-goods-to-up", count);
};

/**
 * 查询七天内下架商品数量，默认返回7天
 */
export const getShelfGoodsCountAPI2 = (count = 7) => {
	return Request.requestForm(Request.GET, "/dashboard/query-goods-to-down-in-recent-days", count);
};

/**
 * 查询下架商品数量Top6，默认返回6位。
 */
export const getTopDownGoodsCountAPI3 = (count = 6) => {
	return Request.requestForm(Request.GET, "/dashboard/query-goods-to-down", count);
};

/**
 * 查询七天内上架商品数量，默认返回7天
 */
export const getGoodsToUpInRecentDaysAPI4 = (count = 7) => {
	return Request.requestForm(Request.GET, "/dashboard/query-goods-to-up-in-recent-days", count);
};
