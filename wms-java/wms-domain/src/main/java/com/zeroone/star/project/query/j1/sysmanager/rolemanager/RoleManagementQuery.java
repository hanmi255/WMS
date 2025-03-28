package com.zeroone.star.project.query.j1.sysmanager.rolemanager;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：用户管理查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString // 打印对象时，打印出属性值
@Getter // 自动生成getter方法
@Setter // 自动生成setter方法
@ApiModel(value = "角色管理查询对象")
public class RoleManagementQuery extends PageQuery {

    @ApiModelProperty(value = "角色名称", example = "财务")
    private String rolename;



}
