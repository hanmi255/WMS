package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;


@Data
@ApiModel("传输数据对象")
public class DaochuHhDTO {

    @ApiModelProperty(value = "数据id列表", example = "XXXXXXXXX")
    private List<String> list;

}
