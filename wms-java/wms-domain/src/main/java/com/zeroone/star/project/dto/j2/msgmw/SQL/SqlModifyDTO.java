package com.zeroone.star.project.dto.j2.msgmw.SQL;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("修改SQL")
public class SqlModifyDTO extends SqlBaseDTO{
    @ApiModelProperty(value = "SQL的唯一标识ID", example = "1")
    private String sqlId;
}
