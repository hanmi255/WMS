package com.zeroone.star.project.dto.j2.msgmw.SQL;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@Getter
@Setter
@ToString
@ApiModel("删除SQL")
public class SqlDeleteDTO {
    @ApiModelProperty(value = "单个SQL的唯一标识ID（用于单个删除）", example = "1")
    private String sqlId;

    @ApiModelProperty(value = "多个SQL的唯一标识ID列表（用于批量删除）", example = "[\"1\",\"2\",\"3\"]")
    private List<String> sqlIdList;
}
