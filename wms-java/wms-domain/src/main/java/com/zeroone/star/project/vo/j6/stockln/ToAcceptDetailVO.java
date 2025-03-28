package com.zeroone.star.project.vo.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：待验收货物详细展示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu
 * @version 1.0.0
 */
@Data
@ApiModel("待验收货物详细展示对象")
public class ToAcceptDetailVO {
    /**
     * 到货通知单编号
     */
    @ApiModelProperty(value = "到货通知单编号", example = "IMC123456789", required = true)
    private String imNoticeId;

    /**
     * 商品编码
     */
    @ApiModelProperty(value = "商品编码", example = "G00001", required = true)
    private String goodsCode;

    /**
     * 货主
     */
    @ApiModelProperty(value = "到货客户代码", example = "X00001")
    private String imCusCode;  // im_cus_code -> imCusCode

    /**
     * 储位
     */
    @ApiModelProperty(value = "储位", example = "BIN001", required = true)
    private String binPlan;
}