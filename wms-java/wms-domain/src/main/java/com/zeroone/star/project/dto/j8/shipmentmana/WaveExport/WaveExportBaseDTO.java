package com.zeroone.star.project.dto.j8.shipmentmana.WaveExport;

import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class WaveExportBaseDTO {
    @ApiModelProperty(value = "客户名称",example = "XXXX-KH有限公司")
    @TableField("cus_name")
    private String customerName;
    @ApiModelProperty(value = "波次号",example = "BC20241009174625")
    @TableField("wave_id")
    private String waveNumber;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    @TableField("goods_id")
    private String goodsNumber;
    @ApiModelProperty(value = "仓位",example = "X1-1-02")
    @TableField("bin_id")
    private String Positions;
    @ApiModelProperty(value = "一次性下架容器",example = " ")
    @TableField("first_rq")
    private String containersRemove;
}
