package com.zeroone.star.project.vo.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("收货登记对象")
public class InboundQmIVO {

    @ApiModelProperty(value = "创建人名称", example = "管理员")
    private String createName;  // create_name -> createName

    @ApiModelProperty(value = "收货日期", example = "2025-02-26 16:18:14")
    private LocalDateTime createDate;  // create_date -> createDate

    @ApiModelProperty(value = "到货通知单", example = "RK20250226-0003")
    private String imNoticeId;  // im_notice_id -> imNoticeId

    @ApiModelProperty(value = "客户订单号", example = "A123")
    private String imCusCode;  // IM_CUS_CODE -> imCusCode*

    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String goodsId;  // goods_id -> goodsId

    @ApiModelProperty(value = "商品名称", example = "小蓝管")
    private String goodsName;  // goods_name -> goodsName*

    @ApiModelProperty(value = "到货数量", example = "36")
    private String imQuat;  // im_quat -> imQuat

    @ApiModelProperty(value = "收货数量", example = "36.0")
    private String qmOkQuat;  // qm_ok_quat -> qmOkQuat

    @ApiModelProperty(value = "备注", example = "良品")
    private String itemText;  // item_text -> itemText

    @ApiModelProperty(value = "温度", example = "25")
    private String recDeg;  // rec_deg -> recDeg

    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String proData;  // pro_data -> proData

    @ApiModelProperty(value = "托盘", example = "A")
    private String tinId;  // tin_id -> tinId

    @ApiModelProperty(value = "商品单位", example = "箱")
    private String goodsUnit;  // goods_unit -> goodsUnit

    @ApiModelProperty(value = "仓位", example = "")
    private String binId;  // bin_id -> binId

    @ApiModelProperty(value = "体积", example = "4500000.0")
    private String tinTj;  // tin_tj -> tinTj

    @ApiModelProperty(value = "重量", example = "1800.0")
    private String tinZhl;  // tin_zhl -> tinZhl

    @ApiModelProperty(value = "基本单位", example = "箱")
    private String baseUnit;  // base_unit -> baseUnit

    @ApiModelProperty(value = "基本单位数量", example = "36.0")
    private String baseGoodscount;  // base_goodscount -> baseGoodscount

    @ApiModelProperty(value = "数量1", example = "40")
    private String baseInGoodscount;  // base_in_goodscount -> baseInGoodscount

    @ApiModelProperty(value = "数量2", example = "30")
    private String baseOutGoodscount;  // base_out_goodscount -> baseOutGoodscount

    @ApiModelProperty(value = "公司名称", example = "YYY-有限公司")
    private String cusName;  // cus_name -> cusName*

    @ApiModelProperty(value = "是否已上架", example = "N")
    private String binSta;  // bin_sta -> binSta

}
