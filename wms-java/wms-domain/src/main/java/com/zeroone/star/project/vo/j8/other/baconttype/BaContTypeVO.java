package com.zeroone.star.project.vo.j8.other.baconttype;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("箱型数据模型")
public class BaContTypeVO {
    @ApiModelProperty(value = "箱型id",example = "1")
    private String id;
    @ApiModelProperty(value = "箱型名称",example = "一号集装箱")
    private String contTypeName;
    @ApiModelProperty(value = "箱型代码",example = "1")
    private String contTypeCode;
}
