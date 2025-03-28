package com.zeroone.star.project.vo.login;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.List;

/**
 * <p>
 * 描述：树状菜单显示数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
public class FunctionTreeVO extends TreeNode {

    /**
     * 菜单id
     */
    @ApiModelProperty(value = "菜单id", example = "402880e6815a85b301815a8f5cf60003")
    private String id;
    /**
     * 菜单父级id
     */
    @ApiModelProperty(value = "父级菜单编号", example = "402880e6815a85b301815a8e7c160001")
    private String parentfunctionid;
    /**
     * 菜单名称
     */
    @ApiModelProperty(value = "菜单名称", example = "APP功能")
    private String functionname;
    /**
     * 菜单级别
     */
    @ApiModelProperty(value = "菜单级别", example = "1")
    private Byte functionlevel;
    /**
     * 菜单地址
     */
    @ApiModelProperty(value = "菜单地址", example = "wmsAppFunctionController.do?list")
    private String functionurl;
    /**
     * 菜单图标
     */
    @ApiModelProperty(value = "菜单图标名称", example = "默认")
    private String iconName;
    /**
     * 桌面菜单图标
     */
    @ApiModelProperty(value = "菜单图标名称", example = "默认")
    private String deskIconName;

    @ApiModelProperty(value = "节点包含的子节点")
    public List<FunctionTreeVO> getChildren() {
        return childrenElementTrans();
    }
}
