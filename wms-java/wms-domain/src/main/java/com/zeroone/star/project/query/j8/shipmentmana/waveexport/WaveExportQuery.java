package com.zeroone.star.project.query.j8.shipmentmana.waveexport;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 分页查询数据
 */
@Getter
@Setter
@ToString
public class WaveExportQuery extends PageQuery {
    @ApiModelProperty(value = "客户名称",example = "XXXX-KH有限公司")
    private String customerName;
    @ApiModelProperty(value = "波次号",example = "BC20241009174625")
    private String waveNumber;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    private String goodsNumber;
    @ApiModelProperty(value = "仓位",example = "X1-1-02")
    private String Positions;
    @ApiModelProperty(value = "一次性下架容器",example = " ")
    private String containersRemove;
}
