package com.zeroone.star.project.dto.j7.downgoods;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

/**
 * @ClassName DownGoodsDTO
 * @Description 下架商品批量修改的数据传输对象
 * @Author: rocklin
 * @Date 2025/2/23 20:08
 * @Version 1.0
 */

@Getter
@Setter
@ToString
@ApiModel("下架商品批量修改的数据传输对象")
public class DownGoodsDTO {
    @NotBlank(message = "商品id不能为空")
    @ApiModelProperty(value = "商品id")
    private String id;

    @NotBlank(message = "数量不能为空")
    @Min(value = 1, message = "数量最小值为1")
    @ApiModelProperty(value = "数量")
    private String goodsQua;

    @NotBlank(message = "基本单位数量不能为空")
    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;
}
