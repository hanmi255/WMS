package com.zeroone.star.project.dto.j7.outmanage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @BelongsProject: 10wms
 * @BelongsPackage: com.zeroone.star.project.j7.dto
 * @Author: ayuan
 * @CreateTime: 2025-02-22
 * @Description:
 */
@ApiModel("出货商品明细")
@Data
public class OutGoodsDetailDTO {
    @ApiModelProperty("出货商品")
    private String goodsName;
    @ApiModelProperty("商品编码")
    private String goodsId;
    @ApiModelProperty("出货数量")
    private String outGoodsNumber;
    @ApiModelProperty("下架任务是否已经生成？")
    private String downGoodsTaskGenerated;
    @ApiModelProperty("sku")
    private String sku;
}
