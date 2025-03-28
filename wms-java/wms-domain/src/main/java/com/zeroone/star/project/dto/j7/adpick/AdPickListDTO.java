package com.zeroone.star.project.dto.j7.adpick;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 *     批量修改拣货单对象
 * </p>
 * @author 阿晨
 * @since 2025 2-25
 */
@Getter
@Setter
@ApiModel("按单拣货批量修改选择对象")
public class AdPickListDTO {


    @ApiModelProperty(value = "主键", example = "123e4567-e89b-12d3-a456-426614174000")
    private String id;

    @ApiModelProperty(value = "数量")
    private Integer quantity;

    @ApiModelProperty(value = "复核数量")
    private Integer verifiedQuantity;

    @ApiModelProperty(value = "基本单位", example = "10000")
    private Integer baseUnit;

    @ApiModelProperty(value = "源托盘码", example = "A")
    private String sourcePalletCode;

    @ApiModelProperty(value = "库位编码", example = "X1-1-02")
    private String storageLocationCode;

    @ApiModelProperty(value = "生成日期", example = "2025-02-23")
    private LocalDateTime productTime;
}
