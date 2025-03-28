package com.zeroone.star.project.query.j8.other.baconttype;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@ToString
@Getter
@Setter
@ApiModel("箱型数据模型")
public class BaContTypeQuery extends PageQuery {

    @ApiModelProperty(value = "箱型id",example = "1")
    private String id;
    @ApiModelProperty(value = "箱型代码",example = "1")
    private String contTypeCode;
    @ApiModelProperty(value = "箱型名称",example = "一号集装箱")
    private String contTypeName;

   /* //查询条件类型 0-箱型代码 1-箱型名称
    @ApiModelProperty(value = "箱型代码",example = "1")
    private Integer QueryType;

    //查询条件值
    @ApiModelProperty(value = "查询值",example = "7")
    private String Value;*/
}
