package com.zeroone.star.project.dto.j7.adpick;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;
/**
 * 批量修改拣货单对象
 *
 * @author Lin
 * @since 2025/3/15
 */
@Data
@ApiModel("拣货单数据传输对象")
public class AdPickModifyDTO extends AdPickModifyBaseDTO {
    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;
    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    /**
     * 原始单据编码
     */
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;
    /**
     * 原始单据类型
     */
    @ApiModelProperty(value = "原始单据类型")
    private String orderType;
    /**
     * 单位
     */
    @ApiModelProperty(value = "单位")
    private String goodsUnit;
    /**
     * 作业类型
     */
    @ApiModelProperty(value = "作业类型")
    private String actTypeCode;
    /**
     * 目标托盘
     */
    @ApiModelProperty(value = "目标托盘")
    private String binIdTo;
    /**
     * 货主
     */
    @ApiModelProperty(value = "货主")
    private String cusCode;
    /**
     * 状态
     */
    @ApiModelProperty(value = "状态")
    private String downSta;
    /**
     * 基本单位
     */
    @ApiModelProperty(value = "基本单位")
    private String baseUnit;
}