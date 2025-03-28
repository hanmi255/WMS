package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：收货登记信息传输数据对象 - 用于封装填写表格空缺部分所需的字段
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author [您的名字]
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("收货登记信息传输数据对象 - 填写表格")
public class DoAcceptDTO {
    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "G00001", required = true)
    private String goodsId;

    /**
     * 数量（已确认数量）
     */
    @ApiModelProperty(value = "数量（已确认数量）", example = "50", required = true)
    private Integer qmOkQuat;

    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生产日期", example = "2024-01-01", required = true)
    private String proData;

    /**
     * 批次
     */
    @ApiModelProperty(value = "批次", example = "BATCH001", required = true)
    private String goodsBatch;

    /**
     * 收货温度
     */
    @ApiModelProperty(value = "收货温度", example = "25", required = true)
    private Double recDeg;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "这是一个测试备注")
    private String itemText;

    /**
     * 托盘
     */
    @ApiModelProperty(value = "托盘", example = "TIN001", required = true)
    private String tinId;

    /**
     * 入重量
     */
    @ApiModelProperty(value = "入重量", example = "10.5", required = true)
    private Double tinZhl;
}