package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * VIEW
 * </p>
 *
 * @author smt
 * @since 2025-03-07
 */
@Getter
@Setter
@TableName("wv_stock")
public class WvStock implements Serializable {

    private static final long serialVersionUID = 1L;

    private String id;

    private String createDate;

    private String createName;

    private String createBy;

    private String kuctype;

    private Long goodsQua;

    private String goodsUnit;

    private Long baseGoodscount;

    private String baseUnit;

    private String kuWeiBianMa;

    private String binId;

    private String cusCode;

    /**
     * 中文全称
     */
    private String zhongWenQch;

    private String goodsId;

    private String goodsCode;

    private String shpMingCheng;

    private String shlDanWei;

    private String chlShl;

    private String goodsProData;

    private String bzhiQi;

    private String shpGuiGe;

    private String dqr;

    /**
     * 库位类型
     */
    private String kuWeiLeiXing;

    /**
     * 取货次序
     */
    private String quHuoCiXu;

    /**
     * 上架次序
     */
    private String shangJiaCiXu;

    /**
     * 仓库
     */
    private String binStore;

    private String tiJiCm;

    /**
     * 体积单位
     */
    private String tiJiDanWei;

    /**
     * 重量单位
     */
    private String zhongLiangDanWei;

    /**
     * 面积单位
     */
    private String mianJiDanWei;

    /**
     * 最大体积
     */
    private String zuiDaTiJi;

    /**
     * 最大面积
     */
    private String zuiDaMianJi;


}
