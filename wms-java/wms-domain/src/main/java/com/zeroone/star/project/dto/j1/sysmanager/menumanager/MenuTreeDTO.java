package com.zeroone.star.project.dto.j1.sysmanager.menumanager;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.ArrayList;
import java.util.List;

@Getter
@Setter
@ToString
@ApiModel("菜单树节点")
/**
 * <p>
 * 描述：继承菜单管理基础数据模型实现菜单树节点
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
public class MenuTreeDTO  {

    @ApiModelProperty(value = "菜单ID", example = "001")
    private String menuId;

    @ApiModelProperty(value = "菜单名称", example = "系统管理")
    private String menuName;

    @ApiModelProperty(value = "父菜单ID", example = "000")
    private String parentId;

    @ApiModelProperty(value = "子菜单列表")
    private List<MenuTreeDTO> children;

    public MenuTreeDTO() {
        this.children=new ArrayList<>();
    }
    public void addChild(MenuTreeDTO child) {
        this.children.add(child);
    }
}
