package com.zeroone.star.project.query.j8.shipmentmana.manyreceipts;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

/**
 * <p>
 * 描述：批量回单查询
 * </p>
 * @author csy
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@Data
public class ManyReceiptsQuery extends PageQuery {
    @ApiModelProperty(value = "客户订单号",example = "XXXX...")
    private String coustomerOrederNo;
    @ApiModelProperty(value = "备注",example = "这是一条备注")
    private String remark;
    @ApiModelProperty(value = "出货单号",example = "CK20240925-0002")
    private String deliveryNo;
    @ApiModelProperty(value = "客户",example = "710500-可口可乐饮料有限公司")
    private String customer;
    @ApiModelProperty(value = "回单开始时间",example = "yyyy-MM-dd")
    private Date receiptStartTime;
    @ApiModelProperty(value = "回单结束时间",example = "yyyy-MM-dd")
    private Date receiptEndTime;
    @ApiModelProperty(value = " 收货人",example = "张三")
    private String consignee;
    @ApiModelProperty(value = "收货人电话",example = "1xx-xxxx-xxxx")
    private String consigneePhone;
    @ApiModelProperty(value = "承运人",example = "李四")
    private String carrier;
    @ApiModelProperty(value = "承运人电话",example = "1xx-xxxx-xxxx")
    private String carrierPhone;
    @ApiModelProperty(value = "承运人车牌号",example = "粤B88888")
    private String carrierCarNumber;
    @ApiModelProperty(value = "发获月台",example = "可乐")
    private String platNo;
    @ApiModelProperty(value = "回单状态",example = "未完成,复合完成")
    private String receiptStatus;
}
