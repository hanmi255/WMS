package com.zeroone.star.project.dto.j2.msgmw.SQL;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class SqlBaseDTO {
    @ApiModelProperty(value = "SQL名称", example = "SQL-查询收货预约")
    private String sqlName;

    @ApiModelProperty(value = "SQL内容", example = "SELECT * FROM relevant_table WHERE condition")
    private String sqlContent;
}