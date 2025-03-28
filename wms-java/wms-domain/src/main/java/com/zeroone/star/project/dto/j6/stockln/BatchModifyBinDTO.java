package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("批量修改储位的请求参数")
public class BatchModifyBinDTO {

    @ApiModelProperty(value = "待修改记录的 id 列表", required = true)
    private List<String> ids;  // 要修改的记录 id 列表

    @ApiModelProperty(value = "新的储位值", required = true)
    private String binId;      // 新的储位值
}
