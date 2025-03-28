package com.zeroone.star.project.dto.j4.automaticEncoding;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;
import java.util.List;

@Data
@Getter
@Setter
@ToString
@ApiModel(value = "ImportExcelDTO", description = "导自入动编码")
public class ImportExcelDTO {
    
    @ApiModelProperty(value = "编号类型 ID 列表", example = "[\"402881b2653ba3dd01653bc236250007\"]")
    private List<String> ids;

    @ApiModelProperty(value = "创建起始日期", example = "2024-01-01")
    private Date startDate;

    @ApiModelProperty(value = "创建结束日期", example = "2024-02-01")
    private Date endDate;
}
