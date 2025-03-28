package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("进货通知单明细")
public class ImportNoticeItemDTO {

    @ApiModelProperty(value = "商品编号",example = "20292")
    private String goodsCode;

    @ApiModelProperty(value = "数量",example = "100")
    private String goodsCount;

    @ApiModelProperty(value = "计划占用存储位数",example = "10")
    private String binPlan;

    @ApiModelProperty(value = "收货完成",allowableValues = "Y N I")
    private String binPre;
}
