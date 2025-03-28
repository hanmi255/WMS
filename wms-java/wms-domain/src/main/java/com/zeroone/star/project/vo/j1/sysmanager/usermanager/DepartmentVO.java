package com.zeroone.star.project.vo.j1.sysmanager.usermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 *
 * PingShui
 * 2025/2/23 21:37
 */
@Data
@ApiModel(value = "部门数据的VO模型")
public class DepartmentVO implements Serializable {
    @ApiModelProperty(value = "部门id", example = "随机生成的UUID")
    private String id;
    @ApiModelProperty(value = "部门名称", example = "某某某有限公司")
    private String departname;
}
