package com.zeroone.star.project.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("待上架货物查询回显对象")
public class ToShelvesVO {
    @ApiModelProperty(value = "托盘编号",example = "AAA")
    private String tinId;

    @ApiModelProperty(value = "货主编码",example = "123456789",required = true)
    private String cusCode;

    @ApiModelProperty(value = "货主名称",example = "YYY-有限公司")
    private String cusName;

    @ApiModelProperty(value = "商品编码",example = "123456789-小蓝管-支")
    private String goodsId;

    @ApiModelProperty(value = "到货数量",example = "10")
    private Integer imQuat;

    @ApiModelProperty(value = "单位",example = "箱")
    private String goodsUnit;

    @ApiModelProperty(value = "生产日期",example = "2099-12-31")
    private String proData;

    @ApiModelProperty(value = "收获日期",example = "2024-10-09 11:46:30")
    private String harvestTime;

    @ApiModelProperty(value = "保质期（天）",example = "360")
    private String bzhQi;
}
