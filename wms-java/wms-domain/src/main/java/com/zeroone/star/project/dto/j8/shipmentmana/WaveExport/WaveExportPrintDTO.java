package com.zeroone.star.project.dto.j8.shipmentmana.WaveExport;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@TableName("wave_to_down")
public class WaveExportPrintDTO {
    @ApiModelProperty(value = "仓位",example = "X1-1-02")
    @TableField("bin_id")
    private String Positions;
    @ApiModelProperty(value = "商品名称",example = "牛羊肉半成品")
    @TableField("goods_name")
    private String goodsName;
    @ApiModelProperty(value = "基本单位",example = "箱")
    @TableField("base_unit")
    private String unit;
    @ApiModelProperty(value = "生产日期",example = "2024-3-20")
    @TableField("pro_data")
    private String producedTime;
    @ApiModelProperty(value = "数量",example = "44.0")
    @TableField("base_goodscount")
    private float goodsNumber;
    @ApiModelProperty(value = "货主",example = "x00001")
    @TableField("cus_code")
    private String goodsOwner;
    @ApiModelProperty(value = "出库备注",example = "0")
    @TableField("om_bei_zhu")
    private String message;
    @ApiModelProperty(value = "托盘",example = "A")
    @TableField("tin_id")
    private String tuoPan;
    @ApiModelProperty(value = "二维码",example = "123")
    @TableField("shp_tiao_ma")
    private String qrCode;
}
