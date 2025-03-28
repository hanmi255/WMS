package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class GoodsDTO {
    /**
     * 品质
     */

    /**
     * 毛重
     */
    @ApiModelProperty(value = "毛重", example = "0")
    private String zhlKgm;
    /**
     * 拆零数量
     */
    @ApiModelProperty(value = "拆零数", example = "0")
    private String chlShl;
    /**
     * 库存
     */
}
