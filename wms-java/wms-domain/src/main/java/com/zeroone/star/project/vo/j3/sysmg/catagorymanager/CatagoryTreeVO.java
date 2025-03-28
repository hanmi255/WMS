package com.zeroone.star.project.vo.j3.sysmg.catagorymanager;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("分类")
public class CatagoryTreeVO extends PageQuery {


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
