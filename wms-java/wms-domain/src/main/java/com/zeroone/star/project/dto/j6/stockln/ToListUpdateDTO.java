package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：待上架货物修改数据传输对象
 * </p>
 *
 * <p>用途：前端修改待上架货物信息后，提交给后端</p>
 *
 * @author [Susu]
 * @version 1.0.0
 */
@Data
@ApiModel("待上架货物修改DTO")
public class ToListUpdateDTO {
    @ApiModelProperty(value = "主键", example = "8a9485a995413dfb01954155c0ef0034")
    private String id;

    @ApiModelProperty(value = "托盘ID", example = "T001")
    private String tinId;  // 托盘 ID（可修改）

    @ApiModelProperty(value = "储位", example = "A01")
    private String binId;  // 货物的存储位置（可修改）

    @ApiModelProperty(value = "收货数量", example = "50")
    private String qmOkQuat;  // 收货后的实际数量（可修改）

    @ApiModelProperty(value = "体积", example = "4500000.0")
    private String tinTj;  // 货物的体积（可修改）

    @ApiModelProperty(value = "重量", example = "1800.0")
    private String tinZhl;  // 货物的重量（可修改）

    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String proData;  // 货物的生产日期（可修改）

    @ApiModelProperty(value = "批次", example = "B001")
    private String goodsBatch;  // 货物的批次编号（可修改）

    @ApiModelProperty(value = "收货温度", example = "4°C")
    private String recDeg;  // 货物的收货时温度（可修改）

    @ApiModelProperty(value = "备注", example = "特殊处理")
    private String itemText;  // 备注信息（可修改）

    @ApiModelProperty(value = "入重量", example = "50")
    private String baseInGoodscount;  // 入库时的重量（可修改）

    @ApiModelProperty(value = "出重量", example = "48")
    private String baseOutGoodscount;  // 出库时的重量（可修改）
}
