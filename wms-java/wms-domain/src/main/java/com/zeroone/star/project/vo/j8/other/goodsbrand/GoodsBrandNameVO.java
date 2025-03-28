package com.zeroone.star.project.vo.j8.other.goodsbrand;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @ClassName: GoodsBrandNameVO
 * @Package: com.zeroone.star.project.vo.j8.other.goodsbrand
 * @Description: 商品品牌名称VO对象
 * @Author: zk
 * @Create: 2025/2/26 - 上午8:55
 */
@Data
@ApiModel("商品品牌名称VO对象")
public class GoodsBrandNameVO {
    @ApiModelProperty(value = "主键", example = "402880d38e31aba8018e35414b7f0008")
    private String id;
    @ApiModelProperty(value = "商品品牌名称", example = "可口可乐")
    private String goodsBrandName;
    @ApiModelProperty(value = "商品品牌代码", example = "KC")
    private String goodsBrandCode;
}
