package com.zeroone.star.project.dto.j7.zccheck;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.time.LocalDateTime;
/**
 * <p>
 * 描述：获取复核列表DTO
 * </p>
 *
 * @author keyuan
 * @since 2025/2/28 17:08
 */
@ApiModel("复核列表")
@Data
public class CheckListDTO {
    @ApiModelProperty(value = "下架人")
    private String createName;
    @ApiModelProperty(value = "下架时间")
    private LocalDateTime createDate;
    @ApiModelProperty(value = "复核人")
    private String updateName;
    @ApiModelProperty(value = "复核时间")
    private LocalDateTime updateDate;
    @ApiModelProperty(value = "原始单据编码")
    private String orderId;
    @ApiModelProperty(value = "商品编码")
    private String goodsId;
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;
    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
    @ApiModelProperty(value = "数量")
    private String goodsQuaok;
    //@ApiModelProperty(value = "复核数量") //前端有，但后端没有
    @ApiModelProperty(value = "单位")
    private String goodsUnit;
    @ApiModelProperty(value = "生产日期")
    private String goodsProData;
    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;
    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;
    @ApiModelProperty(value = "货主")
    private String cusCode;
    @ApiModelProperty(value = "目标托盘")
    private String binIdTo;
}