package com.zeroone.star.project.query.j3.sysmg.catagorymanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


/*
用来返回分类
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("查询分类")
public class CatagoryQuery {

    //分类id
    @ApiModelProperty(value = "分类id", example = "1")
    private String catagoryId;

    //图标id
    @ApiModelProperty(value = "图标的唯一编号", example = "1")
    private String iconId;

    //类型编码
    @ApiModelProperty(value = "分类类型编码", example = "A03")
    private String code;

    //类型名称
    @ApiModelProperty(value = "分类名称", example = "家清")
    private String name;

    //用来判断是否有字节点
    @ApiModelProperty(value = "是否有字节点", example = "false")
    private boolean haveChildren;

    //上级id
    @ApiModelProperty(value = "上级id", example = "A01")
    private String parentId;
}
