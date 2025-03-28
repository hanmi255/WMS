package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("入库通知对象")
public class ImNoticeDTO {

    @ApiModelProperty(value = "主键", example = "8a9485a995413dfb01954155c0ef0034")
    private String id;

    @ApiModelProperty(value = "创建人名称", example = "管理员")
    private String createName;  // create_name -> createName

    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    private String createBy;    // create_by -> createBy

    @ApiModelProperty(value = "创建日期", example = "2025-02-26 16:18:14")
    private LocalDateTime createDate;  // create_date -> createDate

    @ApiModelProperty(value = "更新人名称", example = "管理员")
    private String updateName;  // update_name -> updateName

    @ApiModelProperty(value = "更新人登录名称", example = "admin")
    private String updateBy;    // update_by -> updateBy

    @ApiModelProperty(value = "更新日期", example = "2025-02-26 16:28:27")
    private LocalDateTime updateDate;  // update_date -> updateDate

    @ApiModelProperty(value = "所属部门", example = "A05")
    private String sysOrgCode;  // sys_org_code -> sysOrgCode

    @ApiModelProperty(value = "所属公司", example = "A05")
    private String sysCompanyCode;  // sys_company_code -> sysCompanyCode

    @ApiModelProperty(value = "到货通知单号", example = "RK20250226-0003")
    private String imNoticeId;  // im_notice_id -> imNoticeId

    @ApiModelProperty(value = "到货通知行项目", example = "8a9485a995413dfb019541536349002d")
    private String imNoticeItem;  // im_notice_item -> imNoticeItem

    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String goodsCode;  // goods_code -> goodsCode

    @ApiModelProperty(value = "数量", example = "36")
    private Integer goodsCount;  // goods_count -> goodsCount

    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String goodsPrdData;  // goods_prd_data -> goodsPrdData

    @ApiModelProperty(value = "批次", example = "2025-02-02")
    private String goodsBatch;  // goods_batch -> goodsBatch

    @ApiModelProperty(value = "库位整理状态", example = "整理中")
    private String binPre;  // bin_pre -> binPre

    @ApiModelProperty(value = "体积", example = "4500000.0")
    private Double goodsFvol;  // goods_fvol -> goodsFvol

    @ApiModelProperty(value = "重量", example = "1800.0")
    private Double goodsWeight;  // goods_weight -> goodsWeight

    @ApiModelProperty(value = "计划库位", example = "A01")
    private String binPlan;  // bin_plan -> binPlan

    @ApiModelProperty(value = "单位", example = "箱")
    private String goodsUnit;  // goods_unit -> goodsUnit

    @ApiModelProperty(value = "未清数量", example = "36")
    private Integer goodsWqmCount;  // goods_wqm_count -> goodsWqmCount

    @ApiModelProperty(value = "收货登记数量", example = "36.0")
    private Double goodsQmCount;  // goods_qm_count -> goodsQmCount

    @ApiModelProperty(value = "行项目状态", example = "待处理")
    private String noticeiSta;  // noticei_sta -> noticeiSta

    @ApiModelProperty(value = "基本单位", example = "箱")
    private String baseUnit;  // base_unit -> baseUnit

    @ApiModelProperty(value = "基本单位数量", example = "36.0")
    private Double baseGoodscount;  // base_goodscount -> baseGoodscount

    @ApiModelProperty(value = "基本单位收货数量", example = "36.0")
    private Double baseQmcount;  // base_qmcount -> baseQmcount

    @ApiModelProperty(value = "货物名称", example = "小蓝管")
    private String goodsName;  // goods_name -> goodsName

    @ApiModelProperty(value = "其他ID", example = "其他信息")
    private String otherId;  // other_id -> otherId

    @ApiModelProperty(value = "到货客户代码", example = "X00001")
    private String imCusCode;  // im_cus_code -> imCusCode

    @ApiModelProperty(value = "到货备注", example = "备注内容")
    private String imBeizhu;  // im_beizhu -> imBeizhu

    @ApiModelProperty(value = "条形码", example = "1234567890123")
    private String barcode;  // barcode -> barcode

    @ApiModelProperty(value = "规格", example = "规格说明")
    private String shpGuiGe;  // shp_gui_ge -> shpGuiGe

    @ApiModelProperty(value = "保质期", example = "有效期至2026-02-02")
    private String bzhiQi;  // BZHI_QI -> bzhiQi

    @ApiModelProperty(value = "产品属性", example = "属性描述")
    private String chpShuXing;  // chp_shu_xing -> chpShuXing

    @ApiModelProperty(value = "托盘ID", example = "tid001")
    private String tinId;  // tin_id -> tinId
}