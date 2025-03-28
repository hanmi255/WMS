package com.zeroone.star.project.query.j2.msgmw.SQL;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class SqlQuery extends PageQuery {

    @ApiModelProperty(value = "SQL名称", example = "SQL-查询收货预约")
    private String sqlName;

    @ApiModelProperty(value = "SQL内容", example = "SELECT * FROM table_name")
    private String sqlContent;
}