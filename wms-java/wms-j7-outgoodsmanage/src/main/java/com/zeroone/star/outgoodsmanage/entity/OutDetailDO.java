package com.zeroone.star.outgoodsmanage.entity;


import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * <p>
 * 描述：出库明细实体类
 * </p>
 *
 * @author chen
 * @since 2025/2/24 16:31
 */

@Getter
@Setter
public class OutDetailDO implements Serializable{

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
    private Integer baseGoodscount;
    private String goodsUnit;
    private String sumGoodscount;


}
