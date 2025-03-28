package com.zeroone.star.project.dto.j2.msgmw.SQL;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("获取SQL列表(条件+分页)")
public class SqlListDTO extends SqlBaseDTO {
    @ApiModelProperty(value = "SQL的唯一标识ID", example = "1")
    private String sqlId;
}