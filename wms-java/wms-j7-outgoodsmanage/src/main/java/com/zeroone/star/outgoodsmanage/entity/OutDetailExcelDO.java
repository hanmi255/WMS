package com.zeroone.star.outgoodsmanage.entity;


import lombok.Data;

/**
 * <p>
 * 描述：导出出库明细数据类
 * </p>
 *
 * @author chen
 * @since 2025/3/4 15:38
 */

@Data
public class OutDetailExcelDO {
    private String id;
    private String omSta;
    private String omNoticeId;
    private String imCusCode;
    private String cusCode;
    private String ocusName;
    private String omBeizhu;
    private String delvAddr;
    private String goodsId;
    private String goodsName;
    private String baseGoodscount;
    private String goodsUnit;
    private String sumGoodscount;
}
