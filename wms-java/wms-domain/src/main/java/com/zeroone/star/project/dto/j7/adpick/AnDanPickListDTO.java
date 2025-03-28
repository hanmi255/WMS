package com.zeroone.star.project.dto.j7.adpick;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * @ClassName AnDanPickDTO
 * @Description 按单拣货的数据传输对象
 * @Author: tang
 * @Date 2025/2/25 18:41
 * @Version 1.0
 */

@Getter
@Setter
@ToString
@ApiModel("按单拣货的数据传输对象")
public class AnDanPickListDTO {

    /**
     * 主键
     */
    @ApiModelProperty(value = "主键", example = "123e4567-e89b-12d3-a456-426614174000")
    private String id;

    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期", example = "2025-02-23")
    private LocalDateTime createTime;

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
     * 数量
     */
    @ApiModelProperty(value = "数量", example = "10000")
    private Integer quantity;

    /**
     * 复核数量
     */
    @ApiModelProperty(value = "复核数量", example = "10000")
    private Integer verifiedQuantity;

    /**
     * 基本单位
     */
    @ApiModelProperty(value = "基本单位", example = "10000")
    private Integer baseUnit;

    /**
     * 单位
     */
    @ApiModelProperty(value = "单位", example = "箱")
    private Integer unit;

    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生成日期", example = "2025-02-23")
    private LocalDateTime productTime;

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
}
