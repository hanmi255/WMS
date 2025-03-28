package com.zeroone.star.project.query.j7.adpick;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：按单拣货项查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author tang
 * @since 2025-02-25
 */

@Getter
@Setter
@ToString
public class AnDanPickQuery extends PageQuery {

    /**
     * 原始单据编码
     */
    @ApiModelProperty(value = "原始单据编码", example = "CK20250223-0003")
    private String originalDocumentCode;

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String productCode;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称", example = "小蓝管")
    private String productName;

    /**
     * 客户订单号
     */
    @ApiModelProperty(value = "客户订单号", example = "1112340")
    private Long customerOrderNumber;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "这是一件...")
    private String remark;

    /**
     * 源托盘码
     */
    @ApiModelProperty(value = "源托盘码", example = "A")
    private String sourcePalletCode;

    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码", example = "X1-1-02")
    private String storageLocationCode;

    /**
     * 货主
     */
    @ApiModelProperty(value = "货主", example = "X00001-halo")
    private String cargoOwner;

    /**
     * 目标托盘
     */
    @ApiModelProperty(value = "目标托盘", example = "X00001-halo")
    private String targetPallet;
}
