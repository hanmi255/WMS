package com.zeroone.star.project.dto.j8.shipmentmana.WaveExport;

import com.alibaba.excel.annotation.ExcelProperty;
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
public class WaveExportDetailDTO {
    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    @TableField("create_by")
    @ExcelProperty(value = "创建人登录名称",index = 0)
    private String createdLoginMemberName;
    @ApiModelProperty(value = "创建人名称",example = "管理员")
    @TableField("create_name")
    @ExcelProperty(value = "创建人名称",index = 1)
    private String createdMemberName;
    @ApiModelProperty(value = "货主",example = "x00001")
    @TableField("cus_code")
    @ExcelProperty(value = "货主",index = 2)
    private String goodsOwner;
    @ApiModelProperty(value = "客户名称",example = "XXXX-KH有限公司")
    @TableField("cus_name")
    @ExcelProperty(value = "客户名称",index = 3)
    private String customerName;
    @ApiModelProperty(value = "波次号",example = "BC20241009174625")
    @TableField("wave_id")
    @ExcelProperty(value = "waveId",index = 4)
    private String waveId;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    @TableField("goods_id")
    @ExcelProperty(value = "商品编码",index = 5)
    private String goodsId;
    @ApiModelProperty(value = "商品名称",example = "牛羊肉半成品")
    @TableField("im_cus_code")
    @ExcelProperty(value = "商品名称",index = 6)
    private String goodsName;
    @ApiModelProperty(value = "imCusCode",example = "123")
    @TableField("bin_id")
    @ExcelProperty(value = "imCusCode",index = 7)
    private String imCusCode;
    @ApiModelProperty(value = "仓位",example = "X1-1-02")
    @TableField("tin_id")
    @ExcelProperty(value = "仓位",index = 8)
    private String Positions;
    @ApiModelProperty(value = "托盘",example = "ATP002")
    @TableField("pro_data")
    @ExcelProperty(value = "托盘",index = 9)
    private String tray;
    @ApiModelProperty(value = "生产日期",example = "2024-3-20")
    @TableField("pro_data")
    @ExcelProperty(value = "生产日期",index = 10)
    private String producedTime;
    @ApiModelProperty(value = "数量",example = "44.0")
    @TableField("base_goodscount")
    @ExcelProperty(value = "baseGoodscount",index = 11)
    private float goodsNumber;
    @ApiModelProperty(value = "基本单位",example = "箱")
    @TableField("base_unit")
    @ExcelProperty(value = "基本单位",index = 12)
    private String unit;
    @ApiModelProperty(value = "出库备注",example = "0")
    @TableField("om_bei_zhu")
    @ExcelProperty(value = "omBeiZhu",index = 13)
    private String omBeiZhu;
    @ApiModelProperty(value = "firstRq",example = " ")
    @TableField("first_rq")
    @ExcelProperty(value = "firstRq",index = 14)
    private String firstRq;
    @ApiModelProperty(value = "secondRq",example = " ")
    @TableField("second_rq")
    @ExcelProperty(value = "secondRq",index = 15)
    private String secondRq;
    @ApiModelProperty(value = "by1",example = " ")
    @TableField("by1")
    @ExcelProperty(value = "by1",index = 16)
    private String by1;
    @ApiModelProperty(value = "by2",example = " ")
    @TableField("by2")
    @ExcelProperty(value = "by2",index = 17)
    private String by2;
    @ApiModelProperty(value = "by3",example = " ")
    @TableField("by3")
    @ExcelProperty(value = "by3",index = 18)
    private String by3;
    @ApiModelProperty(value = "by4",example = " ")
    @TableField("by4")
    @ExcelProperty(value = "by4",index = 19)
    private String by4;
    @ApiModelProperty(value = "by5",example = " ")
    @TableField("by5")
    @ExcelProperty(value = "by5",index = 20)
    private String by5;
}
