package com.zeroone.star.project.query.j8.other.port;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("港口信息导出查询对象")
public class PortExportQuery {
    @ApiModelProperty(value = "港口代码", example = "yjq")
    private String portCode;
    @ApiModelProperty(value = "中文名称", example = "yjq")
    private String portZhName;
    @ApiModelProperty(value = "英文名称", example = "yjq")
    private String portEnName;
    @ApiModelProperty(value = "港口三字代码", example = "yjq")
    private String portThCode;
}
