package com.zeroone.star.project.dto.j8.shipmentmana.WaveExport;

import com.alibaba.excel.annotation.ExcelProperty;
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
public class WaveExportExcelDTO extends WaveExportDetailDTO{

    @ApiModelProperty(value = "商品条码",example = "123")
    @TableField("shp_tiao_ma")
    @ExcelProperty(value = "商品条码",index = 21)
    private String shpTiaoMa;

}
