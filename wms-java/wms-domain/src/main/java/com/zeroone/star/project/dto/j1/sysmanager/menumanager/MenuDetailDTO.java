package com.zeroone.star.project.dto.j1.sysmanager.menumanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

@Getter
@Setter
@ToString
@ApiModel("菜单详细信息")
public class MenuDetailDTO extends MenuManagementBaseDTO {

    @ApiModelProperty(value = "菜单ID", example = "001")
    private String menuId;

    @ApiModelProperty(value = "父菜单ID", example = "000")
    private String parentId;

    @ApiModelProperty(value = "父菜单名称",example = "消息中间件")
    private String parentName;

    @ApiModelProperty(value = "创建时间", example = "2023-01-01 12:00:00")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "更新时间", example = "2023-01-02 12:00:00")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "创建人", example = "admin")
    private String createdBy;

    @ApiModelProperty(value = "更新人", example = "admin")
    private String updatedBy;

    @ApiModelProperty(value = "备注", example = "这是一个示例菜单")
    private String remark;
}
