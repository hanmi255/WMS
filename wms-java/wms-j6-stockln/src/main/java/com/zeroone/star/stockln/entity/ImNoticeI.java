package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.IdType;
import java.time.LocalDateTime;
import com.baomidou.mybatisplus.annotation.TableId;
import java.io.Serializable;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

/**
 * <p>
 * 预约进货通知明细
 * </p>
 *
 * @author Backa
 * @since 2025-03-04
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@TableName("wm_im_notice_i")
@ApiModel(value="ImNoticeI对象", description="预约进货通知明细")
public class ImNoticeI implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "主键")
    @TableId(value = "id", type = IdType.AUTO)
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

    @ApiModelProperty(value = "到货通知单号")
    private String imNoticeId;

    @ApiModelProperty(value = "到货通知项目")
    private String imNoticeItem;

    @ApiModelProperty(value = "商品编码")
    private String goodsCode;

    @ApiModelProperty(value = "数量")
    private String goodsCount;

    @ApiModelProperty(value = "生产日期")
    private LocalDateTime goodsPrdData;

    @ApiModelProperty(value = "批次")
    private String goodsBatch;

    @ApiModelProperty(value = "库位整理")
    private String binPre;

    @ApiModelProperty(value = "体积")
    private String goodsFvol;

    @ApiModelProperty(value = "重量")
    private String goodsWeight;

    @ApiModelProperty(value = "计划库位")
    private String binPlan;

    @ApiModelProperty(value = "单位")
    private String goodsUnit;

    @ApiModelProperty(value = "未清数量")
    private String goodsWqmCount;

    @ApiModelProperty(value = "收货登记数量")
    private String goodsQmCount;

    @ApiModelProperty(value = "行项目状态")
    private String noticeiSta;

    @ApiModelProperty(value = "基本单位")
    private String baseUnit;

    @ApiModelProperty(value = "基本单位数量")
    private String baseGoodscount;

    @ApiModelProperty(value = "基本单位收货数量")
    private String baseQmcount;

    private String goodsName;

    private String otherId;

    private String imCusCode;

    private String imBeizhu;

    private String barcode;

    @ApiModelProperty(value = "规格")
    private String shpGuiGe;

    private String bzhiQi;

    @ApiModelProperty(value = "产品属性")
    private String chpShuXing;

    private String tinId;


}
