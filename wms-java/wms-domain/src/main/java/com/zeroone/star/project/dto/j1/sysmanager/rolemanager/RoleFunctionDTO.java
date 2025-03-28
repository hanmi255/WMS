package com.zeroone.star.project.dto.j1.sysmanager.rolemanager;

import com.fasterxml.jackson.annotation.JsonPropertyOrder;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

/**
 * <p>
 * 描述：获取资源名称树数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 匿名的好友
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel(value = "资源名称树数据模型")
@JsonPropertyOrder({ "id", "functionName", "functionUrl", "imagePath", "flag", "parentId", "subItems" })
public class RoleFunctionDTO {

    @ApiModelProperty(value = "权限id", example = "0123")
    private String Id;

    @ApiModelProperty(value = "资源名称", example = "每日检查")
    private String functionName;

    @ApiModelProperty(value = "菜单URL", example = "/check/daily")
    private String functionUrl;

    @ApiModelProperty(value = "菜单图标路径", example = "https://example.com/icons/menu.png")
    private String imagePath;

    @ApiModelProperty(value = "是否拥有权限", example = "0")
    private String flag; //0没有，1有

    @ApiModelProperty(value = "子资源列表")
    private List<RoleFunctionDTO> subItems;
}