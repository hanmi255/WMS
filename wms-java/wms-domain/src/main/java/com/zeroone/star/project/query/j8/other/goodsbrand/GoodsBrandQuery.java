package com.zeroone.star.project.query.j8.other.goodsbrand;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @ClassName: GoodsBrandQuery
 * @Package: com.zeroone.star.project.query.j8.other.goodsbrand
 * @Description:
 * @Author: zk
 * @Create: 2025/2/26 - 上午9:26
 */
@Data
@ApiModel("商品品牌查询对象")
public class GoodsBrandQuery extends PageQuery {
    @ApiModelProperty(value = "商品品牌编号", example = "KC")
    private String goodsBrandCode;
    @ApiModelProperty(value = "商品品牌名称", example = "可口可乐")
    private String goodsBrandName;
    @ApiModelProperty(value = "排序字段", example = "goods_brand_www")
    private String sort;
    @ApiModelProperty(value = "排序方式(asc-升序，desc-降序)", example = "asc")
    private String order;
}
