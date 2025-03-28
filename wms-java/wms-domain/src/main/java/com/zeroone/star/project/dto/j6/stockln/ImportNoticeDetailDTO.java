package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@ToString
@Getter
@Setter
@Builder
@ApiModel("进货通知单详细信息显示数据对象")
public class ImportNoticeDetailDTO{

    @ApiModelProperty(value = "商品编码", example = "0000")
    private String goodsName;

    @ApiModelProperty(value = "数量", example = "32")
    private String goodsCount;

    @ApiModelProperty(value = "计划库位", example = "11")
    private String binPlan;

    @ApiModelProperty(value = "收货完成", example = "是")
    private String noticeiSta;
}

