package com.zeroone.star.project.dto.j7.adpick;
import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import javax.validation.constraints.NotNull;
/**
 * 修改拣货单对象
 *
 * @author Lin
 * @since 2025/3/15
 */
@Data
@ApiModel("拣货单基础对象")
public class AdPickModifyBaseDTO {
    //下面两个变量为定位字段
    /**
     * 商品名称
     */
    @NotNull(message = "客户订单号不能为空")
    @ApiModelProperty(value = "商品名称")
    private String goodsName;
    /**
     * 客户订单号
     */
    @NotNull(message = "客户订单号不能为空")
    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;
    /**
     * 数量
     */
    @ApiModelProperty(value = "数量")
    private String goodsQua;
    /**
     * 完成数量
     */
    @ApiModelProperty(value = "完成数量")
    private String goodsQuaok;
    /**
     * 基本单位数量
     */
    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;
    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生产日期")
    private String goodsProData;
    /**
     * 源托盘码
     */
    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;
    /**
     * 库位编码
     */
    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;
}