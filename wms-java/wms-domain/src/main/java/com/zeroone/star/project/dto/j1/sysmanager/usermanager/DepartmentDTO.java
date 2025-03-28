package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：组织机构显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "组织机构显示数据对象")
public class DepartmentDTO {
    @ApiModelProperty(value = "组织机构id",example = "1")
    private String id;
    @ApiModelProperty(value = "组织机构名称",example = "厦门境图智能科技有限公司")
    private String departname;
    @ApiModelProperty(value = "组织机构类型",example = "公司")
    private String orgType;


}
