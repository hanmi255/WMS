package com.zeroone.star.project.dto.j8.shipmentmana.WaveExport;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@TableName("wave_to_down")
public class WaveExportListDTO extends WaveExportBaseDTO{
    //@ApiModelProperty(value = "操作",example = "波次拣货单")
    //@TableField("")
    //private String operation;
    @ApiModelProperty(value = "创建人登录名称",example = "admin")
    @TableField("create_by")
    private String createdLoginMemberName;

    @ApiModelProperty(value = "创建人名称",example = "管理员")
    @TableField("create_name")
    private String createdMemberName;

    @ApiModelProperty(value = "货主",example = "x00001")
    @TableField("cus_code")
    private String goodsOwner;

    @ApiModelProperty(value = "商品名称",example = "牛羊肉半成品")
    @TableField("goods_name")
    private String goodsName;

    @ApiModelProperty(value = "单号",example = "123")
    @TableField("im_cus_code")
    private String number;

    @ApiModelProperty(value = "托盘",example = "ATP002")
    @TableField("tin_id")
    private String tray;

    @ApiModelProperty(value = "生产日期",example = "2024-3-20")
    @TableField("pro_data")
    private String producedTime;

    @ApiModelProperty(value = "数量",example = "44.0")
    @TableField("base_goodscount")
    private float goodsNumbers;

    @ApiModelProperty(value = "出库备注",example = "0")
    @TableField("om_bei_zhu")
    private String message;

    @ApiModelProperty(value = "基本单位",example = "箱")
    @TableField("base_unit")
    private String unit;

    @ApiModelProperty(value = "分拣容器",example = "123")
    @TableField("second_rq")
    private String containersSorting;
}
