package com.zeroone.star.project.query.j6.stockln;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("库存查询对象")
public class WvStockQuery extends PageQuery {
    @ApiModelProperty(value = "储位",example = "1")
    private String kuWeiBianMa;
    @ApiModelProperty(value = "托盘",example = "A")
    private String binId;
    @ApiModelProperty(value = "客户编码",example = "001")
    private String cusCode;
    @ApiModelProperty(value = "客户名称",example = "可口可乐饮料有限公司")
    private String zhongWenQch;
    @ApiModelProperty(value = "商品编码",example = "0000")
    private String goodsCode;
    @ApiModelProperty(value = "商品名称",example = "可口可乐")
    private String shpMingCheng;
}
