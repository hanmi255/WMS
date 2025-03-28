package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@ApiModel("运输订单明细")
@Data
public class TransportOrderDetailDTO implements Serializable {

    @ApiModelProperty(value = "发货人", notes = "对应参考系统快递公司（难绷，谁能想到数据库里是发货人）")
    private String fahuoren;

    @ApiModelProperty("运单号")
    private String fadh;

    @ApiModelProperty("费用")
    private String jiage;

    @ApiModelProperty("备注")
    private String ywddbz;
}
