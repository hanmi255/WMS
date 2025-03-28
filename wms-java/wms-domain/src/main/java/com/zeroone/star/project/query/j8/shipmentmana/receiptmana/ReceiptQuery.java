package com.zeroone.star.project.query.j8.shipmentmana.receiptmana;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 回单管理列表查询对象
 */
@Getter
@Setter
@ToString
@ApiModel(value = "查询回单对象")
public class ReceiptQuery extends PageQuery {
    @ApiModelProperty(value = "单号",example = "CK20241011-0002")
    private String receiptId;

    @ApiModelProperty(value = "备注",example = "完成")
    private String comment;

    @ApiModelProperty(value = "货主",example = "710500-可口可乐饮料")
    private String cargoOwner;

    @ApiModelProperty(value = "回单开始时间",example = "2024-09-08 22:54:39")
    private String hdBegin;

    @ApiModelProperty(value = "回单结束时间",example = "2025-02-22 22:54:42")
    private String hdEnd;
}
