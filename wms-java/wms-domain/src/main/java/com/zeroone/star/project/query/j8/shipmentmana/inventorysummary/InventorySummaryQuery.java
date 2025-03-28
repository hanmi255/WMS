package com.zeroone.star.project.query.j8.shipmentmana.inventorysummary;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */
@Getter
@Setter
public class InventorySummaryQuery extends PageQuery {
    @ApiModelProperty(value = "储位",example = "X1-1-03")
    private String storageLocation;
    @ApiModelProperty(value = "托盘",example = "ATP002")
    private String tray;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    private String goodsNumber;
    @ApiModelProperty(value = "商品名称",example = "牛羊肉半成品")
    private String goodsName;
}
