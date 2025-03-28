package com.zeroone.star.project.vo.j8.shipmentmana.inventorysummary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2025.2.25
 */
@Data
@ApiModel("库存总表VO")
public class InventorySummaryVo {

    @ApiModelProperty(value = "储位",example = "X1-1-03")
    private String storageLocation;
    @ApiModelProperty(value = "托盘",example = "ATP002")
    private String tray;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    private String goodsNumber;
    @ApiModelProperty(value = "商品名称",example = "牛羊肉半成品")
    private String goodsName;
    @ApiModelProperty(value = "规格",example = "ATP002")
    private String specification;
    @ApiModelProperty(value = "单位",example = "箱")
    private String unit;
    @ApiModelProperty(value = "总库存", example = "1000")
    private long totalStock;
    @ApiModelProperty(value = "待下架库存", example = "-44")
    private long pendingRemovalStock;
    @ApiModelProperty(value = "可用库存", example = "956")
    private long availableStock;
    @ApiModelProperty(value = "生产日期",example = "2099-12-31")
    private LocalDate producedTime;
    @ApiModelProperty(value = "保质期", example = "360")
    private int shelfLife; // 保质期，单位：天
    @ApiModelProperty(value = "到期日", example = "2100-12-26")
    private LocalDate expirationDate;
    @ApiModelProperty(value = "库位类型", example = "存储储位")
    private String storageLocationType;
}
