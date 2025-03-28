package com.zeroone.star.project.dto.j7.adpick;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.plugins.pagination.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;
import java.util.Date;

/**<p>
 *      修改拣货单对象
 * </p>
 * @author 阿晨
 * @since 2025-2-25
 */
@ApiModel("按单拣货可修改对象")
@Getter
@Setter
public class AdPickDTO {
    @ApiModelProperty(value = "主键", example = "123e4567-e89b-12d3-a456-426614174000")
    private String id;
    @ApiModelProperty(value = "原始单据编码", example = "CK20250223-0003")
    private String originalDocumentCode;
    @ApiModelProperty(value = "原始单据类型")
    private String orderIdType;
    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String productCode;
    @ApiModelProperty(value = "备注", example = "这是一件...")
    private String remark;
    @ApiModelProperty(value = "数量", example = "10000")
    private Integer quantity;
    @ApiModelProperty(value = "复核数量", example = "10000")
    private Integer verifiedQuantity;
    @ApiModelProperty(value = "基本单位")
    private double basicUnit;
    @ApiModelProperty(value = "单位")
    private double unit;
    @ApiModelProperty(value = "源托盘码", example = "A")
    private String sourcePalletCode;
    @ApiModelProperty(value = "目标托盘")
    private String aimTuoPan;
    @ApiModelProperty(value = "库位编码", example = "X1-1-02")
    private String storageLocationCode;
    @ApiModelProperty(value = "货主", example = "X00001-halo")
    private String cargoOwner;
    @ApiModelProperty(value = "生产日期", example = "2025-02-23")
    private LocalDateTime productTime;
    @ApiModelProperty(value = "创建日期")
    private Date createTime;
    @ApiModelProperty(value = "状态")
    private String status;
    @ApiModelProperty(value = "作业类型")
    private String workType;

}
