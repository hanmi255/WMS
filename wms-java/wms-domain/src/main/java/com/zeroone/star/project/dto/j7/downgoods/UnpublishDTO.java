package com.zeroone.star.project.dto.j7.downgoods;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 出库任务下架数据传输对象
 * </p>
 *
 * @author King
 * @since 2025-02-25
 */
@Data
@ApiModel("出库任务下架数据传输对象")
public class UnpublishDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "主键")
    private String id;

    @ApiModelProperty(value = "创建人名称")
    private String createName;

    @ApiModelProperty(value = "创建人登录名称")
    private String createBy;

    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "更新人名称")
    private String updateName;

    @ApiModelProperty(value = "更新人登录名称")
    private String updateBy;

    @ApiModelProperty(value = "更新日期")
    private LocalDateTime updateDate;

    @ApiModelProperty(value = "所属部门")
    private String sysOrgCode;

    @ApiModelProperty(value = "所属公司")
    private String sysCompanyCode;

    @ApiModelProperty(value = "商品编码")
    private String goodsId;

    @ApiModelProperty(value = "数量")
    private String goodsQua;

    @ApiModelProperty(value = "完成数量")
    private String goodsQuaok;

    @ApiModelProperty(value = "原始单据编码")
    private String orderId;

    @ApiModelProperty(value = "原始单据行项目")
    private String orderIdI;

    @ApiModelProperty(value = "原始单据类型")
    private String orderType;

    @ApiModelProperty(value = "单位")
    private String goodsUnit;

    @ApiModelProperty(value = "生产日期")
    private String goodsProData;

    @ApiModelProperty(value = "批次")
    private String goodsBatch;

    @ApiModelProperty(value = "作业类型")
    private String actTypeCode;

    @ApiModelProperty(value = "库位编码")
    private String kuWeiBianMa;

    @ApiModelProperty(value = "目标托盘")
    private String binIdTo;

    @ApiModelProperty(value = "源托盘码")
    private String binIdFrom;

    @ApiModelProperty(value = "货主")
    private String cusCode;

    @ApiModelProperty(value = "状态")
    private String downSta;

    @ApiModelProperty(value = "基本单位")
    private String baseUnit;

    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;

    @ApiModelProperty(value = "商品名称")
    private String goodsName;

    @ApiModelProperty(value = "客户编码")
    private String imCusCode;

    @ApiModelProperty(value = "备注")
    private String omBeiZhu;
}