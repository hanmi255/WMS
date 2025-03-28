package com.zeroone.star.project.dto.j2.sysmgr;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：获取组织列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author TWTW
 * @version 1.0.0
 */

@Getter
@Setter
@ToString
@ApiModel("组织列表项")
public class DepartTreeListDTO  {
    @ApiModelProperty(value = "部门ID", example = "2c9221a470adc6fc0170ecef9dd4029e")
    private String id;
    @ApiModelProperty(value = "父部门ID", example = "2c9221a470adc6fc0170ecef9dd4029e")
    private String parentDepartId;
    @ApiModelProperty(value = "组织名称", example = "广州华壹智能科技有限公司")
    private String departName;
    @ApiModelProperty(value = "部门类型", example = "1（总公司）")
    private Integer orgType;
    @ApiModelProperty(value = "是否有子节点", example = "true")
    private Boolean hasChildren;
    @ApiModelProperty(value = "部门描述", example = "是一个科技公司")
    private String description;
    @ApiModelProperty(value = "部门编码", example = "A001")
    private String orgCode;
    @ApiModelProperty(value = "电话", example = "138xxxxxxxx")
    private String mobile;
    @ApiModelProperty(value = "传真", example = "138xxxxxxxx")
    private String fax;
    @ApiModelProperty(value = "地址", example = "湖南xxxxx")
    private String address;
    @ApiModelProperty(value = "排序", example = "0")
    private String departOrder;

}
