package com.zeroone.star.project.dto.j3.sysmg.catagorymanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("编辑分类")
public class EdgeCatagoryDTO {


    //唯一标识
    @ApiModelProperty(value = "分类的唯一编号", example = "1")
    private String id;

    //图标id
    @ApiModelProperty(value = "图标的唯一编号", example = "1")
    private String iconId;

    //类型名称
    @ApiModelProperty(value = "分类名称", example = "家清")
    private String name;

    //上级id
    @ApiModelProperty(value = "上级id", example = "A01")
    private String parentId;


}
