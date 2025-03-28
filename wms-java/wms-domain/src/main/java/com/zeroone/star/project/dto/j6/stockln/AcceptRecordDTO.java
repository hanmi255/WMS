package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("收货登记表的实体类")
public class AcceptRecordDTO {

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

    @ApiModelProperty(value = "到货通知单", example = "RK20250226-0003")
    private String imNoticeId;  // im_notice_id -> imNoticeId

    @ApiModelProperty(value = "到货通知行项目", example = "8a9485a995413dfb019541536349002d")
    private String imNoticeItem;  // im_notice_item -> imNoticeItem

    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String goodsId;  // goods_id -> goodsId

    @ApiModelProperty(value = "到货数量", example = "36")
    private String imQuat;  // im_quat -> imQuat

    @ApiModelProperty(value = "收货数量", example = "36.0")
    private String qmOkQuat;  // qm_ok_quat -> qmOkQuat

    @ApiModelProperty(value = "备注", example = "良品")
    private String itemText;  // item_text -> itemText

    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String proData;  // pro_data -> proData

    @ApiModelProperty(value = "托盘", example = "A")
    private String tinId;  // tin_id -> tinId

    @ApiModelProperty(value = "商品单位", example = "箱")
    private String goodsUnit;  // goods_unit -> goodsUnit

    @ApiModelProperty(value = "批次", example = "2025-02-02")
    private String goodsBatch;  // goods_batch -> goodsBatch

    @ApiModelProperty(value = "仓位", example = "")
    private String binId;  // bin_id -> binId

    @ApiModelProperty(value = "体积", example = "4500000.0")
    private String tinTj;  // tin_tj -> tinTj

    @ApiModelProperty(value = "重量", example = "1800.0")
    private String tinZhl;  // tin_zhl -> tinZhl

    @ApiModelProperty(value = "是否已上架", example = "N")
    private String binSta;  // bin_sta -> binSta

    @ApiModelProperty(value = "货主", example = "X00001")
    private String cusCode;  // cus_code -> cusCode

    @ApiModelProperty(value = "温度", example = "25")
    private String recDeg;  // rec_deg -> recDeg

    @ApiModelProperty(value = "基本单位", example = "箱")
    private String baseUnit;  // base_unit -> baseUnit

    @ApiModelProperty(value = "基本单位数量", example = "36.0")
    private String baseGoodscount;  // base_goodscount -> baseGoodscount

    @ApiModelProperty(value = "基本单位收货数量")
    private String baseQmcount;  // base_qmcount -> baseQmcount

    @ApiModelProperty(value = "公司名称", example = "YYY-有限公司")
    private String cusName;  // cus_name -> cusName*

    @ApiModelProperty(value = "商品名称", example = "小蓝管")
    private String goodsName;  // goods_name -> goodsName*

    @ApiModelProperty(value = "入库单号", example = "A123")
    private String imCusCode;  // IM_CUS_CODE -> imCusCode*

    @ApiModelProperty(value = "数量1", example = "40")
    private String baseInGoodscount;  // base_in_goodscount -> baseInGoodscount

    @ApiModelProperty(value = "数量2", example = "30")
    private String baseOutGoodscount;  // base_out_goodscount -> baseOutGoodscount



}
