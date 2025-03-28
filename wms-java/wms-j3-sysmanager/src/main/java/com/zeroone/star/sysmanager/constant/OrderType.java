package com.zeroone.star.sysmanager.constant;

/**
 * 返回记录顺序, 共两种
 */
public enum OrderType {

    ORDER_TYPE_ASC,
    ORDER_TYPE_DESC;

    public static boolean isAsc(String orderType) {
        if (orderType == null) {
            return false;
        }
        return !orderType.equals("desc");
    }
}
