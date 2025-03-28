/**
 * @ClassName : DepartADM  //类名
 * @Description : 增删改实体类  //描述
 * @Author : 全息主角 //作者
 * @Date: 2025/3/1  16:11
 */

package com.zeroone.star.sysmgr.entity;

import com.baomidou.mybatisplus.annotation.*;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@TableName("t_s_depart")
public class DepartADM {
    @ApiModelProperty(value = "组织机构id", example = "2c9221a470adc6fc0170ecef9dd4029e")
    @TableId(type = IdType.ASSIGN_UUID)
    @TableField("ID")
    private String id;
    /**
     * 组织机构名称
     */
    @ApiModelProperty(value = "组织机构名称", example = "上海零壹星辰科技有限公司")
    @TableField("departname")
    private String departName;

    /**
     * 组织机构描述
     */
    @ApiModelProperty(value = "组织机构描述", example = "这是一家做家电售卖的企业")
    @TableField("description")
    private String description;


    /**
     * 组织机构编码
     */
    @ApiModelProperty(value = "组织机构编码", example = "A31")
    @TableField("org_code")
    private String orgCode;

    /**
     * 组织机构类型
     */
    @ApiModelProperty(value = "组织机构类型", example = "1:公司(前端) 2:组织机构")
    @TableField("org_type")
    private String orgType;

    /**
     * 电话
     */
    @ApiModelProperty(value = "电话", example = "123456789")
    @TableField("mobile")
    private String mobile;

    /**
     * 传真
     */
    @ApiModelProperty(value = "传真", example = "26737123")
    @TableField("fax")
    private String fax;

    /**
     * 地址
     */
    @ApiModelProperty(value = "地址", example = "上海市浦东新区")
    @TableField("address")
    private String address;

    /**
     * 上级组织机构
     */
    @ApiModelProperty(value = "上级组织机构", example = "2c9221a470adc6fc0170ecef9dd4029e:厦门境图智能科技有限公司(前端显示)")
    @TableField(value = "parentdepartid", updateStrategy = FieldStrategy.IGNORED)
    private String parentId;
    /**
     * 是否存在成员
     */
    @ApiModelProperty(value = "是否存在成员", example = "null")
    @TableField(value = "depart_order", updateStrategy = FieldStrategy.IGNORED)
    private String departOrder = "0";
}
