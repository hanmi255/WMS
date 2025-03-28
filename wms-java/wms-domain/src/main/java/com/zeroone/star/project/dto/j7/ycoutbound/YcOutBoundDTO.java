package com.zeroone.star.project.dto.j7.ycoutbound;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * <p>
 * 描述：获取异常出库通知明细列表DTO
 * </p>
 *
 * @author keyuan
 * @since 2025/2/28
 */
@ApiModel("出库任务列表")
@Data
public class YcOutBoundDTO {
    /**
     * 通知单号
     */
    @ApiModelProperty(value = "通知单号")
    @ExcelProperty(value = "通知单号", index = 0)
    private String omNoticeId;

    /**
     * 第三方单号，对应表 wm_om_notice_h 中的 IM_CUS_CODE 字段
     */
    @ApiModelProperty(value = "第三方单号")
    @ExcelProperty(value = "第三方单号", index = 1)
    @TableField("IM_CUS_CODE")
    private String imCusCode;

    /**
     * 第三方客户，对应表 wm_om_notice_h
     */
    @ApiModelProperty(value = "第三方客户")
    @ExcelProperty(value = "第三方客户", index = 2)
    private String ocusCode;

    /**
     * 第三方客户名称，对应表 wm_om_notice_h
     */
    @ApiModelProperty(value = "第三方客户名称")
    @ExcelProperty(value = "第三方客户名称", index = 3)
    private String ocusName;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注")
    @ExcelProperty(value = "备注", index = 4)
    private String omBeizhu;

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码")
    @ExcelProperty(value = "商品编码", index = 5)
    private String goodsId;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称")
    @ExcelProperty(value = "商品名称", index = 6)
    private String goodsName;

    /**
     * 通知数量
     */
    @ApiModelProperty(value = "通知数量")
    @ExcelProperty(value = "通知数量", index = 7)
    private String baseGoodscount;

    /**
     * 单位
     */
    @ApiModelProperty(value = "单位")
    @ExcelProperty(value = "单位", index = 8)
    private String baseUnit;

    /**
     * 状态
     */
    @ApiModelProperty(value = "状态")
    @ExcelProperty(value = "状态", index = 9)
    private String planSta;

    /**
     * 下架任务数量，对应表 wm_om_qm_i
     */
    @ApiModelProperty(value = "下架任务数量")
    @ExcelProperty(value = "下架任务数量", index = 10)
    private BigDecimal thirdGoodsCount;
}
