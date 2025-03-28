package com.zeroone.star.project.dto.j6.stockln;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("录入待上架货物前端传来请求对应的实体类")
@TableName("wm_in_qm_i")
public class ToShelvesDTO {

    @ApiModelProperty(value = "到货通知单编号", example = "RK20250226-0003")
    private String imNoticeId;    // 到货通知单编号

    @ApiModelProperty(value = "商品编码", example = "RL001")
    private String goodsId;       // 商品编码

    @ApiModelProperty(value = "货主", example = "X00001")
    private String cusCode;       // 货主

    @ApiModelProperty(value = "储位", example = "A-01-01")
    private String binId;         // 储位

    // 新增的字段，用于用户填写的内容
    @ApiModelProperty(value = "验收数量", example = "36")
    private String imQuat;  // 用户填写的数量 (到货数量)

    @ApiModelProperty(value = "生产日期", example = "2025-02-02")
    private String proData;  // 用户填写的生产日期

    @ApiModelProperty(value = "批次", example = "BATCH001")
    private String goodsBatch; // 用户填写的批次

    @ApiModelProperty(value = "收货温度(°C)", example = "25")
    private String recDeg;     // 用户填写的收货温度

    @ApiModelProperty(value = "备注", example = "良品")
    private String itemText;   // 用户填写的备注

    @ApiModelProperty(value = "托盘", example = "A1")
    private String tinId;      // 用户填写的托盘

    @ApiModelProperty(value = "入库货物数量")
    private String baseInGoodscount;


}
