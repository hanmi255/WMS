package com.zeroone.star.project.vo.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("传输数据对象")
public class DaochuHhVO {

    @ApiModelProperty(value = "文件url", example = "XXXXXX")
    private String url;
}
