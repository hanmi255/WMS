package com.zeroone.star.project.dto.j1.sysmanager.menumanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：菜单录入数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "获取菜单列表数据模型")
public class MenuEntryDTO extends MenuManagementBaseDTO{
    @ApiModelProperty(value = "是否父节点", example = "1")
    private  int IsParentNode=0;
}
