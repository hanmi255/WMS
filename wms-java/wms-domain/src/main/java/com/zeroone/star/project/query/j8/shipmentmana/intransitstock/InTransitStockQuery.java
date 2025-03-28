package com.zeroone.star.project.query.j8.shipmentmana.intransitstock;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDate;

/**
 * @ClassName: InTransitStockQuery
 * @Package: com.zeroone.star.project.query.j8.shipmentmana.intransitstock
 * @Description: 在途库存查询
 * @Author: zk
 * @Create: 2025/2/26 - 上午10:36
 */
@Data
@ApiModel("在途库存查询")
public class InTransitStockQuery extends PageQuery {
    @ApiModelProperty(value = "出货订单",example = "3rt3ktl3jkt33")
    private String orderId;
    @ApiModelProperty(value = "出货日期开始",example = "2025-02-26")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate createDateBegin;
    @ApiModelProperty(value = "出货日期结束", example = "2025-02-26")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate createDateEnd;
    @ApiModelProperty(value = "客户编码",example = "KC")
    private String cusCode;
    @ApiModelProperty(value = "客户名称",example = "KC")
    private String zhongWenQch;
    @ApiModelProperty(value = "商品编码",example = "KC")
    private String goodsId;
    @ApiModelProperty(value = "商品名称",example = "KC")
    private String shpMingCheng;
    @ApiModelProperty(value = "出货储位", example = "1")
    private String kuWeiBianMa;
}
