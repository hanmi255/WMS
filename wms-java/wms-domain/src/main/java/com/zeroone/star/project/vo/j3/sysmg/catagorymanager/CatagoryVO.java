package com.zeroone.star.project.vo.j3.sysmg.catagorymanager;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("分类名称")
public class CatagoryVO extends TreeNode {

    /**
     * 分类id
     */
    @ApiModelProperty(value = "分类id", example = "1")
    private String categoryId;

    /**
     * 图标id
     */
    @ApiModelProperty(value = "图标id", example = "1")
    private String iconId;

    /**
     * 类型名称
     */
    @ApiModelProperty(value = "分类名称", example = "家清")
    private String name;

    /**
     * 用来判断是否有字节点
     */
    @ApiModelProperty(value = "是否有字节点", example = "false")
    private boolean haveChildren;

    /**
     * 子分类集合
     */
    @ApiModelProperty(value = "分类类型编码")
    private List<CatagoryVO> children;

    /**
     * 父节点id
     */
    private String parentId;

}
