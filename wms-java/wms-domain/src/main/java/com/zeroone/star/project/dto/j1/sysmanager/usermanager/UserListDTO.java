package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.sql.Date;

/**
 * <p>
 * 描述：用户列表显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 图团
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "用户列表显示数据对象")
public class UserListDTO {
    @ApiModelProperty(value = "创建时间",example = "2025-2-24")
    private DateTime createDate;

    @ApiModelProperty(value = "状态",example = "激活")
    private String status;

    @ApiModelProperty(value = "用户ID",example = "1")
    private String id;
    @ApiModelProperty(value = "组织机构名",example = "厦门境图智能科技有限公司")
    private String departname;
    @ApiModelProperty(value = "角色",example = "客户")
    private String roleName;

    @ApiModelProperty(value = "用户账号", example = "admin",required = true)
    protected String username;

    @ApiModelProperty(value = "用户姓名", example = "张三")
    private String userKey;






}
