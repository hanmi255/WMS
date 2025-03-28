package com.zeroone.star.project.dto.j2.msgmw.SQL;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("获取SQL名称列表")
public class SqlNameListDTO {

    @ApiModelProperty(value = "SQL名称", example = "SQL-查询收货预约")
    private String sqlName;
}
