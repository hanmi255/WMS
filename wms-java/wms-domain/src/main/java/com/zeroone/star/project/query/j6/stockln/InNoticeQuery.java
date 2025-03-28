package com.zeroone.star.project.query.j6.stockln;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：入库通知单明细查询对象
 * </p>
 *
 * @author [你的姓名]
 * @version 1.0.0
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("入库通知单明细查询对象")
public class InNoticeQuery extends PageQuery {

    /**
     * 通知单号
     */
    @ApiModelProperty(value = "通知单号", example = "RK20250226-0003", required = true)
    private String imNoticeId;  // 对应VO的 imNoticeId

    /**
     * 客户编码
     */
    @ApiModelProperty(value = "客户编码", example = "X00001", required = true)
    private String cusCode;  // 对应VO的 cusCode

    /**
     * 客户名称
     */
    @ApiModelProperty(value = "客户名称", example = "某某公司")
    private String createName;  // 对应VO的 createName（客户名称）

    /**
     * 通知单状态
     */
    @ApiModelProperty(value = "通知单状态", example = "待处理")
    private String noticeiSta;  // 对应VO的 noticeiSta

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "RL001", required = true)
    private String goodsCode;  // 对应VO的 goodsCode

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称", example = "小蓝管", required = true)
    private String goodsName;  // 对应VO的 goodsName

    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号", example = "CUS000001")
    private String imCusCode;  // 对应VO的 imCusCode（客户订单号）

    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String goodsPrdData;  // 对应VO的 goodsPrdData（生产日期）

}
