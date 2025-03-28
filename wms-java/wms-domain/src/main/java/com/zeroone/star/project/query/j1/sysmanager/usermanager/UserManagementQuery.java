package com.zeroone.star.project.query.j1.sysmanager.usermanager;

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
@ApiModel(value = "用户管理查询对象")
public class UserManagementQuery extends PageQuery {

    @ApiModelProperty(value = "用户账号", example = "admin")
    private String username;

    @ApiModelProperty(value = "用户姓名", example = "管理员")
    private String realname;

    @ApiModelProperty(value = "选择部门", example = "组织机构")
    private String department;
}
