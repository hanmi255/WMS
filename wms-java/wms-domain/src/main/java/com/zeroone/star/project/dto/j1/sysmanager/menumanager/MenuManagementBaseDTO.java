package com.zeroone.star.project.dto.j1.sysmanager.menumanager;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：菜单管理基础数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */

@ToString
@Setter
@Getter
@ApiModel("菜单管理基础数据模型")
public class MenuManagementBaseDTO {

    @ApiModelProperty(value = "菜单ID", example = "1")
    private String menuId;

    @ApiModelProperty(value = "菜单名称", example = "每日检查")
    private String menuName;

    @ApiModelProperty(value = "菜单类型")
    private Integer menuType;

    @ApiModelProperty(value = "菜单等级", example = "一级菜单")
    private Integer menuLevels;

    @ApiModelProperty(value = "菜单地址")
    private String menuUrl;

    @ApiModelProperty(value = "图标")
    private String menuIcon;

    @ApiModelProperty(value = "桌面图标", example = "用户管理")
    private String desktopIcons;

    @ApiModelProperty(value = "菜单顺序", example = "006")
    private String menuSort;

    @ApiModelProperty(value = "菜单图标样式")
    private String menuIconStyle;

    @ApiModelProperty(value = "是否含有子菜单", example = "1")
    private String isHasChild;



}
